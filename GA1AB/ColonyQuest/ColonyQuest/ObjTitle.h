#pragma once
//�g�p�w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p�l�[���X�y�[�X
using namespace GameL;

//�萔
//�}�E�X�N���b�N�̃��C���J�ځi�J�ځj
#define MOU_MAIN_HIT_X			(450)
#define MOU_MAIN_HIT_W			(575)
#define MOU_MAIN_HIT_Y			(500)
#define MOU_MAIN_HIT_H			(530)

//�`��֌W�萔
#define TITLE_POS_X				(325)
#define TITLE_POS_Y				(200)
#define TITLE_FONT_SIZE			(40)

#define CLICK_START_POS_X		(425)
#define CLICK_START_POS_Y		(500)
#define CLICK_START_FONT_SIZE	(30)



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
	bool m_deb_mn;
};