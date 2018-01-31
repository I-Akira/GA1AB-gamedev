//STL�f�o�b�O�@�\���n�e�e��
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

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"Htext.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"tekisuto2.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"BGameOver.png", 3, TEX_SIZE_512);
	Draw::LoadImage(L"haikei2.png", 4, TEX_SIZE_512);
	Draw::LoadImage(L"GameOver.png", 5, TEX_SIZE_512);
	//���y�ESE�ǂݍ���
	Audio::LoadAudio(0, L"SE GameOver.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(1, L"SE SELECT.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);
}
//----------------------------------------------------------------------------------------------------------------------------------------
void CSceneGameOver::Scene()//������-------------------------------------------------------------------------------------------------------------
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------
//�C�j�V�����C�Y---------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
void CSceneGameOver::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}
//----------------------------------------------------------------------------------------------------------------------------------------------
//�A�N�V����-----------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
void CSceneGameOver::Action()
{
	//�}�E�X�̍��W
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//�A�N�V�����Ɉړ�
	if (m_mou_x <= 770 && m_mou_x >= 280 && m_mou_y >= 260 && m_mou_y <= 350)
	{
		if (m_mou_l == true)
		{
			Audio::Start(1);
			Scene::SetScene(new CSceneBattle());
		}
	}
	//map��
	if (m_mou_x <= 770 && m_mou_x >= 280 && m_mou_y >= 390 && m_mou_y <= 480)
	{
		if (m_mou_l == true)
		{
			Audio::Start(1);
			Scene::SetScene(new CSceneMap());//
		}
	}
	//�^�C�g����
	if (m_mou_x <= 770 && m_mou_x >= 280 && m_mou_y >= 530 && m_mou_y <= 610)
	{
		if (m_mou_l == true)
		{
			Audio::Start(1);
			Scene::SetScene(new CSceneTitle());
		}
	}




}
//------------------------------------------------------------------------------------------------------------------------------------------
//�h���[--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
void CSceneGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst, dst2, dst3;

	//�w�i---------------------------------------------------------
	//�؂���ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 500.0f;
	src.m_bottom = 500.0f;
	//�\���ʒu
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1030.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(3, &src, &dst, c, 0.0f);

	//�e�L�X�g----------------------------------------------------
	//�\���ʒu
	dst2.m_top = 0.0f;
	dst2.m_left = 280.0f;
	dst2.m_right = 740.0f;
	dst2.m_bottom = 220.0f;
		Draw::Draw(5, &src, &dst2, c, 0.0f);//

	dst3.m_top = 240.0f;
	dst3.m_left = 280.0f;
	dst3.m_right = 770.0f;
	dst3.m_bottom = 350.0f;
	Draw::Draw(1, &src, &dst3, c, 0.0f);//�A�N�V������ʂ�
	dst3.m_top = 370.0f;
	dst3.m_left = 280.0f;
	dst3.m_right = 770.0f;
	dst3.m_bottom = 480.0f;
	Draw::Draw(1, &src, &dst3, c, 0.0f);//MAP
	dst3.m_top = 500.0f;
	dst3.m_left = 280.0f;
	dst3.m_right = 770.0f;
	dst3.m_bottom = 610.0f;
		Draw::Draw(1, &src, &dst3, c, 0.0f);//�^�C�g����
	//�����\��---------------------------------------
	//Font::StrDraw(L" �Q�[���I�[�o�[", 365, 120, 40, c);
	//	Font::StrDraw(L"�����i �摜�Ȃ� �j����N���b�N or �E��N���b�N",90,125,35,c);
	Font::StrDraw(L"���X�^�[�g", 380, 280, 55, c);
	Font::StrDraw(L"�X�e�[�W�I����ʂ�", 325, 410, 44, c);
	Font::StrDraw(L"�^�C�g����", 380,530, 55, c);
	//���}�E�X�̈ʒu�\��----------------------------------------
	wchar_t str[256];
	swprintf_s(str, L"x = %f, y = %f", m_mou_x, m_mou_y);
	//	Font::StrDraw(str, 500, 20, 20, c);
}

