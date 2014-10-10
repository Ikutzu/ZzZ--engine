#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>
#include "GL\glew.h"

namespace ZZZ
{

	class GameWindow
	{
	public:

		GameWindow(){ hWnd = nullptr; hInstance = nullptr; }
		~GameWindow(){ UnregisterClass("GameWindowClass", hInstance); }
		static GameWindow& createWindow(LPCSTR wName, RECT wClientCoord);
		void update();
		bool running;

	private:

		
		GameWindow(WNDCLASSEX& win, LPCSTR wName, RECT wClientCoord);

		static GameWindow wStack[1];

		HWND hWnd;
		HDC hdc;
		HGLRC hglrc;
		HINSTANCE hInstance;
		MSG msg;

	};

}


#endif