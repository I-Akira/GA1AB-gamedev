//STL�f�o�b�O�@�\OFF
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�w�b�_�[
#include "GameL\DrawFont.h"
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
	CObjTitle* p = new CObjTitle();
	Objs::InsertObj(p, OBJ_TITLE, 1);
}

void CSceneTitle::Scene()
{


}