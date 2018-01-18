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
	m_x = x;
	m_y = y;
}
//�C�j�V�����C�Y
void CObjHeroAttack::Init()
{
	//�����蔻��hitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, -32, 64, ELEMENT_PLAYER, OBJ_HEROATTACK, 1);

}
//�A�N�V����
void CObjHeroAttack::Action()
{
	//�e�ۂ�HitBox�X�V�p�|�C���^�[�擾
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);				//HitBox�̈ʒu���U���̈ʒu�X�V

	if (hit->CheckObjNameHit(ELEMENT_ENEMY) != nullptr)
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
	
}
//�h���[	
void CObjHeroAttack::Draw(){}

