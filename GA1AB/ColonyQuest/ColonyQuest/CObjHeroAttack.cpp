//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"


#include "ObjTime.h"
#include "CObjheroAttack.h"
#include "ObjHero.h"
#include "ObjEnemy.h"
//�l�[���X�y�[�X
using namespace GameL;
//�R���X�g���N�^
CObjHeroAttack::CObjHeroAttack(float x, float y)
{
	m_px = x;
	m_py = y;
}
//�C�j�V�����C�Y
void CObjHeroAttack::Init()
{

	Draw::LoadImage(L"zan.png", 9, TEX_SIZE_512);
	//�����蔻��hitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 10, 64, ELEMENT_PLAYER, OBJ_HEROATTACK, 1);
	
	m_time = 0;	//�^�C���J�E���^�[
	m_eff.m_top = 0;
	m_eff.m_left = 0;
	m_eff.m_right = 100;
	m_eff.m_bottom = 500;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;
}
//�A�N�V����
void CObjHeroAttack::Action()
{
	//��l���̈ʒu���擾&�U�������@�ɍ��킹��
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_px += hero->GetX() - m_px+60; //�U�������@�ɖ�����Ȃ��p
	m_py += hero->GetY() - m_py;	
	
	CHitBox*hit = Hits::GetHitBox(this);	//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	hit->SetPos(m_px, m_py);				//HitBox�̈ʒu���U���̈ʒu�X�V

	if (m_del == true) {
		RECT_F ani_src[4] =
		{
			{0,0,100,500},
			{0,103,203,500},
			//{0,204,304,500},
			{0,305,405,500},
			{0,406,506,500},
		};

		//�A�j���[�V�����̃R�}�Ԋu����
		if (m_ani_time > 2)
		{
			m_ani++;
			m_ani_time = 0;

			m_eff = ani_src[m_ani];
		}
		else
		{
			m_ani_time++;
		}

		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		return;
	}

	//�G�L�����ɐG���ƍU��HitBox���폜
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	if (Input::GetVKey('C') == true)
	{
		m_del =true;
	}
	//'D'�L�[�ɓ��͂��Ȃ��ꍇ�U��HitBox���폜
	if (Input::GetVKey('C') == false)
	{
		m_del = false;
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//���ԂɂȂ�ƍU��HitBox�������폜
	if (m_time >= 50)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		m_time = 0;
	}
	m_time++;
}
//�h���[	
void CObjHeroAttack::Draw()
{	
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f+m_py;
	dst.m_left =-17.0f+m_px;
	dst.m_right = 5.0f+m_px;
	dst.m_bottom =64.0f+m_py;

	if (m_del == true)
	{
		Draw::Draw(9, &m_eff, &dst, c, 0.0f);
	}
	else 
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 100.0f;
		src.m_bottom = 500.0f;
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
}