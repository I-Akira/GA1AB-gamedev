#include "Input.h"

int CInput::m_mou_x;
int CInput::m_mou_y;

void CInput::InitInput()
{
	m_mou_x = 0;
	m_mou_y = 0;
}

//マウス位置取得用　ウィンドウプロジャーシャーに宣言
void CInput::SetMouPos(UINT* uMsg, LPARAM* iParam)
{
	switch (*uMsg)
	{
	case WM_MOUSEMOVE:
	{
		POINT point = { LOWORD(*iParam), HIWORD((*iParam)) };

		m_mou_x = point.x;
		m_mou_y = point.y;

	}
	break;
	}
}

//キー・マウスボタンのプッシュ確認
bool CInput::KeyPush(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		return true;
	}
	return false;
}