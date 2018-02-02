//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjEnemy.h"
#include "CObjheroattack.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjEnemy::CObjEnemy(float x, float y)
{
	m_px = x;//�ʒu
	m_py = y;
}
//�C�j�V�����C�Y
void CObjEnemy::Init()
{
	Audio::LoadAudio(12, L"SE Delete.wav", SOUND_TYPE::EFFECT);
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f;	//�E����0.0f�@������1.0f

	m_ani_time = 0;
	m_ani_frame = 4;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 4;	 //�A�j���[�V�����Ԋu��

	m_move = true;		 //true=�Efalse=��

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}
//�A�N�V����
void CObjEnemy::Action()
{
	//����
	if (m_py > 1000.0f)
	{
	 ;
	}
	
	//�ʏ푬�x
	m_speed_power = 0.5f;
	m_ani_max_time = 4;


	//���C
	m_vx += -(m_vx*0.098);

	//���R�����^��*�����Ă�����
//	m_vy += 9.8 / (16.0f);

	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̃_�~�[
	int d;
	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	//�u���b�N���������Ă���
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBox�̈ʒu�̕ύX
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px+block->GetScroll(), m_py);

	if (hit->CheckObjNameHit(OBJ_HEROATTACK) != nullptr)
	{
		Audio::Start(12);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void  CObjEnemy::Draw()
{
	Draw::LoadImage(L"Enemy.png", 1, TEX_SIZE_512);
	int AniData[4] =
	{
		1,0,2,0,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 0.0f;		 //64.0f;
	src.m_left   = 72.0f;		 //0.0f + AniData[m_ani_frame] * 64;
	src.m_right  = 0.0f;		 //64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 60.0f;		 //src.m_top+64.0f;

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//��\���ʒu�̐ݒ�
	dst.m_top   = 0.0f + m_py;
	dst.m_left = (64.0f*m_posture) + m_px + block->GetScroll();
	dst.m_right = (64 - 64.0f*m_posture) + m_px + block->GetScroll();
	dst.m_bottom = 64.0f + m_py;

	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);
}