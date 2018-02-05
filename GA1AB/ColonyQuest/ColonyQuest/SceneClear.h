#pragma once

#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"


using namespace GameL;

class CSceneClear : public   CScene, CObj  //, CScene
{
public:
	CSceneClear() {};
	~CSceneClear() {};
	void InitScene();	//実行
	void Scene();		//初期化
	void Action();
	void Init();
	void Draw();
private:
	bool m_kb_sw; //スイッチの確認
};