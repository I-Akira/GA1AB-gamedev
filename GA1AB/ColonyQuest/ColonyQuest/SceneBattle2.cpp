//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"
#include "GameL\Audio.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneBattle2.h"
#include "Gamehead.h"

//初期化メソッド
void CSceneBattle2::InitScene()
{
	//ステージデータの読み込み
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
	//Font作成
	//Font::SetStrTex(L"0123456789分秒");
	//グラフィック読み込み
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"sougen.png", 1, TEX_SIZE_512);


	CObjBatoru*objv = new CObjBatoru();
	Objs::InsertObj(objv, OBJ_BATORU, 5);

	//主人公オブジェクト作成
	CObjHero*obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 10);

	//blockオブジェクト作成
	CObjBlock*objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//Timeオブジェクト作成
	CObjTime*objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 11);



}
//実行中メソッド
void CSceneBattle2::Scene()
{

}