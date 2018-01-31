#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン：メイン
class CSceneBattle2 :public CScene
{
public:
	CSceneBattle2();
	~CSceneBattle2();
	void InitScene();//初期化メソッド
	void Scene();	 //実行中メソッド
public:
};