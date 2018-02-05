
//TLデバッグ機能をＯＦＦに
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "Story.h"

#include "GameHead.h"

#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\Audio.h"

using namespace GameL;

void CSceneStory::InitScene()
{
	CSceneStory* map = new CSceneStory();
	Objs::InsertObj(map, CSCENESTORY, 1);

	//グラフィック読み込み
	Draw::LoadImage(L"tekisuto1.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"tekisuto2.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"haikei4.png", 3, TEX_SIZE_512);
	//音楽・SE読み込み
	Audio::LoadAudio(0, L"BGM Menu.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"SE SELECT.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);
}
//----------------------------------------------------------------------------------------------------------------------------------------
void CSceneStory::Scene()//初期化-------------------------------------------------------------------------------------------------------------
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------
//イニシャライズ---------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
void CSceneStory::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}
//----------------------------------------------------------------------------------------------------------------------------------------------
//アクション-----------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
void CSceneStory::Action()
{
	//マウスの座標
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//マップへ
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			if (Input::GetVKey(VK_RETURN) == true)
			{
				Scene::SetScene(new CSceneMap());
				m_key_flag = false;
			}
		}
		else
		{
			m_key_flag = true;
		}
	}




}
//------------------------------------------------------------------------------------------------------------------------------------------
//ドロー--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
void CSceneStory::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst, dst2, dst3;

	//背景---------------------------------------------------------
	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 500.0f;
	src.m_bottom = 500.0f;
	//表示位置
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1030.0f;
	dst.m_bottom = 600.0f;
//	Draw::Draw(3, &src, &dst, c, 0.0f);

	//テキスト----------------------------------------------------
	//表示位置
	dst3.m_top = 630.0f;
	dst3.m_left = 470.0f;
	dst3.m_right = 960.0f;
	dst3.m_bottom = 710.0f;
	Draw::Draw(1, &src, &dst3, c, 0.0f);//道具やへ
										//文字表示---------------------------------------
	Font::StrDraw(L"とある村に一人の少女とその母親がいました。", 150, 80, 35, c);
	Font::StrDraw(L"ある時、母親が突然倒れてしまい、少女は大慌て。", 120, 120, 35, c);
	Font::StrDraw(L"村には薬も、薬の材料も無く、ホトホト困っていました。", 75, 160, 35, c);
	Font::StrDraw(L"そこで、少女は意を決し、", 325, 200, 35, c);
	Font::StrDraw(L"恐ろしいモンスターがいる場所に生えている薬草を手にしようと", 0, 240, 35, c);
	Font::StrDraw(L"おじさんから護身代わりに貰った", 260, 280, 35, c);
	Font::StrDraw(L"一振りのナイフとともに走り出しました。",190, 320, 35, c);
	Font::StrDraw(L"すべては、大好きなお母さんのために・・・", 160, 360, 35, c);

	Font::StrDraw(L"薬草を取りに行く！", 530, 650, 45, c);
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
*/