//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameL\Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneBattle2.h"
#include "Gamehead.h"

//���������\�b�h
void CSceneBattle2::InitScene()
{
	//�X�e�[�W�f�[�^�̓ǂݍ���
	unique_ptr<wchar_t> p;
	int size;
	p = Save::ExternalDataOpen(L"Book2.csv", &size);

	int map[10][100];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}
	//Font�쐬
	//Font::SetStrTex(L"0123456789���b");
	//�O���t�B�b�N�ǂݍ���
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"sougen.png", 1, TEX_SIZE_512);


	CObjBatoru*objv = new CObjBatoru();
	Objs::InsertObj(objv, OBJ_BATORU, 5);

	//��l���I�u�W�F�N�g�쐬
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//block�I�u�W�F�N�g�쐬
	CObjBlock*objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//Time�I�u�W�F�N�g�쐬
	CObjTime*objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 11);



}
//���s�����\�b�h
void CSceneBattle2::Scene()
{

}