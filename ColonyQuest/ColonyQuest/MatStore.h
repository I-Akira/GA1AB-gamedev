#pragma once

//構造体-----------
//素材マテリアル
//アイテムの名前と説明文、購入金額を管理
struct Material
{
	//アイテム名
	char Itemname[256];
	//アイテムの説明
	char Desc[256];
	//購入金額（これを用いて売却値段も設定。売却値段は購入金額の半分）
	unsigned int Money;
};



class MyClass
{
public:
	MyClass();
	~MyClass();

private:

};


