//STLデバッグ機能をＯＦＦに
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "SceneClear.h"

#include "GameHead.h"

#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\Audio.h"

using namespace GameL;

void CSceneClear::InitScene()
{
	CSceneClear* map = new CSceneClear();
	Objs::InsertObj(map, OBJ_SCENECLEAR, 1);

	//グラフィック読み込み
	Draw::LoadImage(L"tekisuto1.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"tekisuto2.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"gameclearH.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"haikei2.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"gameclear.png", 5, TEX_SIZE_512);
	//音楽・SE読み込み
	Audio::LoadAudio(0, L"SE GameClear.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(1, L"SE SELECT.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);
}
//----------------------------------------------------------------------------------------------------------------------------------------
void CSceneClear::Scene()//初期化-------------------------------------------------------------------------------------------------------------
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------
//イニシャライズ---------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
void CSceneClear::Init()
{
	m_kb_sw = false;
}
//----------------------------------------------------------------------------------------------------------------------------------------------
//アクション-----------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
void CSceneClear::Action()
{


	//選択画面に移動
	if (Input::GetVKey(VK_RETURN)==true)
	{
		if (m_kb_sw==true)
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
void CSceneClear::Draw()
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
	dst.m_bottom = 1000.0f;
	Draw::Draw(3, &src, &dst, c, 0.0f);

	//テキスト----------------------------------------------------
	//表示位置
	dst2.m_top = 0.0f;
	dst2.m_left = 200.0f;
	dst2.m_right = 835.0f;
	dst2.m_bottom = 400.0f;
	Draw::Draw(5, &src, &dst2, c, 0.0f);//GAMECLEAR

	dst3.m_top = 240.0f;
	dst3.m_left = 240.0f;
	dst3.m_right = 800.0f;
	dst3.m_bottom = 350.0f;
	Draw::Draw(1, &src, &dst3, c, 0.0f);//アクション画面へ
	dst3.m_top = 500.0f;
	dst3.m_left = 240.0f;
	dst3.m_right = 800.0f;
	dst3.m_bottom = 610.0f;
	Draw::Draw(1, &src, &dst3, c, 0.0f);//タイトルへ

	//文字表示---------------------------------------
	Font::StrDraw(L" 少女は薬草の元にたどり着きました！", 160, 70, 40, c);
	Font::StrDraw(L" お母さんの待つおうちに帰りましょう！", 140, 120, 40, c);
	Font::StrDraw(L"Enter:ステージ選択画面へ", 260, 280, 44, c);
	Font::StrDraw(L"T:タイトルへ", 340, 530, 55, c);
	//仮マウスの位置表示----------------------------------------
	//	Font::StrDraw(str, 500, 20, 20, c);
}
