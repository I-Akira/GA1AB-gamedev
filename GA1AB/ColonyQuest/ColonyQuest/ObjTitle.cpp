//�g�p�w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "GameL\Audio.h"

#include "ObjTitle.h"


//�g�p�l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	Draw::LoadImage(L"tekisuto1.png", 1, TEX_SIZE_512);
	Audio::LoadAudio(0, L"SE SELECT.wav", SOUND_TYPE::EFFECT);
	m_key_flag = false;

	//�Q�[�������s����1��̂�
	static bool init_point = false;


	if (init_point == true)
		Save::Seve();//UserData�̏��𓯃t�H���_�uUserData�v���쐬����B
}

//�A�N�V����
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

//�h���[
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 0.1f,0.1f,0.1f,1.0f };

	RECT_F src,src2;
	RECT_F dst, dst3;
	
	//�w�i�ݒ�
	src.m_top = 0.0f;
	src.m_bottom = 768.0f;
	src.m_left = 0.0f;
	src.m_right = 1024.0f;

	dst.m_top = 0.0f;
	dst.m_bottom = 768.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1024.0f;

	Draw::Draw(0, &src, &dst, c, 0.0f);

	//�؂���ʒu
	src2.m_top = 0.0f;
	src2.m_left = 0.0f;
	src2.m_right = 500.0f;
	src2.m_bottom = 500.0f;

	dst3.m_top = 480.0f;
	dst3.m_left = 380.0f;
	dst3.m_right = 640.0f;
	dst3.m_bottom = 550.0f;
	Draw::Draw(1, &src2, &dst3, c, 0.0f);//�^�C�g����
	//�^�C�g��
	Font::StrDraw(L"��������", TITLE_POS_X+92, TITLE_POS_Y, TITLE_FONT_SIZE, b);
	Font::StrDraw(L"�`Bakusou Little girl�`", TITLE_POS_X-45, TITLE_POS_Y+TITLE_FONT_SIZE, TITLE_FONT_SIZE, b);
	

	//�N���b�N����ꏊ
	//�Q�[���Ɉڍs����N���b�N�ꏊ
	Font::StrDraw(L"Enter:�X�^�[�g", CLICK_START_POS_X-20, CLICK_START_POS_Y, CLICK_START_FONT_SIZE, c);
}
