#pragma once
//使用ヘッダー
#include "GameL\SceneObjManager.h"
//使用ネームスペース
using namespace GameL;

//定数
//マウスクリックのメイン遷移（遷移）
#define MOU_MAIN_HIT_X			(325)
#define MOU_MAIN_HIT_W			(450)
#define MOU_MAIN_HIT_Y			(400)
#define MOU_MAIN_HIT_H			(430)

//描画関係定数
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

//オブジェ：タイトル
class CObjTitle : public CObj
{
public:
	CObjTitle() {};
	~CObjTitle() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_mou_x;	//マウス位置X
	float m_mou_y;	//マウス位置Y
	bool  m_mou_r;	//マウス右ボタン
	bool  m_mou_l;	//マウス左ボタン

};