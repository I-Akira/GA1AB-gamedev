#pragma once

#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"


using namespace GameL;

class CSceneStory : public   CScene, CObj  //, CScene
{
public:
	CSceneStory() {};
	~CSceneStory() {};
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
	bool m_key_flag;//キーの状態
};