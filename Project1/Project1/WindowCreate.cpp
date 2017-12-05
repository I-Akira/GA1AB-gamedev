#include <Windows.h>
#include "WindowCreate.h"

HWND CWindowCreate::m_hWnd;
int  CWindowCreate::m_width;
int  CWindowCreate::m_height;

//NewWindow���\�b�h
//�����P�@int		:�E�B���h�E����
//�����Q�@int		:�E�B���h�E�c��
//�����R�@wchar_t*	:�E�B���h�E�X�e�[�^�X�ƃ^�C�g����
//�����S�@HINSTANCE	:�C���X�^���X�n���h��
//�߂�l�@�Ȃ��ł��B
//���e�F�E�B���h�E�̍쐬
void CWindowCreate::NewWindow(int w, int h, wchar_t*name, HINSTANCE hInstance)
{
	m_width = w;
	m_height = h;

	int width = m_width + GetSystemMetrics(SM_CXDLGFRAME) * 2;
	int height = m_height + GetSystemMetrics(SM_CXDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION);

	//�E�B���h�E�쐬
	if (!(m_hWnd = CreateWindow(name, name,
		WS_OVERLAPPEDWINDOW&~(WS_MAXIMIZEBOX | WS_SIZEBOX),
		CW_USEDEFAULT, 0, width, height, 0, 0, hInstance, 0)))
	{
		return;
	}
	ShowWindow(m_hWnd, SW_SHOW);

}

