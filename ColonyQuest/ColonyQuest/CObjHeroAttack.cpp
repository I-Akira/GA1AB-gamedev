//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"

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

}
//�A�N�V����
void CObjHeroAttack::Action()
{
	//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);				//HitBox�̈ʒu���U���̈ʒu�X�V

	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
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
	if (m_atk_time == 50)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		m_atk_time = 0;
	}
	else
	{
		m_atk_time+=0.1f;
	}
}
//�h���[	
void CObjHeroAttack::Draw(){}

