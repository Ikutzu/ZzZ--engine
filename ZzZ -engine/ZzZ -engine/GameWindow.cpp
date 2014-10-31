#include "GameWindow.h"
#include "Shader.h"
//#include "GL\glew.h"


using namespace ZZZ;

GameWindow* GameWindow::wStack[];
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

	backgroundColor[0] = 0.0f;
	backgroundColor[1] = 0.0f;
	backgroundColor[2] = 0.0f;
	backgroundColor[3] = 1.0f;

	if (Shader::newShader(nullptr, nullptr))
		Debugger::Print("Shader creation failed");

	verticeBuffer.createBuffer(ZZZVERTEX);
	indexBuffer.createBuffer(ZZZINDEX);
		
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

	wStack[0] = new GameWindow(window, wName, wClientCoord);

	return *wStack[0];
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

	glClearColor(backgroundColor[0], backgroundColor[1], backgroundColor[2], backgroundColor[3]);
	glClear(GL_COLOR_BUFFER_BIT);

	// kutsu juttuja esim buffer.pushData ja piirrot
	glBindBuffer(GL_ARRAY_BUFFER, *verticeBuffer.getIndex());
	
	Shader::useShader();

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *indexBuffer.getIndex());

	//
	
	glBindBuffer(GL_ARRAY_BUFFER, 0u);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0u);

	SwapBuffers(hdc);

}

void GameWindow::setBackgroundColor(float red, float green, float blue)
{
	backgroundColor[0] = red;
	backgroundColor[1] = green;
	backgroundColor[2] = blue;
	
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