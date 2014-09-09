#include <windows.h>
#include "GL/glew.h"
#include "lodepng.h"

#pragma comment (lib, "opengl32.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
bool Lode_test(const std::string& file_in, const std::string& file_out);

int WinMain(__in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd)
{
	MSG msg = { 0 };
	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
	wc.lpszClassName = L"oglversionchecksample";
	wc.style = CS_OWNDC;
	if (!RegisterClass(&wc))
		return 1;
	CreateWindowW(wc.lpszClassName, L"openglversioncheck", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, 640, 480, 0, 0, hInstance, 0);

	while (GetMessage(&msg, NULL, 0, 0) > 0)
		DispatchMessage(&msg);

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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

		HGLRC hglrc = wglCreateContext(hdc);

		wglMakeCurrent(hdc, hglrc);

		glewExperimental = TRUE;

		

		GLenum err = glewInit();
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
		if (Lode_test("lode_test_in.png", "lode_test_out.png"))
			MessageBoxA(0, "test passed", "LodePNG test", 0);
		else
			MessageBoxA(0, "test failed", "LodePNG test", 0);


		wglDeleteContext(hglrc);
		PostQuitMessage(0);

		break;
	}
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;

}



//decodes and re-encodes an image
bool Lode_test(const std::string& file_in, const std::string& file_out)
{
	std::vector<unsigned char> image;
	unsigned w, h;
	std::vector<unsigned char> buffer;
	lodepng::State state;
	unsigned error;

	lodepng::load_file(buffer, file_in);
	if (lodepng::decode(image, w, h, state, buffer))
		return false;

	buffer.clear();

	if (lodepng::encode(buffer, image, w, h, state))
		return false;
	lodepng::save_file(buffer, file_out);

	return true;
}