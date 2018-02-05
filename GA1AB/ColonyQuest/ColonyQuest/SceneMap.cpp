//STLデバッグ機能をＯＦＦに
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "SceneMap.h"

#include "GameHead.h"

#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\Audio.h"

using namespace GameL;
int num = 0;

void CSceneMap::InitScene()
{
	CSceneMap* map = new CSceneMap();
	Objs::InsertObj(map, OBJ_SCENE_MAP, 1);

	//グラフィック読み込み
	Draw::LoadImage(L"tekisuto1.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"tekisuto2.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"haikei4.png"  , 3, TEX_SIZE_512);
	//音楽・SE読み込み
	Audio::LoadAudio(0, L"BGM Menu.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"SE SELECT.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);
}
//----------------------------------------------------------------------------------------------------------------------------------------
void CSceneMap::Scene()//初期化-------------------------------------------------------------------------------------------------------------
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------
//イニシャライズ---------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
void CSceneMap::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_key_flag = false;//Zキーの状態
}
//----------------------------------------------------------------------------------------------------------------------------------------------
//アクション-----------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
void CSceneMap::Action()
{
	//マウスの座標
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


	if (Input::GetVKey('Z') == true)
	{
		Audio::Start(1);
		Scene::SetScene(new CSceneBattle());
	}
	//ステージ２に移動
	if (Input::GetVKey('X') == true)
	{
		Audio::Start(1);
		Scene::SetScene(new CSceneBattle2());
	}
	//ステージ3に移動
	if (Input::GetVKey('C') == true)
	{
		Audio::Start(1);
		Scene::SetScene(new CSceneBattle3());
	}
	

	//デバッグ・ゲームクリア確認用
	if (Input::GetVKey('V') == true)
	{
		Scene::SetScene(new CSceneClear);//ここをクリア画面にする
	}


}
//------------------------------------------------------------------------------------------------------------------------------------------
//ドロー--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
void CSceneMap::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst ,dst2,dst3;

//背景---------------------------------------------------------
	//切り取り位置
	src.m_top 	 =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 500.0f;
	src.m_bottom = 500.0f;
	//表示位置
	dst.m_top    =   0.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 1030.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(3, &src, &dst, c, 0.0f);

//テキスト----------------------------------------------------
	//表示位置
	dst2.m_top    =   0.0f;
	dst2.m_left   =   0.0f;
	dst2.m_right  = 380.0f;
	dst2.m_bottom = 120.0f;
	Draw::Draw(1, &src, &dst2, c, 0.0f);//MAP

	dst3.m_top    = 240.0f;
	dst3.m_left   = 280.0f;
	dst3.m_right  = 770.0f;
	dst3.m_bottom = 350.0f;
	Draw::Draw(1, &src, &dst3, c, 0.0f);//ステージ1へ
	dst3.m_top    = 370.0f;
	dst3.m_left   = 280.0f;
	dst3.m_right  = 770.0f;
	dst3.m_bottom = 480.0f;
	Draw::Draw(1, &src, &dst3, c, 0.0f);//ステージ
	dst3.m_top    = 500.0f;
	dst3.m_left   = 280.0f;
	dst3.m_right  = 770.0f;
	dst3.m_bottom = 610.0f;
	Draw::Draw(1, &src, &dst3, c, 0.0f);//道具やへ
    //文字表示---------------------------------------
	Font::StrDraw(L" ★メイン★", 80, 45, 35, c);	
	Font::StrDraw(L"Z :ステージ１", 365, 280, 55, c);
	Font::StrDraw(L"X :ステージ２", 365, 410, 55, c);
	Font::StrDraw(L"C :ステージ３", 365, 540, 55, c);
	Font::StrDraw(L"キーをを入力して選択", 50, 620, 45, c);
	Font::StrDraw(L"（Z　X　C）"                , 200, 680, 45, c);
	//仮マウスの位置表示----------------------------------------
	wchar_t str[256];
	swprintf_s(str, L"x = %f, y = %f", m_mou_x, m_mou_y);
//	Font::StrDraw(str, 500, 20, 20, c);
}







/*----------------------------------------------------------------------------------------------------------------------------
マウス状態テスト
if (m_mou_l == true)
{
swprintf_s(str, L"L = true");
Font::StrDraw(str, 510, 50, 40, c);
}
else
{
swprintf_s(str, L"L = 押してない");
Font::StrDraw(str, 510, 50, 40, c);
}
if (m_mou_r == true)
{
swprintf_s(str, L"R = true");
Font::StrDraw(str, 510, 100, 40, c);
}
else
{
swprintf_s(str, L"R = 押してない");
Font::StrDraw(str, 510, 100, 40, c);
}
---------------------------------------------------------------------------------------------

//ステージ１に移動
if (Input::GetVKey('Z') == true)
{
if (m_key_flag == true)
{
num += 1;
m_key_flag = false;
if (num > 3)
{
num = 1;
}
}
else
{
m_key_flag = true;
}
}
//ステージ１に移動
if (num == 1)
{
if (Input::GetVKey(VK_RETURN) == true)
{
Audio::Start(1);
num = 0;
Scene::SetScene(new CSceneBattle());
}
}
//ステージ２に移動
if (num == 2)
{
if (Input::GetVKey(VK_RETURN) == true)
{
Audio::Start(1);
num = 0;
Scene::SetScene(new CSceneBattle2());
}
}
//ステージ3に移動
if (num == 3)
{
if (Input::GetVKey(VK_RETURN) == true)
{
Audio::Start(1);
num = 0;
Scene::SetScene(new CSceneBattle3());
}
}
*/