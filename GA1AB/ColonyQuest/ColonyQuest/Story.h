#pragma once

#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"


using namespace GameL;

class CSceneStory : public   CScene, CObj  //, CScene
{
public:
	CSceneStory() {};
	~CSceneStory() {};
	void InitScene();	//���s
	void Scene();		//������
	void Action();
	void Init();
	void Draw();
private:
	float m_mou_x;//�}�E�X�̈ʒu
	float m_mou_y;//
	bool m_mou_r; //�{�^���̏��
	bool m_mou_l; //
	bool m_key_flag;//�L�[�̏��
};