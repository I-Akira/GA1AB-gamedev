#pragma once
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
//�I�u�W�F�N�g�F�U��
class CObjHeroAttack : public CObj
{
public:
	CObjHeroAttack(float m_x,float m_y);
	~CObjHeroAttack() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_x;//X�����̈ʒu�p�ϐ�
	float m_y;//Y�����̈ʒu�p�ϐ�
};