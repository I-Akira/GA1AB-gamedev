//STL�f�o�b�O�@�\OFF
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�w�b�_�[
#include "GameL\Drawtexture.h"
#include "GameL\WinInputs.h"

#include "SceneTitle.h"
#include "ObjTitle.h"
#include "GameHead.h"

CSceneTitle::CSceneTitle()
{

}

CSceneTitle::~CSceneTitle()
{

}

void CSceneTitle::InitScene()
{
	Draw::LoadImageW(L"Title.png",0, TEX_SIZE_1024);
	CObjTitle* p = new CObjTitle();
	Objs::InsertObj(p, OBJ_TITLE, 1);
}

void CSceneTitle::Scene()
{


}