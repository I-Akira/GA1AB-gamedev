//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"

#include "CObjheroAttack.h"
#include "ObjHero.h"
#include "ObjEnemy.h"
//ネームスペース
using namespace GameL;
//コンストラクタ
CObjHeroAttack::CObjHeroAttack(float x, float y)
{
	m_x = x;
	m_y = y;
}
//イニシャライズ
void CObjHeroAttack::Init()
{
	//当たり判定hitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, -32, 64, ELEMENT_PLAYER, OBJ_HEROATTACK, 1);

}
//アクション
void CObjHeroAttack::Action()
{
	//弾丸のHitBox更新用ポインター取得
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);				//HitBoxの位置を攻撃の位置更新

	if (hit->CheckObjNameHit(ELEMENT_ENEMY) != nullptr)
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
	
}
//ドロー	
void CObjHeroAttack::Draw(){}

