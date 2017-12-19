#pragma once
//使用ヘッダー
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーンゲームメイン
class CSceneTitle :public CScene
{
	public:
		CSceneTitle();
		~CSceneTitle();
		void InitScene();
		void Scene();
	private:
};