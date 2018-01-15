//STL�f�o�b�O�@�\���n�e�e��
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING (0)

#include "SceneMap.h"
#include "SceneMain.h"

#include "GameHead.h"

#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"

using namespace GameL;

void CSceneMap::InitScene()
{
	CSceneMap* map = new CSceneMap();
	Objs::InsertObj(map, OBJ_SCENE_MAP, 1);

	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImage(L"tekisuto2.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"haikei2.png"  , 4, TEX_SIZE_512);
	Draw::LoadImage(L"tekisuto1.png", 1, TEX_SIZE_512);
}
//----------------------------------------------------------------------------------------------------------------------------------------
void CSceneMap::Scene()//������-------------------------------------------------------------------------------------------------------------
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------
//�C�j�V�����C�Y---------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
void CSceneMap::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}
//----------------------------------------------------------------------------------------------------------------------------------------------
//�A�N�V����-----------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
void CSceneMap::Action()
{
	//�}�E�X�̍��W
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();


	//���퉮�Ɉړ�
	if (m_mou_x <= 300 && m_mou_x >= 0  && m_mou_y <= 300 && m_mou_y >= 0 )
	{
		if (m_mou_l == true)
		{
			Scene::SetScene(new CSceneShopBugu());//aaaaaaa
		}
	}
	//����Ɉړ�
	if (m_mou_x <= 1010 && m_mou_x >= 800 && m_mou_y >= 0 && m_mou_y <= 200)
	{
		if (m_mou_l == true)
		{
			Scene::SetScene(new CSceneItem());
		}
	}
	//����Ɉړ�
	if (m_mou_x <= 300 && m_mou_x >= 0 && m_mou_y >= 568 && m_mou_y <= 768)
	{
		if (m_mou_l == true)
		{
			Scene::SetScene(new CSceneBattle());
		}
	}
	


}
//------------------------------------------------------------------------------------------------------------------------------------------
//�h���[--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
void CSceneMap::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;
	RECT_F src1;
	RECT_F dst1;

//�w�i---------------------------------------------------------
	//�؂���ʒu
	src.m_top 	 =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 500.0f;
	src.m_bottom = 500.0f;
	//�\���ʒu
	dst.m_top    =   0.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(4, &src, &dst, c, 0.0f);

//�e�L�X�g----------------------------------------------------
	//�؂���ʒu
	src1.m_top    =   0.0f;
	src1.m_left   =   0.0f;
	src1.m_right  = 500.0f;
	src1.m_bottom = 500.0f;
	//�\���ʒu
	dst.m_top    =   0.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 380.0f;
	dst.m_bottom = 120.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);


    //�����\��---------------------------------------
	Font::StrDraw(L" ��MAP��", 50, 45, 50, c);	
	Font::StrDraw(L"�����i �摜�Ȃ� �j����N���b�N or �E��N���b�N",90,125,35,c);
	Font::StrDraw(L"�����N���b�N", 90, 160, 35, c);

	//���}�E�X�̈ʒu�\��----------------------------------------
	wchar_t str[256];
	swprintf_s(str, L"x = %f, y = %f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 500, 20, 20, c);
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