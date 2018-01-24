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
	//当たり判定hitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 5, 64, ELEMENT_PLAYER, OBJ_HEROATTACK, 1);
	
	m_time = 0;	//タイムカウンター
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

	//敵キャラに触れると攻撃HitBoxを削除※要改良
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	if (hit->CheckObjNameHit(OBJ_JUMPENEMY) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	//'D'キーに入力がない場合攻撃HitBoxを削除
	if (Input::GetVKey('D') == false)
	{
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
void CObjHeroAttack::Draw(){}