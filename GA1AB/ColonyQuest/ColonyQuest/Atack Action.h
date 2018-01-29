#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�G�e��
class CObjAtackAction : public CObj
{
public:
	CObjAtackAction(float x, float y);
	~CObjAtackAction() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_x;//�U����X�����@�ʒu
	float m_y;//�e�ۂ�Y�����@�ʒu
	float m_f;//true or false

	float m_posture;//�e�ۂ̌���

	float m_ani_frame;	 //�`��t���[��
	float m_ani_time;	 //�A�j������Ԋu
	float m_ani_max_time;//����Ԋu�ő�l

	//�����蔻��
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	int m_block_type;
};