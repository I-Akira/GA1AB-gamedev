//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjJunpEnemy.h"
#include "CObjheroattack.h"

//使用するネームスペース
using namespace GameL;

CObjJumpEnemy::CObjJumpEnemy(float x, float y)
{
	m_px = x;//位置
	m_py = y;
}
//イニシャライズ
void CObjJumpEnemy::Init()
{
	Audio::LoadAudio(12, L"SE Delete.wav", SOUND_TYPE::EFFECT);

	m_vx = 0.0f;		//移動ベクトル
	m_vy = 0.0f;
	m_posture = 1.0f;	//右向き0.0f　左向き1.0f

	m_ani_time = 0;
	m_ani_frame = 4;	//静止フレームを初期にする

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;	 //アニメーション間隔幅

	m_move = true;		 //true=右false=左

						 //blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//当たり判定用のHitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 64, 64, ELEMENT_ENEMY, OBJ_JUMPENEMY, 1);
}
//アクション
void CObjJumpEnemy::Action()
{
	//Cキー入力でジャンプ
	if (Input::GetVKey('X') == true)
	{
		if (m_hit_down == true)
		{
			m_vy = -12;
		}
	}

	//画面外に出たら破棄
	if (m_px < -10.0f)//試し用
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}


	//落下
	if (m_py > 1000.0f)
	{
		;
	}

	//通常速度
	m_speed_power = 0.5f;
	m_ani_max_time = 4;


	//摩擦
	m_vx += -(m_vx*0.098);

	//自由落下運動*無くてもいい
	m_vy += 9.8 / (16.0f);

	//ブロックタイプ検知用の変数がないためのダミー
	int d;
	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(&m_px, &m_py, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, &m_vx, &m_vy,
		&d
	);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;

	//ブロック情報を持ってくる
	CObjBlock*block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//HitBoxの位置の変更
	CHitBox*hit = Hits::GetHitBox(this);
	hit->SetPos(m_px + block->GetScroll(), m_py);

	if (hit->CheckObjNameHit(OBJ_HEROATTACK) != nullptr)
	{
		Audio::Start(12);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//ドロー
void  CObjJumpEnemy::Draw()
{
	Draw::LoadImage(L"Enemy.png", 1, TEX_SIZE_512);
	int AniData[4] =
	{
		1,0,2,0,
	};

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

				//切り取り位置の設定
	src.m_top = 64.0f;		 //64.0f;
	src.m_left = 72.0f;		 //0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 0.0f;		 //64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 128.0f;		 //src.m_top+64.0f;

								 //ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	//先表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64.0f*m_posture) + m_px + block->GetScroll();
	dst.m_right = (64 - 64.0f*m_posture) + m_px + block->GetScroll();
	dst.m_bottom = 64.0f + m_py;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);
}