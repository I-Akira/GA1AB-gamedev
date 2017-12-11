#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ブロック＆背景
class CBatoru :public CObj
{
public:
	CBatoru() {};
	~CBatoru() {};
	void Init();	 //イニシャライズ
	void Action();	 //アクション
	void Draw();	 //ドロー
private:
	
};