#pragma once
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

using namespace GameL;

class CSceneItem : public CScene , CObj //CScene //CScene
{
public:
	CSceneItem() {};
	~CSceneItem() {};
	void InitScene();
	void Scene();
	void Action();
	void Init();
	void Draw();
	void Draw2();
private:
	float m_mou_x;//�}�E�X�̈ʒu
	float m_mou_y;//
	bool  m_mou_r; //�{�^���̏��
	bool  m_mou_l; //
};