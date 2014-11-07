#include "GameWindow.h"
#include "Shader.h"


using namespace ZZZ;

LRESULT CALLBACK wndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

GameWindow::GameWindow(LPCSTR wName, RECT wClientCoord)
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
	hInstance = window.hInstance;


	if (!RegisterClassEx(&window))
	{
		MessageBox(NULL, "FAIL rekisteri", "rekisteriFAIL", NULL);
	}

	AdjustWindowRectEx(&wClientCoord, WS_CAPTION, false, WS_EX_LEFT);

	hWnd = CreateWindowEx(WS_EX_LEFT, "GameWindowClass", wName, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, wClientCoord.left, wClientCoord.top, wClientCoord.right, wClientCoord.bottom, NULL, NULL, hInstance, NULL);
	ShowWindow(hWnd, SW_SHOWNORMAL);


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