//STL�f�o�b�O�@�\���n�e�e��
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
	Draw::LoadImage(L"haikei3.png", 5, TEX_SIZE_512);
}

//------------------------------------------------------------------------------------------------------------------------------------
//������----------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
void CSceneItem::Scene()
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------
//�C�j�V�����C�Y---------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
void CSceneItem::Init()
{
	m_mou_x = 0.0f;   //�}�E�X�̈ʒu
	m_mou_y = 0.0f;
	m_mou_r = false;  //�}�E�X�̏�ԁ@�@false = �����ĂȂ��@ true = �����Ă�
	m_mou_l = false;
}

//----------------------------------------------------------------------------------------------------------------------------------------------
//�A�N�V����-----------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
void CSceneItem::Action()
{
	//�}�E�X�̍��W���擾
	m_mou_x = float(Input::GetPosX());
	m_mou_y = float(Input::GetPosY());
	//�}�E�X�̏�Ԃ��擾
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//����
	if (m_mou_x >= 730 && m_mou_x <= 1000 && m_mou_y >= 430 && m_mou_y <= 530)
	{
		if (m_mou_l == true)
		{
			Scene::SetScene(new CSceneItem2());
		}
	}

	//�߂�
	if (m_mou_x >= 730 && m_mou_x <= 1000  && m_mou_y >= 600 && m_mou_y <= 660)
	{
		if (m_mou_l == true)
		{
			Scene::SetScene(new CSceneMap());
		}
	}

}

//------------------------------------------------------------------------------------------------------------------------------------------
//�h���[--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------
void CSceneItem::Draw()
{

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;
	RECT_F dst;
	RECT_F src2;
	RECT_F dst2;
	RECT_F src3;
	RECT_F dst3;
	//�w�i-------------------------------------------------------------
	//�؂���ʒu
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 500.0f;
	src.m_bottom = 500.0f;
	//�\���ʒu
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right  = 525.0f + src.m_right;
	dst.m_bottom = 265.0f + src.m_bottom;
	Draw::Draw(5, &src, &dst, c, 0.0f);

	//�؂���ʒu-------------------------------------------�A�C�e����
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 500.0f;
	src.m_bottom = 500.0f;
	//�\���ʒu
	dst.m_top = 0.0f;
	dst.m_left = 00.0f;
	dst.m_right = 380.0f;
	dst.m_bottom = 120.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	//�e�L�X�g----------------------------------------------------------����
	//�؂���ʒu
	src2.m_top    =   0.0f;
	src2.m_left   =   0.0f;
	src2.m_right  = 500.0f;
	src2.m_bottom = 500.0f;
	//�\���ʒu
	dst2.m_top    =  400.0f;
	dst2.m_left   =  700.0f;
	dst2.m_right  = 1000.0f;
	dst2.m_bottom =  530.0f;
	Draw::Draw(2, &src2, &dst2, c, 0.0f);
	//�؂���ʒu-----------------------------------------------------�߂�
	src3.m_top    =   0.0f;
	src3.m_left   =   0.0f;
	src3.m_right  = 500.0f;
	src3.m_bottom = 500.0f;
	//�\���ʒu
	dst3.m_top    =  550.0f;
	dst3.m_left   =  700.0f;
	dst3.m_right  = 1000.0f;
	dst3.m_bottom =  680.0f;
	Draw::Draw(2, &src3, &dst3, c, 0.0f);

	//�����\��------------------------------------------------------------------

	Font::StrDraw(L" ���A�C�e������", 50, 45, 35, c);
	Font::StrDraw(L"   ����", 700, 450, 60, c);
	Font::StrDraw(L"�}�b�v�ɖ߂�", 750, 620, 35, c);//  

	//���}�E�X�̈ʒu�\��------------------------------------------------
	wchar_t str[256];
	swprintf_s(str, L"x = %f, y = %f", m_mou_x, m_mou_y);
	Font::StrDraw(str, 500, 20, 20, c);
}