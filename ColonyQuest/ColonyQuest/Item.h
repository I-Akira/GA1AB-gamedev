#pragma once
#include "Struct.h"
struct sItem
{
	public:
		//�A�C�e����
		char Itemname[40];
		//�A�C�e���̐���
		char Itemdesc[256];
		//���z�i�����p���Ĕ��p�l�i���ݒ�B���p�l�i�͍w�����z�̔����j
		unsigned int Mon;
};



struct EquipItem :public sItem
{

	private:
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
		void EquipCreate();
		void SetItem();
		void GetItem(int t);
		void SetEItem(int a, int d, int s);
	private:
		int ItemNum;
		int ItemSet;
}Itm;