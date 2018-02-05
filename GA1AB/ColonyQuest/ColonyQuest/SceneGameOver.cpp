//STLデバッグ機能をＯＦＦに
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "SceneGameOver.h"

#include "GameHead.h"

#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\Audio.h"

using namespace GameL;

void CSceneGameOver::InitScene()
{
	CSceneGameOver* map = new CSceneGameOver();
	Objs::InsertObj(map, OBJ_SCENEGAMEOVER, 1);

	//グラフィック読み込み
	Draw::LoadImage(L"Htext.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"tekisuto2.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"BGameOver.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"haikei2.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"GameOver.png", 5, TEX_SIZE_512);
	//音楽・SE読み込み
	Audio::LoadAudio(0, L"SE GameOver.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(1, L"SE SELECT.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);
}
//----------------------------------------------------------------------------------------------------------------------------------------
void CSceneGameOver::Scene()//初期化-------------------------------------------------------------------------------------------------------------
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------
//イニシャライズ---------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
void CSceneGameOver::Init()
{

}
//----------------------------------------------------------------------------------------------------------------------------------------------
//アクション-----------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
void CSceneGameOver::Action()
{
	//選択画面に移動
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_kb_sw == true)
		{
			Audio::Start(1);
			Scene::SetScene(new CSceneMap());
			m_kb_sw = false;
		}
		else
		{
			m_kb_sw = true;
		}
	}
	//タイトルに移動
	if (Input::GetVKey('T') == true)
	{
		if (m_kb_sw == true)
		{
			Audio::Start(1);
			Scene::SetScene(new CSceneTitle());
			m_kb_sw = false;
		}
		else
		{
			m_kb_sw = true;
		}
	}




}
//------------------------------------------------------------------------------------------------------------------------------------------
//ドロー--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
void CSceneGameOver::Draw()
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
	Draw::Draw(3, &src, &dst, c, 0.0f);

	//テキスト----------------------------------------------------
	//表示位置
	dst2.m_top = 0.0f;
	dst2.m_left = 280.0f;
	dst2.m_right = 740.0f;
	dst2.m_bottom = 220.0f;
		Draw::Draw(5, &src, &dst2, c, 0.0f);//

	dst3.m_top = 240.0f;
	dst3.m_left = 240.0f;
	dst3.m_right = 800.0f;
	dst3.m_bottom = 350.0f;
	Draw::Draw(1, &src, &dst3, c, 0.0f);//アクション画面へ
	dst3.m_top = 370.0f;
	dst3.m_left = 240.0f;
	dst3.m_right = 780.0f;
	dst3.m_bottom = 480.0f;
	//Draw::Draw(1, &src, &dst3, c, 0.0f);//MAP
	dst3.m_top = 500.0f;
	dst3.m_left = 240.0f;
	dst3.m_right = 800.0f;
	dst3.m_bottom = 610.0f;
		Draw::Draw(1, &src, &dst3, c, 0.0f);//タイトルへ
	//文字表示---------------------------------------
	//Font::StrDraw(L" ゲームオーバー", 365, 120, 40, c);
	//	Font::StrDraw(L"未完（ 画像ない ）左上クリック or 右上クリック",90,125,35,c);
	Font::StrDraw(L"Enter:ステージ選択画面へ", 260, 280, 44, c);
	//Font::StrDraw(L"無題", 325, 410, 44, c);
	Font::StrDraw(L"T:タイトルへ", 340,530, 55, c);
}

