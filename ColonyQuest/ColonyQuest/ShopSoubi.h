#pragma once

#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"

using namespace GameL;

class CSceneShopBugu : public  CScene ,CObj //cobj
{
public:
	CSceneShopBugu(){};
	~CSceneShopBugu(){};
	void InitScene();	//実行
	void Scene();		//初期化
	void Action();
	void Init();
	void Draw();
private:
	float m_mou_x;//マウスの位置
	float m_mou_y;//
	bool m_mou_r; //ボタンの状態
	bool m_mou_l; //
};