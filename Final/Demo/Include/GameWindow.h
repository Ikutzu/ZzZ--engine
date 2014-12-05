#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>
#include "Buffer.h"
#include "GL\glew.h"

namespace ZZZ
{

	class GameWindow
	{
		friend class Device;
	public:

		~GameWindow(){ UnregisterClass("GameWindowClass", hInstance); }
		HWND* getWindowHandle(){ return &hWnd; };

	private:

		GameWindow();

		GameWindow(LPCSTR wName, RECT wClientCoord);
		
		HWND hWnd;
		HDC hdc;
		HGLRC hglrc;
		HINSTANCE hInstance;

	};
}

#endif