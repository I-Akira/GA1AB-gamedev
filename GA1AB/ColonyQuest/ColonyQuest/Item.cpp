#include "Item.h"
#define ITEM_SET_MAX (20)

//アイテムの管理をするクラス
//ここでアイテムの管理をする。

void Item::ItemCreate()
{
	sItem Mat[ITEM_SET_MAX];
	//アイテム作成関数
	//アイテムネームセット変数(アイテムを入れる場合上のITEM_SET_MAXを変更するのを忘れない)
	char* SetItemName[ITEM_SET_MAX][ITEM_NAME_MAX] = 
	{"デバッグアイテム１","デバッグアイテム２","デバッグアイテム３"};
	//アイテム説明セット変数
	char* SetItemDesc[ITEM_SET_MAX][ITEM_DESC_MAX] = 
	{ "デバッグ用１","デバッグ用２","デバッグ用３" };
	//アイテム価格セット変数
	int SetMon[ITEM_SET_MAX] = { 114,514,1919 };

	/*for (int i = 0; i < ITEM_SET_MAX; i++)
	{
		//アイテムネームセット
		for (int j = 0; j < ITEM_NAME_MAX; j++)
		{
			if (SetItemName[i][j] != '\0')//文字が空白でない限りいれる。空白だった場合無視
				Mat[i].SetItemName[j](i,SetItemName[i][j]);
		}
		//アイテム説明セット
		for (int j = 0; j < ITEM_DESC_MAX; j++)
		{
			//文字が空白でない限りいれる。空白だった場合無視
			if(SetItemDesc[i][j]!='\0')
				Mat[i].SetItemDesc(i,SetItemDesc[i][j]);
		}

		//アイテム価格セット
		Mat[i].SetItemMon( SetMon[i]);
	}*///エラー吐いてるのでいったん放置。ベータ版で実装させよう




}


//武器防具のアイテム生成関数
void Item::EquipCreate()
{
	EquipItem eItem[256];//武器装備の構造体管理
	//eItem[1] = {2,1,0 };//構造体エラーで少し調整中
	
}