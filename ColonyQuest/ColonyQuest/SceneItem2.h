#pragma once
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CSceneItem2 : public  CScene ,CObj //CScene //CScene
{
public:
	CSceneItem2() {};
	~CSceneItem2() {};
	void InitScene();
	void Scene();
	void Action();
	void Init();
	void Draw();
private:
	float m_mou_x;//�}�E�X�̈ʒu
	float m_mou_y;//
	bool  m_mou_r; //�{�^���̏��
	bool  m_mou_l; //
};