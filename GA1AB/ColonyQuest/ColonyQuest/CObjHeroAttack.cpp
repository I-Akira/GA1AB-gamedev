//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"


#include "ObjTime.h"
#include "CObjheroAttack.h"
#include "ObjHero.h"
#include "ObjEnemy.h"
//ネームスペース
using namespace GameL;
//コンストラクタ
CObjHeroAttack::CObjHeroAttack(float x, float y)
{
	m_px = x;
	m_py = y;
}
//イニシャライズ
void CObjHeroAttack::Init()
{

	Draw::LoadImage(L"zan.png", 9, TEX_SIZE_512);
	//当たり判定hitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 10, 64, ELEMENT_PLAYER, OBJ_HEROATTACK, 1);
	
	m_time = 0;	//タイムカウンター
	m_eff.m_top = 0;
	m_eff.m_left = 0;
	m_eff.m_right = 100;
	m_eff.m_bottom = 500;
	m_ani = 0;
	m_ani_time = 0;
	m_del = false;
}
//アクション
void CObjHeroAttack::Action()
{
	//主人公の位置を取得&攻撃を自機に合わせる
	CObjHero*hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_px += hero->GetX() - m_px+60; //攻撃が自機に埋もれない用
	m_py += hero->GetY() - m_py;	
	
	CHitBox*hit = Hits::GetHitBox(this);	//弾丸のHitBox更新用ポインター取得
	hit->SetPos(m_px, m_py);				//HitBoxの位置を攻撃の位置更新

	if (m_del == true) {
		RECT_F ani_src[4] =
		{
			{0,0,100,500},
			{0,103,203,500},
			//{0,204,304,500},
			{0,305,405,500},
			{0,406,506,500},
		};

		//アニメーションのコマ間隔制御
		if (m_ani_time > 2)
		{
			m_ani++;
			m_ani_time = 0;

			m_eff = ani_src[m_ani];
		}
		else
		{
			m_ani_time++;
		}

		if (m_ani == 4)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
		return;
	}

	//敵キャラに触れると攻撃HitBoxを削除
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	if (Input::GetVKey('C') == true)
	{
		m_del =true;
	}
	//'D'キーに入力がない場合攻撃HitBoxを削除
	if (Input::GetVKey('C') == false)
	{
		m_del = false;
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//時間になると攻撃HitBoxを自動削除
	if (m_time >= 50)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		m_time = 0;
	}
	m_time++;
}
//ドロー	
void CObjHeroAttack::Draw()
{	
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//表示位置の設定
	dst.m_top = 0.0f+m_py;
	dst.m_left =-17.0f+m_px;
	dst.m_right = 5.0f+m_px;
	dst.m_bottom =64.0f+m_py;

	if (m_del == true)
	{
		Draw::Draw(9, &m_eff, &dst, c, 0.0f);
	}
	else 
	{
		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 100.0f;
		src.m_bottom = 500.0f;
		Draw::Draw(9, &src, &dst, c, 0.0f);
	}
}