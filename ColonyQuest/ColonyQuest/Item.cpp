#include "Item.h"
//アイテムの管理をするクラス
//ここでアイテムの管理をする。

void Item::ItemCreate()
{
	sItem Mat[3];
	//アイテム作成関数
	//下記の所でアイテムネームセット。
	char SetItemName[3][40] = {"デバッグアイテム１","デバッグアイテム２","デバッグアイテム３"};
	char SetItemDesc[3][256] = { "デバッグ用１","デバッグ用２","デバッグ用３" };

}


//武器防具のアイテム生成関数
void Item::EquipCreate()
{
	EquipItem eItem[256];//武器装備の構造体管理
	//eItem[1] = {2,1,0 };//構造体エラーで少し調整中
	
}