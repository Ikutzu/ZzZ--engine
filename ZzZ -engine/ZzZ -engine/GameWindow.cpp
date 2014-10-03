#include "GameWindow.h"
#include "GL\glew.h"
//#include "GL/glew.h"
//
//#pragma comment (lib, "opengl32.lib")

//LRESULT CALLBACK GWSTUFF::wndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

using namespace ZZZ;

GameWindow GameWindow::wStack[];
LRESULT CALLBACK wndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

GameWindow::GameWindow(WNDCLASSEX& win, LPCSTR wName, RECT wClientCoord)
{
	hInstance = win.hInstance;

	if (!RegisterClassEx(&win))
	{
		MessageBox(NULL, "FAIL rekisteri", "rekisteriFAIL", NULL);
	}

	AdjustWindowRectEx(&wClientCoord, WS_CAPTION, false, WS_EX_LEFT);

	hWnd = CreateWindowEx(WS_EX_LEFT, "GameWindowClass", wName, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, wClientCoord.left, wClientCoord.top, wClientCoord.right, wClientCoord.bottom, NULL, NULL, win.hInstance, NULL);
	ShowWindow(hWnd, SW_SHOWNORMAL);

	running = true;

	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
		PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
		32,                        //Colordepth of the framebuffer.
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24,                        //Number of bits for the depthbuffer
		8,                        //Number of bits for the stencilbuffer
		0,                        //Number of Aux buffers in the framebuffer.
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};

	hdc = GetDC(hWnd);

	int pixelCode = ChoosePixelFormat(hdc, &pfd);
	SetPixelFormat(hdc, pixelCode, &pfd);

	hglrc = wglCreateContext(hdc);

	wglMakeCurrent(hdc, hglrc);

	glewExperimental = TRUE;
	
	GLenum err = glewInit();
}

GameWindow& GameWindow::createWindow(LPCSTR wName, RECT wClientCoord)
{
	WNDCLASSEX window;

	window.cbSize = sizeof(window);
	window.style = CS_OWNDC;
	window.lpfnWndProc = wndProc;
	window.cbClsExtra = 0;
	window.cbWndExtra = 0;
	window.hInstance = GetModuleHandle(nullptr);
	window.hIcon = NULL;
	window.hCursor = NULL;
	window.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);
	window.lpszMenuName = NULL;
	window.lpszClassName = "GameWindowClass";
	window.hIconSm = NULL;

	wStack[0] = GameWindow(window, wName, wClientCoord);

	return wStack[0];
}

void GameWindow::update()
{
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
	{
		if (msg.message == WM_QUIT)
		{
			running = false;
			break;
		}
		DispatchMessage(&msg);
	}

	glClearColor(0.0f, 0.6f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	SwapBuffers(hdc);

}


LRESULT CALLBACK wndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:

		break;

	case WM_DESTROY:
	
		PostQuitMessage(0);
		break;
	
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}
	/*LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_CREATE:
		{
			PIXELFORMATDESCRIPTOR pfd =
			{
				sizeof(PIXELFORMATDESCRIPTOR),
				1,
				PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
				PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
				32,                        //Colordepth of the framebuffer.
				0, 0, 0, 0, 0, 0,
				0,
				0,
				0,
				0, 0, 0, 0,
				24,                        //Number of bits for the depthbuffer
				8,                        //Number of bits for the stencilbuffer
				0,                        //Number of Aux buffers in the framebuffer.
				PFD_MAIN_PLANE,
				0,
				0, 0, 0
			};

			HDC hdc = GetDC(hWnd);

			int pixelCode = ChoosePixelFormat(hdc, &pfd);
			SetPixelFormat(hdc, pixelCode, &pfd);

			hglrc = wglCreateContext(hdc);

			wglMakeCurrent(hdc, hglrc);

			glewExperimental = TRUE;



			GLenum err = glewInit();
			/*
			if (GLEW_OK != err)
			{
			return 1;
			}

			MessageBoxA(0, (char*)glGetString(GL_VERSION), "OPENGL VERSION", 0);

			if (GLEW_VERSION_2_1)
			{
			MessageBoxA(0, "2.1 SUPPORTED", "OPENGL VERSION", 0);
			}
			

			//lodePNG test
			if (!Lode_test("lode_test_in.png", "lode_test_out.png"))
				MessageBoxA(0, "test failed", "LodePNG test", 0);

			break;
		}
		case WM_DESTROY:
		{
			wglDeleteContext(hglrc);
			PostQuitMessage(0);
		}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;

	}*/
