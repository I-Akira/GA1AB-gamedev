//STLデバッグ機能をＯＦＦに
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "SceneItem.h"
#include "GameHead.h"

#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"

using namespace GameL;

void CSceneItem::InitScene()
{
	CSceneItem* objI = new CSceneItem();
	Objs::InsertObj(objI, OBJ_SHOP_ITEM, 1);

	Draw::LoadImage(L"tekisuto1.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"tekisuto2.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"haikei3.png"  , 5, TEX_SIZE_512);
}
//------------------------------------------------------------------------------------------------------------------------------------
//初期化----------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
void CSceneItem::Scene()
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------
//イニシャライズ---------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
void CSceneItem::Init()
{
	m_mou_x = 0.0f;   //マウスの位置
	m_mou_y = 0.0f;
	m_mou_r = false;  //マウスの状態　　false = 押してない　 true = 押してる
	m_mou_l = false;
}

//----------------------------------------------------------------------------------------------------------------------------------------------
//アクション-----------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
void CSceneItem::Action()
{
	//マウスの座標を取得
	m_mou_x = float(Input::GetPosX());
	m_mou_y = float(Input::GetPosY());
	//マウスの状態を取得
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//買う
	if (m_mou_x >= 730 && m_mou_x <= 1000 && m_mou_y >= 430 && m_mou_y <= 530)
	{
		if (m_mou_l == true)
		{
			Draw2();
		}
	}

	//戻る
	if (m_mou_x >= 730 && m_mou_x <= 1000  && m_mou_y >= 600 && m_mou_y <= 660)
	{
		if (m_mou_l == true)
		{
			Scene::SetScene(new CSceneMap());
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------
//ドロー--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
void CSceneItem::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst,dst2,dst3;

	//背景-------------------------------------------------------------
	//切り取り位置
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 500.0f;
	src.m_bottom = 500.0f;
	//表示位置
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right  = 525.0f + src.m_right;
	dst.m_bottom = 265.0f + src.m_bottom;
	Draw::Draw(5, &src, &dst, c, 0.0f);
	//テキスト---------------------------------------------------------アイテム屋
	//表示位置
	dst.m_top = 0.0f;
	dst.m_left = 00.0f;
	dst.m_right = 380.0f;
	dst.m_bottom = 120.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);
	//テキスト----------------------------------------------------------買う
	//表示位置
	dst2.m_top    =  400.0f;
	dst2.m_left   =  700.0f;
	dst2.m_right  = 1000.0f;
	dst2.m_bottom =  530.0f;
	Draw::Draw(2, &src, &dst2, c, 0.0f);
	//テキスト-----------------------------------------------------戻る
	//表示位置
	dst3.m_top    =  550.0f;
	dst3.m_left   =  700.0f;
	dst3.m_right  = 1000.0f;
	dst3.m_bottom =  680.0f;
	Draw::Draw(2, &src, &dst3, c, 0.0f);
	//文字表示------------------------------------------------------------------
//	Font::StrDraw(L" ★アイテム屋★", 50, 45, 35, c);
//	Font::StrDraw(L"   買う", 700, 450, 60, c);
//	Font::StrDraw(L"マップに戻る", 750, 620, 35, c);//  
}

void CSceneItem::Draw2()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L" ★アイテム屋★", 50, 45, 35, c);
	Font::StrDraw(L"   買う", 700, 450, 60, c);
	Font::StrDraw(L"マップに戻る", 750, 620, 35, c);//  
}

/*
//マウスの位置表示------------------------------------------------
wchar_t str[256];
swprintf_s(str, L"x = %f, y = %f", m_mou_x, m_mou_y);
Font::StrDraw(str, 500, 20, 20, c);
*/