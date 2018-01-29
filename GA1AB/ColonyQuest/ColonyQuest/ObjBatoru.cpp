//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\hitBoxManager.h"
#include "GameL\DrawFont.h"


#include "GameHead.h"
#include "ObjBatoru.h"
#include "ObjHero.h"
#include "ObjEnemy.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjBatoru::Init()
{
	int batorublock_data[6][10]=
	{
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0 },
		{ 1,1,1,1,1,1,1,1,1,1 },
	};
memcpy(batorumap, batorublock_data, sizeof(int)*(6 * 10));
}

//アクション
void CObjBatoru::Action()
{
	
}

//ドロー
void CObjBatoru::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	Font::StrDraw(L"D：攻撃"    , 50, 680, 30, c);
	Font::StrDraw(L"S：ジャンプ", 240, 680, 30, c);
	Font::StrDraw(L"A：速度UP"  , 490, 680, 30, c);
	Font::StrDraw(L"E：選択画面に戻る", 700, 680, 30, c);
	Draw::LoadImageW(L"sougen.png", 1, TEX_SIZE_512);
	//背景表示
	src.m_top = 320.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

}
