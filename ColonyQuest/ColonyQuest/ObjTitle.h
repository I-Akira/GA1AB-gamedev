#pragma once
//使用ヘッダー
#include "GameL\SceneObjManager.h"
//使用ネームスペース
using namespace GameL;

//定数
//マウスクリックのメイン遷移（遷移）
#define MOU_MAIN_HIT_X			(450)
#define MOU_MAIN_HIT_W			(575)
#define MOU_MAIN_HIT_Y			(500)
#define MOU_MAIN_HIT_H			(530)

//描画関係定数
#define TITLE_POS_X				(325)
#define TITLE_POS_Y				(200)
#define TITLE_FONT_SIZE			(40)

#define CLICK_START_POS_X		(425)
#define CLICK_START_POS_Y		(500)
#define CLICK_START_FONT_SIZE	(30)



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
	bool m_deb_mn;
};