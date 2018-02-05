
//TL�f�o�b�O�@�\���n�e�e��
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

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"tekisuto1.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"tekisuto2.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"haikei4.png", 3, TEX_SIZE_512);
	//���y�ESE�ǂݍ���
	Audio::LoadAudio(0, L"BGM Menu.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(1, L"SE SELECT.wav", SOUND_TYPE::EFFECT);

	Audio::Start(0);
}
//----------------------------------------------------------------------------------------------------------------------------------------
void CSceneStory::Scene()//������-------------------------------------------------------------------------------------------------------------
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------
//�C�j�V�����C�Y---------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
void CSceneStory::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}
//----------------------------------------------------------------------------------------------------------------------------------------------
//�A�N�V����-----------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
void CSceneStory::Action()
{
	//�}�E�X�̍��W
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//�}�b�v��
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
//�h���[--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
void CSceneStory::Draw()
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
//	Draw::Draw(3, &src, &dst, c, 0.0f);

	//�e�L�X�g----------------------------------------------------
	//�\���ʒu
	dst3.m_top = 630.0f;
	dst3.m_left = 470.0f;
	dst3.m_right = 960.0f;
	dst3.m_bottom = 710.0f;
	Draw::Draw(1, &src, &dst3, c, 0.0f);//������
										//�����\��---------------------------------------
	Font::StrDraw(L"�Ƃ��鑺�Ɉ�l�̏����Ƃ��̕�e�����܂����B", 150, 80, 35, c);
	Font::StrDraw(L"���鎞�A��e���ˑR�|��Ă��܂��A�����͑�Q�āB", 120, 120, 35, c);
	Font::StrDraw(L"���ɂ͖���A��̍ޗ��������A�z�g�z�g�����Ă��܂����B", 75, 160, 35, c);
	Font::StrDraw(L"�����ŁA�����͈ӂ������A", 325, 200, 35, c);
	Font::StrDraw(L"���낵�������X�^�[������ꏊ�ɐ����Ă���򑐂���ɂ��悤��", 0, 240, 35, c);
	Font::StrDraw(L"�������񂩂��g����ɖ����", 260, 280, 35, c);
	Font::StrDraw(L"��U��̃i�C�t�ƂƂ��ɑ���o���܂����B",190, 320, 35, c);
	Font::StrDraw(L"���ׂẮA��D���Ȃ��ꂳ��̂��߂ɁE�E�E", 160, 360, 35, c);

	Font::StrDraw(L"�򑐂����ɍs���I", 530, 650, 45, c);
	//���}�E�X�̈ʒu�\��----------------------------------------
	wchar_t str[256];
	swprintf_s(str, L"x = %f, y = %f", m_mou_x, m_mou_y);
	//	Font::StrDraw(str, 500, 20, 20, c);
}
/*----------------------------------------------------------------------------------------------------------------------------
�}�E�X��ԃe�X�g
if (m_mou_l == true)
{
swprintf_s(str, L"L = true");
Font::StrDraw(str, 510, 50, 40, c);
}
else
{
swprintf_s(str, L"L = �����ĂȂ�");
Font::StrDraw(str, 510, 50, 40, c);
}
if (m_mou_r == true)
{
swprintf_s(str, L"R = true");
Font::StrDraw(str, 510, 100, 40, c);
}
else
{
swprintf_s(str, L"R = �����ĂȂ�");
Font::StrDraw(str, 510, 100, 40, c);
}
*/