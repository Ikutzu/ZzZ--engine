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

		void setBackgroundColor(float red, float green, float blue);

		void update();
		bool running;

	private:


		GameWindow(WNDCLASSEX& win, LPCSTR wName, RECT wClientCoord);

		static GameWindow wStack[1];

		float backgroundColor[4];

		HWND hWnd;
		HDC hdc;
		HGLRC hglrc;
		HINSTANCE hInstance;
		MSG msg;

	};

}


#endif