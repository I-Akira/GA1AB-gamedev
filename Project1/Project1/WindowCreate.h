#pragma once
#include <Windows.h>



class CWindowCreate
{
public:
	CWindowCreate() {};
	~CWindowCreate() {};

	static void NewWindow(int w, int h, wchar_t*name, HINSTANCE hInstance);
	static HWND GethWnd() { return m_hWnd; }

private:
	static HWND m_hWnd;
	static int	m_width;
	static int  m_height;

};