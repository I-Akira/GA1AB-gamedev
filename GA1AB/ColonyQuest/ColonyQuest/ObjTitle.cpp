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
	Audio::LoadAudio(0, L"SE SELECT.wav", SOUND_TYPE::EFFECT);
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
	m_deb_mn = false;

	//�Q�[�������s����1��̂�
	static bool init_point = false;


	if (init_point == true)
		Save::Seve();//UserData�̏��𓯃t�H���_�uUserData�v���쐬����B
}

//�A�N�V����
void CObjTitle::Action()
{

	//�}�E�X�ʒu�擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�{�^�����
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//�}�E�X�ʒu�ƃN���b�N����ꏊ�œ����蔻��
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

//�h���[
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float b[4] = { 0.1f,0.1f,0.1f,1.0f };

	RECT_F src;
	RECT_F dst;
	
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

	//�^�C�g��
	Font::StrDraw(L"�����̂��g��", TITLE_POS_X+44, TITLE_POS_Y, TITLE_FONT_SIZE, b);
//	Font::StrDraw(L"�`Bakusou Runner�`", TITLE_POS_X-20, TITLE_POS_Y+TITLE_FONT_SIZE, TITLE_FONT_SIZE, b);
	

	//�N���b�N����ꏊ
	//�Q�[���Ɉڍs����N���b�N�ꏊ
	Font::StrDraw(L"�X�^�[�g", CLICK_START_POS_X+20, CLICK_START_POS_Y, CLICK_START_FONT_SIZE, b);



	/*//���}�E�X�ʒu�\��
	wchar_t str[256];
	swprintf_s(str, L"x=%f,y=%f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 20, 20, 12, c);
	//���}�E�X�{�^�����
	if (m_mou_r == true)
		Font::StrDraw(L"R=�����Ă�", 20, 30, 12, c);
	else
		Font::StrDraw(L"R=�����ĂȂ�", 20, 30, 12, c);
	if (m_mou_l == true)
		Font::StrDraw(L"L=�����Ă�", 20, 40, 12, c);
	else
		Font::StrDraw(L"L=�����ĂȂ�", 20, 40, 12, c);*/

	/*if(m_deb_mn==true)
		Font::StrDraw(L"�f�o�b�O�F���C����ʈڍs�X�C�b�`", 20, 620, 32, b);
		*/ //�f�o�b�O�p�F���C����ʈڍs�ł��邩�m�F
}
