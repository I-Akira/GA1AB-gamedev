//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"

#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\hitBoxManager.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "CObjheroattack.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 40.0f;		//�ʒu
	m_py = 128.0f;
	m_vx = 0.0f;		//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture=1.0f;		//�E����0.0f������1.0f

	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 4;	 //�A�j���[�V�����Ԋu��

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	m_f = true;//�U������

	m_block_type = 0;	//����ł���block�̎�ނ��m�F�p

	//�����蔻��p��HitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 40, 60, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	//�����ɂ��Q�[���I�[�o�[�ƃ��X�^�[�g
	if (m_py > 1000.0f)
	{
		//��O�ɏo���烊�X�^�[�g
		Scene::SetScene(new CSceneBattle);
	}



	if (Input::GetVKey('E') == true)
	{
		Scene::SetScene(new CSceneMap);//�}�b�v�ɖ߂�
	}
	//S�L�[���͂ŃW�����v
	if (Input::GetVKey('S') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = -12;
		}
	}
	//A�L�[���͂ő��x�A�b�v
	if (Input::GetVKey('A') == true)
	{
				//�_�b�V�����̑��x
				m_speed_power = 2.0f;
				m_ani_max_time = 2;

	}
	else
	{
		//�ʏ푬�x
		m_speed_power = 0.5f;
		m_ani_max_time = 4;
	}
// �E�i�s
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	
	
	

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}
	//���C
	m_vx += -(m_vx*0.098);

	//���R�����^��
	m_vy += 9.0/(18.0f);

	//��l���̍U��
	if (Input::GetVKey('D') == true)
	{
		if(m_f==true)
		{
			//�U���I�u�W�F�N�g�쐬
			CObjHeroAttack*obj_b = new CObjHeroAttack(m_px+62.0f, m_py);//�U���I�u�W�F�N�g�쐬
			Objs::InsertObj(obj_b, OBJ_HEROATTACK, 100);//������U���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
			m_f = false;
		}
	}
	else
	{
		m_f = true;
	}

	//�����ړ��ɂ��Block����
	bool b;
	float pxx, pyy, r;
	CObjBlock*pbb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (pbb->GetScroll() > 0)
		pbb->SetScroll(0);

	//�ړ������Ƀ��C���΂�
	float vx;
	if (m_vx > 0)
		vx = 500;
	else
		vx = -500;

	//���C����
	b = pbb->HeroBlockCrossPint(m_px - pbb->GetScroll() + 32, m_py + 32, m_vx * 100, m_vy * 100, &pxx, &pyy, &r);

	if (b == true)
	{
		//��_�擾
		px = pxx + pbb->GetScroll();
		py = pyy;

		float aa = (m_px)		 - px;//A(��_����l���̈ʒu)�x�N�g��
		float bb = (m_px + m_vx) - px;//B(��_����l���̈ړ���ʒu)�x�N�g��

		//��l���̕����̃I�t�Z�b�g
		if (vx > 0)
			px += -64;
		else
			px += +2;

		//A��B���t�������Ă���(��l�����ړ��悪�ǂ��z���Ă���)
		if (aa*bb < 0)
		{
			//�ړ��x�N�g����(��_����l���̈ʒu)�x�N�g���ɂ���
			m_vx = px - m_px;
		}

	}
	else
	{
		px = 0.0f;
		py = 0.0f;
	}														
	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&m_block_type
	);

	//���g��HitBox�������Ă���
	CHitBox*hit = Hits::GetHitBox(this);
	//�G�Ɠ������Ă��邩�m�F
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		//��l�����G�Ƃǂ̊p�x�œ������Ă��邩���m�F
		HIT_DATA** hit_data;
		hit_data = hit->SearchObjNameHit(OBJ_ENEMY);
		for (int i = 0; i < hit->GetCount(); i++) {
			//�G�̍��E�ɓ���������
			float r = hit_data[i]->r;
			if ((r < 45 && r >= 0) || r > 315)
			{//�E
				//�o�g���V�[���ڍs
				Scene::SetScene(new CSceneBattle);
			
			}
			if (r >= 225 && r < 315)
			{
				//�G�̈ړ���������l���̈ʒu�ɉ��Z
				m_px += ((CObjEnemy*)hit_data[i]->o)->GetVx();
				//�u���b�N���������Ă���
				CObjBlock*b = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
				//����X�N���[�����C��
				if (m_px < 80)
				{
					m_px = 80;					//��l���̓��C���𒴂��Ȃ��悤�ɂ���
					b->SetScroll(b->GetScroll() + 5.0);		//��l�����{�������ׂ����̒l��m_scroll�ɉ�����
				}

				//�O���X�N���[�����C��
				if (m_px > 300)
				{
					m_px = 300;
					b->SetScroll(b->GetScroll() - 5.0);
				}
				//���ɏ悹�鏈��
				if (m_vy < -1.0f)
				{
					//�W�����v���Ă�ꍇ�͉��L�̉e�����o�Ȃ��悤�ɂ���
				}
				else
				{
					//��l�����G�̓��ɏ���Ă�̂ŁAYvec��0�ɂ��ė��������Ȃ�
					//�܂��A�n�ʂɓ������Ă锻��ɂ���
					m_vy = 0.0f;
					m_hit_down = true;
					//���X�^�[�g
					Scene::SetScene(new CSceneBattle);
				}
			}
		}
	}
	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;
	
	

	//HitBox�̈ʒu�̕ύX
	hit->SetPos(m_px, m_py);
}

//�h���[
void CObjHero::Draw()
{/*
	//���g��HitBox�������Ă���
	CHitBox*hit = Hits::GetHitBox(this);
	*/
	int AniData[4] =
	{
		1,0,2,0,
	};
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	/*
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		Font::StrDraw(L"�G�Ɍ��j����܂����I", 230, 250, 32, c);
	}*/

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top	 = 7.0f;
	src.m_left   = 0.0f + AniData[m_ani_frame]*64;
	src.m_right  =50.0f + AniData[m_ani_frame]*64;
	src.m_bottom =62.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top	 = 0.0f+m_py;
	dst.m_left	 = (	    42.0f * m_posture) + m_px;
	dst.m_right  = ( 64  -  64.0f * m_posture) + m_px;
	dst.m_bottom =64.0f+m_py;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);

	//���_
	float cc[4] = { 1.0f,0.0f,0.0f,1.0f };
	src.m_top   = 0.0f;
	src.m_left  = 320.0f;
	src.m_right = 320.0f+64.0f;
	src.m_bottom= 64.0f;
	dst.m_top   = py;
	dst.m_left  = px;
	dst.m_right = dst.m_left+ 10.0f;
	dst.m_bottom= dst.m_top + 10.0f;
	Draw::Draw(0, &src, &dst, cc, 0.0f);
}