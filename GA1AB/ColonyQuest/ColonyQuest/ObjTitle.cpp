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
	Draw::LoadImage(L"tekisuto1.png", 1, TEX_SIZE_512);
	Audio::LoadAudio(0, L"SE SELECT.wav", SOUND_TYPE::EFFECT);
	m_key_flag = false;

	//ゲームを実行して1回のみ
	static bool init_point = false;


	if (init_point == true)
		Save::Seve();//UserDataの情報を同フォルダ「UserData」を作成する。
}

//アクション
void CObjTitle::Action()
{



	if (Input::GetVKey(VK_RETURN)==true)
	{
		if (m_key_flag == true)
		{
			Audio::Start(0);
			if (Input::GetVKey(VK_RETURN) == true)
			{
				Scene::SetScene(new CSceneStory());
				m_key_flag = false;
			}
		}
		else
		{
			m_key_flag = true;
		}
	}


}

//ドロー
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 0.1f,0.1f,0.1f,1.0f };

	RECT_F src,src2;
	RECT_F dst, dst3;
	
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

	//切り取り位置
	src2.m_top = 0.0f;
	src2.m_left = 0.0f;
	src2.m_right = 500.0f;
	src2.m_bottom = 500.0f;

	dst3.m_top = 480.0f;
	dst3.m_left = 380.0f;
	dst3.m_right = 640.0f;
	dst3.m_bottom = 550.0f;
	Draw::Draw(1, &src2, &dst3, c, 0.0f);//タイトルへ
	//タイトル
	Font::StrDraw(L"爆走少女", TITLE_POS_X+92, TITLE_POS_Y, TITLE_FONT_SIZE, b);
	Font::StrDraw(L"～Bakusou Little girl～", TITLE_POS_X-45, TITLE_POS_Y+TITLE_FONT_SIZE, TITLE_FONT_SIZE, b);
	

	//クリックする場所
	//ゲームに移行するクリック場所
	Font::StrDraw(L"Enter:スタート", CLICK_START_POS_X-20, CLICK_START_POS_Y, CLICK_START_FONT_SIZE, c);
}
