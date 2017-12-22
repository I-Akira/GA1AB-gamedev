//STLデバッグ機能をＯＦＦに
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "ShopSoubi.h"
#include "ShopSoubi2.h"

#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"


using namespace GameL;

void CSceneShopBugu::InitScene()
{
	 CSceneShopBugu* obj = new CSceneShopBugu();
	 Objs::InsertObj(obj, OBJ_SHOP_SOUBI, 1);
	 //グラフィック読み込み
	 Draw::LoadImage(L"tatemono2.png", 0, TEX_SIZE_512);
	 Draw::LoadImage(L"tekisuto1.png", 1, TEX_SIZE_512);
	 Draw::LoadImage(L"tekisuto2.png", 2, TEX_SIZE_512);


}
//-------------------------------------------------------------------------------------------------------------------------------------------
void CSceneShopBugu::Scene()
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------
//イニシャライズ---------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
void CSceneShopBugu::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}
//----------------------------------------------------------------------------------------------------------------------------------------------
//アクション-----------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
void CSceneShopBugu::Action()
{
	//マウスの座標
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	

	//買う
	if (m_mou_x >= 730  &&  m_mou_x<=1000  && m_mou_y>=430  && m_mou_y<=520)
	{
		if (m_mou_l == true )
		{
			Scene::SetScene(new CSceneShopBugu2() );
		}
	}
	//マップに戻る
	if (m_mou_x >= 730 && m_mou_x <= 1000 && m_mou_y >= 600 && m_mou_y <= 660)
	{

		if (m_mou_l == true)
		{
			Scene::SetScene(new CSceneMap() );
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------
//ドロー--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
void CSceneShopBugu::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;
	RECT_F src1;
	RECT_F dst1;
	RECT_F src2;
	RECT_F dst2;

//背景--------------------------------------------------------------
	//切り取り位置
	src.m_top    =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 500.0f;
	src.m_bottom = 500.0f;
	//表示位置
	dst.m_top    =   0.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 1025.0f;  
	dst.m_bottom = 765.0f;  
	
	Draw::Draw(0, &src, &dst, c, 0.0f);

//テキスト
	//切り取り位置-------------------------------------------武具屋
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 500.0f;
	src.m_bottom = 500.0f;
	//表示位置
	dst.m_top    =   0.0f;
	dst.m_left   =  00.0f;
	dst.m_right  = 380.0f;  
	dst.m_bottom = 120.0f;  
	Draw::Draw(1, &src, &dst, c, 0.0f);
	//切り取り位置------------------------------------------買う
	src1.m_top = 0.0f;
	src1.m_left = 0.0f;
	src1.m_right = 500.0f;
	src1.m_bottom = 500.0f;
	//表示位置
	dst1.m_top    = 410.0f;
	dst1.m_left   = 700.0f;
	dst1.m_right  = 1000.0f;  
	dst1.m_bottom = 520.0f;  
	Draw::Draw(2, &src1, &dst1, c, 0.0f);
	//切り取り位置------------------------------------------戻る
	src2.m_top    = 0.0f;
	src2.m_left   = 0.0f;
	src2.m_right  = 500.0f;
	src2.m_bottom = 500.0f;
	//表示位置
	dst2.m_top    = 560.0f;
	dst2.m_left   = 700.0f;
	dst2.m_right  = 1000.0f;  
	dst2.m_bottom = 670.0f;  
	Draw::Draw(2, &src2, &dst2, c, 0.0f);

//文字表示---------------------------------------------------
	Font::StrDraw(L" ★武具屋★", 50,  45, 50, c);// 
	Font::StrDraw(L" 買 う", 740, 450, 60, c);//
	Font::StrDraw(L" マップに戻る", 730, 610, 35, c);

	//仮マウスの位置表示
	wchar_t str[256];
	swprintf_s(str, L"x = %f, y = %f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 500, 20, 20, c);
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