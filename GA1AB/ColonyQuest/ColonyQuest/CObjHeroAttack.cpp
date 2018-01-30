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
	Hits::SetHitBox(this, m_px, m_py, 5, 64, ELEMENT_PLAYER, OBJ_HEROATTACK, 1);
	
	m_time = 0;	//�^�C���J�E���^�[
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

	//�G�L�����ɐG���ƍU��HitBox���폜
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//'D'�L�[�ɓ��͂��Ȃ��ꍇ�U��HitBox���폜
	if (Input::GetVKey('D') == false)
	{
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

			   //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 90.0f;
	src.m_bottom = 480.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f+m_py;
	dst.m_left = -17.0f+m_px;
	dst.m_right = 17.0f+m_px;
	dst.m_bottom =64.0f+m_py;
	Draw::Draw(9, &src, &dst, c, 0.0f);

}