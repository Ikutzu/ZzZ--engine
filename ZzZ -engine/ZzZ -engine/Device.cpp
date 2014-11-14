#include "Device.h"

using namespace ZZZ;


void Device::initialize(std::string wName, RECT wClientCoord)
{
	gameWindow = new GameWindow(wName.c_str(), wClientCoord);
	rm = ResourceManager();
	input = Input();
	input.initialize(gameWindow->getWindowHandle());

	isRunning = true;

	backgroundColor[0] = 0.0f;
	backgroundColor[1] = 0.0f;
	backgroundColor[2] = 0.0f;
	backgroundColor[3] = 1.0f;

	createBuffers();
	createShader(wClientCoord);

	//siirretty mainista
	Texture testiTex(rm.load<TextureRes>("lode_test_in"));
	spriteManager.newSprite("testi", 50, 150, &testiTex);
}

void Device::update()
{
	glUseProgram(*Shader::getProgram());

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
	//verticeBuffer.pushData(sizeof(spriteManager.getVerticesVector()), &spriteManager.getVerticesVector());
	//indexBuffer.pushData(sizeof(spriteManager.getIndicesVector()), &spriteManager.getIndicesVector());


	glBindBuffer(GL_ARRAY_BUFFER, *verticeBuffer.getIndex());

	Shader::useShader();

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *indexBuffer.getIndex());

	drawElements();


	glBindBuffer(GL_ARRAY_BUFFER, 0u);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0u);

	SwapBuffers(gameWindow->hdc);
	
	glUseProgram(0u);

	//input test
	if (input.isKeyPressed(ZZZ::Key::A))
		Debugger::Print("Key pressed once: A");

	if (input.isKeyDown(Key::Space))
	{
		Debugger::Print("x ", input.getCursorPos().x);
		Debugger::Print("y ", input.getCursorPos().y);
	}

	input.update();
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

void Device::createShader(RECT windowCoordinates)
{
	if (Shader::newShader(nullptr, nullptr, windowCoordinates))
		Debugger::Print("Shader creation failed");
}

void Device::drawElements()
{
	/*
	std::vector<Texture*> textureVector = spriteManager.getTexturesVector();
	std::vector<Texture*>::iterator textureit;
	
	for (textureit = textureVector.begin(); textureit != textureVector.end(); textureit++)
//	for (int o = 0; 0 < textureVector->size(); o++)
	{
		int i = 0;
		//Kaatuu t�h�n
		if (textureit == textureVector.begin() || textureit != textureit - 1)
		{
			glBindTexture(GL_TEXTURE_2D, *(*textureit)->getIndex());
		}
		glDrawElements(GL_TRIANGLES, 6u, GL_UNSIGNED_INT, reinterpret_cast<GLvoid*>(24*i));

		i++;
	}
	*/
}