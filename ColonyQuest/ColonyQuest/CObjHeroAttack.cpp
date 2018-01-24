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

	//�G�L�����ɐG���ƍU��HitBox���폜���v����
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	if (hit->CheckObjNameHit(OBJ_JUMPENEMY) != nullptr)
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
void CObjHeroAttack::Draw(){}