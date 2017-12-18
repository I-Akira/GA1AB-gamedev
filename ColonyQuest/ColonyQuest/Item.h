#pragma once
#include "Struct.h"

#define ITEM_NAME_MAX (40)
#define ITEM_DESC_MAX (80)


struct sItem
{
	public:
		void SetItemName(int i,char Inam[ITEM_NAME_MAX]) 
		{ Itemname[i] = Inam[i]; }
		void SetItemDesc(int i, char Ides[ITEM_DESC_MAX]) 
		{ Itemdesc[i] = Ides[i]; }
		void SetItemMon(char IMon) { Mon = IMon; }
		
	protected:
		//アイテム名
		char Itemname[40];
		//アイテムの説明
		char Itemdesc[80];
		//金額（これを用いて売却値段も設定。売却値段は購入金額の半分）
		unsigned int Mon;

};



struct EquipItem :public sItem
{

	private:
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
		void EquipCreate();
		void SetItem();
		void GetItem(int t);
		void SetEItem(int a, int d, int s);
	private:
		int ItemNum;
		int ItemSet;
}Itm;