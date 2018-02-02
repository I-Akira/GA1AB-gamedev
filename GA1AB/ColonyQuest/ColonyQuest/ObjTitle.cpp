//使用ヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "GameL\Audio.h"

#include "ObjTitle.h"


//使用ネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	Audio::LoadAudio(0, L"SE SELECT.wav", SOUND_TYPE::EFFECT);
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_deb_mn = false;

	//ゲームを実行して1回のみ
	static bool init_point = false;


	if (init_point == true)
		Save::Seve();//UserDataの情報を同フォルダ「UserData」を作成する。
}

//アクション
void CObjTitle::Action()
{

	//マウス位置取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//マウスボタン状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//マウス位置とクリックする場所で当たり判定
	if (m_mou_x > MOU_MAIN_HIT_X && m_mou_x <MOU_MAIN_HIT_W &&
		m_mou_y>MOU_MAIN_HIT_Y && m_mou_y < MOU_MAIN_HIT_H)
	{
		if (m_mou_r == true || m_mou_l == true)
		{
			Audio::Start(0);
			Scene::SetScene(new CSceneStory());
		}
		else
		{
			m_deb_mn = false;
		}
	}
	else
	{
		m_deb_mn = false;
	}





}

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 0.1f,0.1f,0.1f,1.0f };

	RECT_F src;
	RECT_F dst;
	
	//背景設定
	src.m_top = 0.0f;
	src.m_bottom = 768.0f;
	src.m_left = 0.0f;
	src.m_right = 1024.0f;

	dst.m_top = 0.0f;
	dst.m_bottom = 768.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1024.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);

	//タイトル
	Font::StrDraw(L"少女のお使い", TITLE_POS_X+44, TITLE_POS_Y, TITLE_FONT_SIZE, b);
//	Font::StrDraw(L"～Bakusou Runner～", TITLE_POS_X-20, TITLE_POS_Y+TITLE_FONT_SIZE, TITLE_FONT_SIZE, b);
	

	//クリックする場所
	//ゲームに移行するクリック場所
	Font::StrDraw(L"スタート", CLICK_START_POS_X+20, CLICK_START_POS_Y, CLICK_START_FONT_SIZE, b);



	/*//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);
	//仮マウスボタン状態
	if (m_mou_r == true)
		Font::StrDraw(L"R=押してる", 20, 30, 12, c);
	else
		Font::StrDraw(L"R=押してない", 20, 30, 12, c);
	if (m_mou_l == true)
		Font::StrDraw(L"L=押してる", 20, 40, 12, c);
	else
		Font::StrDraw(L"L=押してない", 20, 40, 12, c);*/

	/*if(m_deb_mn==true)
		Font::StrDraw(L"デバッグ：メイン画面移行スイッチ", 20, 620, 32, b);
		*/ //デバッグ用：メイン画面移行できるか確認
}
