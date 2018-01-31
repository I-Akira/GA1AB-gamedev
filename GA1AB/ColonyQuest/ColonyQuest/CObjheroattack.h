#pragma once
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;
//オブジェクト：攻撃
class CObjHeroAttack : public CObj
{
public:
	CObjHeroAttack(float m_x,float m_y);
	~CObjHeroAttack() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:

	float m_px;//X方向の位置用変数
	float m_py;//Y方向の位置用変数
	int m_time;//時間
	RECT_F m_eff;
	int	   m_ani;	  //着弾アニメーション用
	int	   m_ani_time;//着弾アニメーション間隔タイム
	bool   m_del;     //削除チェック
};