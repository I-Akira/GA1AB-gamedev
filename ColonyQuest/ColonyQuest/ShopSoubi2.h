#pragma once

#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"

using namespace GameL;

class CSceneShopBugu2 :public CScene , CObj ,Objs  //cscene
{
public:
	CSceneShopBugu2();
	~CSceneShopBugu2();
	void InitScene();	//���s
	void Scene();		//������
	void Action();
	void Init();
	void Draw();
private:
	float m_mou_x;//�}�E�X�̈ʒuX
	float m_mou_y;//			
	float m_mou_r;//�}�E�X�̃N���b�N���
	float m_mou_l;//
};