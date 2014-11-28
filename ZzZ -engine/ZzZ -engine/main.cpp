#include "Device.h"
#include "debugger.h"
#include "Shader.h"
#include "ResourceManager.h"
#include "Sprite.h"
#include "Timer.h"
#include <sstream>

static const int RM_TEST_SIZE = 50;
void resourceManagerTest();

using namespace ZZZ;

int main()
{
	//resourceManagerTest();

	RECT semmone;
	semmone.left = 40;
	semmone.top = 40;
	semmone.bottom = 600;
	semmone.right = 800;

	ZZZ::Device testi;
	testi.initialize("akkuna", semmone);
	testi.update();
	testi.setBackgroundColor(0.0f, 0.5f, 0.0f);

	Timer timer = Timer(millisecond);
	
	Texture testiTex("lode_test_in");
	Texture testi2Tex("KhorneMark");

	Sprite sprite1(&testiTex, 300, 450);
	Sprite sprite2(&testiTex, 400, 300);
	

	sprite1.setPosition(100,100);
	sprite1.setTexture(&testi2Tex);

	sprite2.setPosition(500, 100);

	std::vector<Sprite*> testilista;
	for (int i = 0; i < 10; i++)
		testilista.push_back(new Sprite(&Texture("Koala"), 128, 128));


	sprite1.setLayerDepth(2);

	ResourceManager::printAll();
	float angle = 0;
	while (testi.isRunning)
	{
		timer.startDeltaTime();

		// input testi, logiin ei saisi tulla kahtaa samaa rivi� per�kk�in
		if (testi.input.isKeyPressed(Key::A))
			Debugger::Print("pressed Key::A");
		if (testi.input.isKeyReleased(Key::A))
			Debugger::Print("released Key::A");

		// kursorin koordinaatit ikkunan suhteen
		if (testi.input.isKeyDown(Key::Space))
		{
			Debugger::Print("x ", testi.input.getCursorPos().x);
			Debugger::Print("y ", testi.input.getCursorPos().y);
		}

		// input pit�� p�ivitt�� mahdollisimman pian viimeisen input-kutsun j�lkeen
		testi.input.update();

		if (sprite1.intersects(&sprite2))
			Debugger::Print("Spritet t�rm��");
		else
			Debugger::Print("Spritet ei t�rm��");

		angle += 0.01 * timer.getDeltaTime();
		if (angle > 360)
			angle -= 360;
		sprite1.setRotation(angle);
		sprite2.setRotation(angle);

		//deltaTime indikaattori, mit� isompi dt, sit� kauemmas oikealle koalat piirtyv�t
		for (int i = 0; i < testilista.size(); i++)
			testilista.at(i)->setPosition(40 + i* timer.getDeltaTime(), 40);
		
		testi.update();
		timer.setDeltaTime();
	}
	for (int i = 0; i < testilista.size(); i++)
		delete testilista.at(i);
	testilista.clear();

	return 0;
}


//logiin pitaisi tulla 2*RM_TEST_SIZE kpl resursseja
//void resourceManagerTest()
//{
//	ZZZ::ResourceManager rm = ZZZ::ResourceManager();
//	ZZZ::TextureRes* t[RM_TEST_SIZE];
//	ZZZ::ShaderRes* s[RM_TEST_SIZE];
//	for (int i = 0; i < RM_TEST_SIZE; i++)
//	{
//		std::ostringstream ss;
//		ss << i;
//		t[i] = rm.load<ZZZ::TextureRes>(ss.str());
//		s[i] = rm.load<ZZZ::ShaderRes>(ss.str());
//	}
//	rm.printAll();
//}


//#ifndef WIN32_LEAN_AND_MEAN
//#define WIN32_LEAN_AND_MEAN
//#endif
//
//#include <windows.h>
//#include "GL/glew.h"
//#include "lodepng.h"
//#include "debugger.h"
//
//#pragma comment (lib, "opengl32.lib")
//
//LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//bool Lode_test(const std::string& file_in, const std::string& file_out);
//
//static HGLRC hglrc;
//
//
//int main()
//{
//	WNDCLASSEX window;
//
//	window.cbSize = sizeof(window);
//	window.style = CS_OWNDC;
//	window.lpfnWndProc = wndProc;
//	window.cbClsExtra = 0;
//	window.cbWndExtra = 0;
//	window.hInstance = GetModuleHandle(nullptr);
//	window.hIcon = NULL;
//	window.hCursor = NULL;
//	window.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);
//	window.lpszMenuName = NULL;
//	window.lpszClassName = "WindowClass";
//	window.hIconSm = NULL;
//
//	if (!RegisterClassEx(&window))
//	{
//		MessageBox(NULL, "FAIL rekisteri", "rekisteriFAIL", NULL);
//	}
//
//	RECT wRect;
//
//	wRect.top = 40;
//	wRect.left = 10;
//	wRect.right = 800;
//	wRect.bottom = 600;
//
//	AdjustWindowRectEx(&wRect, WS_CAPTION, false, WS_EX_LEFT);
//
//	HWND hWnd = CreateWindowEx(WS_EX_LEFT, "WindowClass", "Ikkuna", WS_CAPTION|WS_MINIMIZEBOX|WS_SYSMENU, wRect.left, wRect.top, wRect.right, wRect.bottom, NULL, NULL, window.hInstance, NULL);
//
//	ShowWindow(hWnd, SW_SHOWNORMAL);
//
//	MSG msg;
//	bool running = true;
//	while (running)
//	{
//		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
//		{
//			if (msg.message == WM_QUIT)
//			{
//				running = false;
//				break;
//			}
//			DispatchMessage(&msg);
//		}
//	}
//
//	Debugger::Print("All is well... for now!");
//
//	UnregisterClass("WindowClass", window.hInstance);
//
//
//
//	return 0;
//}
//
//
//LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//	switch (message)
//	{
//	case WM_CREATE:
//	{
//		PIXELFORMATDESCRIPTOR pfd =
//		{
//			sizeof(PIXELFORMATDESCRIPTOR),
//			1,
//			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
//			PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
//			32,                        //Colordepth of the framebuffer.
//			0, 0, 0, 0, 0, 0,
//			0,
//			0,
//			0,
//			0, 0, 0, 0,
//			24,                        //Number of bits for the depthbuffer
//			8,                        //Number of bits for the stencilbuffer
//			0,                        //Number of Aux buffers in the framebuffer.
//			PFD_MAIN_PLANE,
//			0,
//			0, 0, 0
//		};
//
//		HDC hdc = GetDC(hWnd);
//
//		int pixelCode = ChoosePixelFormat(hdc, &pfd);
//		SetPixelFormat(hdc, pixelCode, &pfd);
//
//		hglrc = wglCreateContext(hdc);
//
//		wglMakeCurrent(hdc, hglrc);
//
//		glewExperimental = TRUE;
//
//		
//
//		GLenum err = glewInit();
//		/*
//		if (GLEW_OK != err)
//		{
//			return 1;
//		}
//		
//		MessageBoxA(0, (char*)glGetString(GL_VERSION), "OPENGL VERSION", 0);
//		
//		if (GLEW_VERSION_2_1)
//		{
//			MessageBoxA(0, "2.1 SUPPORTED", "OPENGL VERSION", 0);
//		}
//		*/
//
//		//lodePNG test
//		if (!Lode_test("lode_test_in.png", "lode_test_out.png"))
//			MessageBoxA(0, "test failed", "LodePNG test", 0);
//
//		break;
//	}
//	case WM_DESTROY:
//	{
//		wglDeleteContext(hglrc);
//		PostQuitMessage(0);
//	}
//	default:
//		return DefWindowProc(hWnd, message, wParam, lParam);
//	}
//	return 0;
//
//}
//
//
//
////decodes and re-encodes an image
//bool Lode_test(const std::string& file_in, const std::string& file_out)
//{
//	std::vector<unsigned char> image;
//	unsigned w, h;
//	std::vector<unsigned char> buffer;
//	lodepng::State state;
//	unsigned error;
//
//	lodepng::load_file(buffer, file_in);
//	if (lodepng::decode(image, w, h, state, buffer))
//		return false;
//
//	buffer.clear();
//
//	if (lodepng::encode(buffer, image, w, h, state))
//		return false;
//	lodepng::save_file(buffer, file_out);
//
//	return true;
//}