#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�o�g��
class CObjBatoru :public CObj
{
public:
	CObjBatoru() {};
	~CObjBatoru() {};
	void Init();	 //�C�j�V�����C�Y
	void Action();	 //�A�N�V����
	void Draw();	 //�h���[

	
private:
	int batorumap[6][10];
};