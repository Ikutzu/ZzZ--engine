#include "Device.h"

using namespace ZZZ;


void Device::initialize(std::string wName, RECT wClientCoord)
{
	gameWindow = new GameWindow(wName.c_str(), wClientCoord);

	isRunning = true;

	backgroundColor[0] = 0.0f;
	backgroundColor[1] = 0.0f;
	backgroundColor[2] = 0.0f;
	backgroundColor[3] = 1.0f;

	createBuffers();
}

void Device::update()
{
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
	{
		if (msg.message == WM_QUIT)
		{
			isRunning = false;
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

	SwapBuffers(gameWindow->hdc);
}

void Device::setBackgroundColor(float red, float green, float blue)
{
	backgroundColor[0] = red;
	backgroundColor[1] = green;
	backgroundColor[2] = blue;
}

void Device::createBuffers()
{
	verticeBuffer.createBuffer(ZZZVERTEX);
	indexBuffer.createBuffer(ZZZINDEX);
}

void Device::createShader()
{
	if (Shader::newShader(nullptr, nullptr))
		Debugger::Print("Shader creation failed");
}