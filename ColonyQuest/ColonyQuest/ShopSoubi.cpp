//STL�f�o�b�O�@�\���n�e�e��
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
	 //�O���t�B�b�N�ǂݍ���
	 Draw::LoadImage(L"tatemono2.png", 0, TEX_SIZE_512);
	 Draw::LoadImage(L"tekisuto1.png", 1, TEX_SIZE_512);
	 Draw::LoadImage(L"tekisuto2.png", 2, TEX_SIZE_512);


}
//-------------------------------------------------------------------------------------------------------------------------------------------
void CSceneShopBugu::Scene()
{

}
//--------------------------------------------------------------------------------------------------------------------------------------------
//�C�j�V�����C�Y---------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------
void CSceneShopBugu::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;
}
//----------------------------------------------------------------------------------------------------------------------------------------------
//�A�N�V����-----------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
void CSceneShopBugu::Action()
{
	//�}�E�X�̍��W
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();
	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	

	//����
	if (m_mou_x >= 730  &&  m_mou_x<=1000  && m_mou_y>=430  && m_mou_y<=520)
	{
		if (m_mou_l == true )
		{
			Scene::SetScene(new CSceneShopBugu2() );
		}
	}
	//�}�b�v�ɖ߂�
	if (m_mou_x >= 730 && m_mou_x <= 1000 && m_mou_y >= 600 && m_mou_y <= 660)
	{

		if (m_mou_l == true)
		{
			Scene::SetScene(new CSceneMap() );
		}
	}
}
//------------------------------------------------------------------------------------------------------------------------------------------
//�h���[--------------------------------------------------------------------------------------------------------------------------------------
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

//�w�i--------------------------------------------------------------
	//�؂���ʒu
	src.m_top    =   0.0f;
	src.m_left   =   0.0f;
	src.m_right  = 500.0f;
	src.m_bottom = 500.0f;
	//�\���ʒu
	dst.m_top    =   0.0f;
	dst.m_left   =   0.0f;
	dst.m_right  = 1025.0f;  
	dst.m_bottom = 765.0f;  
	
	Draw::Draw(0, &src, &dst, c, 0.0f);

//�e�L�X�g
	//�؂���ʒu-------------------------------------------���
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 500.0f;
	src.m_bottom = 500.0f;
	//�\���ʒu
	dst.m_top    =   0.0f;
	dst.m_left   =  00.0f;
	dst.m_right  = 380.0f;  
	dst.m_bottom = 120.0f;  
	Draw::Draw(1, &src, &dst, c, 0.0f);
	//�؂���ʒu------------------------------------------����
	src1.m_top = 0.0f;
	src1.m_left = 0.0f;
	src1.m_right = 500.0f;
	src1.m_bottom = 500.0f;
	//�\���ʒu
	dst1.m_top    = 410.0f;
	dst1.m_left   = 700.0f;
	dst1.m_right  = 1000.0f;  
	dst1.m_bottom = 520.0f;  
	Draw::Draw(2, &src1, &dst1, c, 0.0f);
	//�؂���ʒu------------------------------------------�߂�
	src2.m_top    = 0.0f;
	src2.m_left   = 0.0f;
	src2.m_right  = 500.0f;
	src2.m_bottom = 500.0f;
	//�\���ʒu
	dst2.m_top    = 560.0f;
	dst2.m_left   = 700.0f;
	dst2.m_right  = 1000.0f;  
	dst2.m_bottom = 670.0f;  
	Draw::Draw(2, &src2, &dst2, c, 0.0f);

//�����\��---------------------------------------------------
	Font::StrDraw(L" �������", 50,  45, 50, c);// 
	Font::StrDraw(L" �� ��", 740, 450, 60, c);//
	Font::StrDraw(L" �}�b�v�ɖ߂�", 730, 610, 35, c);

	//���}�E�X�̈ʒu�\��
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