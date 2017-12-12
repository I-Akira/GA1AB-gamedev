#pragma once
#include "Struct.h"

struct EquipItem :public sItem
{
	//攻撃力
	int Atk;
	//防御力
	int Def;
	//スキル力
	int spp;
};

//アイテム用のヘッダー・変数
//ここでアイテムの一元管理を行う

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