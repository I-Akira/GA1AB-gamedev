#pragma once

#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"


using namespace GameL;

class CSceneClear : public   CScene, CObj  //, CScene
{
public:
	CSceneClear() {};
	~CSceneClear() {};
	void InitScene();	//���s
	void Scene();		//������
	void Action();
	void Init();
	void Draw();
private:
	bool m_kb_sw; //�X�C�b�`�̊m�F
};