#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト；弾丸
class CObjAtackAction : public CObj
{
public:
	CObjAtackAction(float x, float y);
	~CObjAtackAction() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_x;//攻撃のX方向　位置
	float m_y;//弾丸のY方向　位置
	float m_f;//true or false

	float m_posture;//弾丸の向き

	float m_ani_frame;	 //描画フレーム
	float m_ani_time;	 //アニメ動作間隔
	float m_ani_max_time;//動作間隔最大値

	//当たり判定
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	int m_block_type;
};