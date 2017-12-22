//STLデバッグ機能をＯＦＦにする
#define _SECURE_SCL	(0)
#define _HAS_ITERATOR_DEBUGGING	(0)


#include "GameHead.h"
#include "SceneMain.h"

#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"




//---------------------------------------------------------------------------------------------------------------
//コンストラクタ---------------------------------------------------------------------------------------------------
CSceneMain::CSceneMain()
{

}
//------------------------------------------------------------------------------------------------------------
//デストラクタ---------------------------------------------------------------------------------------------------
CSceneMain::~CSceneMain()
{

}
//---------------------------------------------------------------------------------------------------------------
//ゲームメイン初期化-----------------------------------------------------------------------------------------------
void CSceneMain::InitScene()
{
	//グラフィック読み込み
	Draw::LoadImage(L"tatemono2.png", 0, TEX_SIZE_512);
	Draw::LoadImage(L"tekisuto1.png", 1, TEX_SIZE_512);
	Draw::LoadImage(L"tekisuto2.png", 2, TEX_SIZE_512);
	Draw::LoadImage(L"haikei1.png"  , 3, TEX_SIZE_512);
	Draw::LoadImage(L"haikei2.png"  , 4, TEX_SIZE_512);
	Draw::LoadImage(L"haikei3.png"  , 5, TEX_SIZE_512);
	
//	CSceneItem2* objII = new CSceneItem2();
//	Objs::InsertObj(objII, OBJ_SHOP_ITEM, 1);

//	CSceneItem* objI = new CSceneItem();
//	Objs::InsertObj(objI, OBJ_SHOP_ITEM, 1);

//	CSceneMap* map = new CSceneMap();
//	Objs::InsertObj(map, OBJ_SCENE_MAP, 2);

//	CSceneShopBugu* obj = new CSceneShopBugu();
//	Objs::InsertObj(obj, OBJ_SHOP_SOUBI, 1);

}
//-------------------------------------------------------------------------------------------------------------------
//ゲームメイン実行中--------------------------------------------------------------------------------------------------
void CSceneMain::Scene()
{

}