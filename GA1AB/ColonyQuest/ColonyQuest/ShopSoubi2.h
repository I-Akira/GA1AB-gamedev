#pragma once

#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"

using namespace GameL;

class CSceneShopBugu2 :public CScene , CObj ,Objs  //cscene
{
public:
	CSceneShopBugu2();
	~CSceneShopBugu2();
	void InitScene();	//実行
	void Scene();		//初期化
	void Action();
	void Init();
	void Draw();
private:
	float m_mou_x;//マウスの位置X
	float m_mou_y;//			
	float m_mou_r;//マウスのクリック状態
	float m_mou_l;//
};