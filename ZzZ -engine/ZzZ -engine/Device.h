#ifndef DEVICE_H
#define DEVICE_H

#include "Buffer.h"
#include "debugger.h"
#include "GameWindow.h"
#include "ResourceManager.h"
#include "Shader.h"
#include "SpriteManager.h"


namespace ZZZ
{
	class Device
	{
	public:

		void initialize(std::string wName, RECT wClientCoord);

		void update();

		void setBackgroundColor(float red, float green, float blue);


		bool isRunning;

		SpriteManager spriteManager;

	private:

		void createBuffers();
		void createShader(RECT windowCoordinates);

		void drawElements();


		float backgroundColor[4];

		GameWindow* gameWindow;

		Buffer verticeBuffer;
		Buffer indexBuffer;

		MSG msg;

		ResourceManager rm;
	};
}
#endif