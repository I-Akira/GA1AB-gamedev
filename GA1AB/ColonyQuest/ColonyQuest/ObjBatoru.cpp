//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\hitBoxManager.h"
#include "GameL\DrawFont.h"


#include "GameHead.h"
#include "ObjBatoru.h"
#include "ObjHero.h"
#include "ObjEnemy.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
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

//�A�N�V����
void CObjBatoru::Action()
{
	
}

//�h���[
void CObjBatoru::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	Font::StrDraw(L"D�F�U��"    , 50, 680, 30, c);
	Font::StrDraw(L"S�F�W�����v", 240, 680, 30, c);
	Font::StrDraw(L"A�F���xUP"  , 490, 680, 30, c);
	Font::StrDraw(L"E�F�I����ʂɖ߂�", 700, 680, 30, c);
	Draw::LoadImageW(L"sougen.png", 1, TEX_SIZE_512);
	//�w�i�\��
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
