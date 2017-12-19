#pragma once
//�g�p�w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p�l�[���X�y�[�X
using namespace GameL;

//�萔
//�}�E�X�N���b�N�̃��C���J�ځi�J�ځj
#define MOU_MAIN_HIT_X			(325)
#define MOU_MAIN_HIT_W			(450)
#define MOU_MAIN_HIT_Y			(400)
#define MOU_MAIN_HIT_H			(430)

//�`��֌W�萔
#define TITLE_POS_X				(200)
#define TITLE_POS_Y				(100)
#define TITLE_FONT_SIZE			(40)

#define RANKING_POS_X			(600)
#define RANKING_POS_Y			(0)
#define RANKING_FONT_SIZE		(24)
#define RANKING_SCORE_MAX		(15)
#define STR_MAX					(256)
#define SCORE_INIT				(1)
#define SCORE_POS_X				(670)
#define SCORE_POS_Y				(24)
#define SCORE_POINT_MAX			(100)
#define SCORE_INTERVAL			(24)
#define SCORE_FONT_SIZE			(12)

#define CLICK_START_POS_X		(300)
#define CLICK_START_POS_Y		(400)
#define CLICK_START_FONT_SIZE	(30)

#define CLICK_RESET_POS_X		(680)
#define CLICK_RESET_POS_Y		(400)
#define CLICK_RESET_FONT_SIZE	(16)

#define SCORE_RESET_DEFAULT		(15)

//�I�u�W�F�F�^�C�g��
class CObjTitle : public CObj
{
public:
	CObjTitle() {};
	~CObjTitle() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_mou_x;	//�}�E�X�ʒuX
	float m_mou_y;	//�}�E�X�ʒuY
	bool  m_mou_r;	//�}�E�X�E�{�^��
	bool  m_mou_l;	//�}�E�X���{�^��

};