#pragma once
#include "Struct.h"

struct EquipItem :public sItem
{
	//�U����
	int Atk;
	//�h���
	int Def;
	//�X�L����
	int spp;
};

//�A�C�e���p�̃w�b�_�[�E�ϐ�
//�����ŃA�C�e���̈ꌳ�Ǘ����s��

typedef class Item
{
	public:
		void ItemCreate();
		void ItemSet();
		void EquipCreate();
		void GetItem(int t);
	private:
		int ItemNum;
		int ItemSet;
}Itm;