#ifndef DEVICE_H
#define DEVICE_H

#include "Buffer.h"
#include "debugger.h"
#include "GameWindow.h"
#include "ResourceManager.h"
#include "Shader.h"
#include "SpriteManager.h"
#include "Input.h"


namespace ZZZ
{
	class Device
	{
	public:
		//Name for the window and the size of the window
		void initialize(std::string wName, RECT wClientCoord);
		//Name for the window and the size of the window
		void initialize(std::string wName, int width, int height);
		// values between 0 and 255
		void setBackgroundColor(float red, float green, float blue);
		Texture* loadTexture(std::string textureName);
		void update();

		Input input;
		bool isRunning;

	private:
		void createBuffers();
		void createShader(RECT windowCoordinates);

		float backgroundColor[4];
		GameWindow* gameWindow;
		Buffer verticeBuffer;
		Buffer indexBuffer;
		MSG msg;
	};
}
#endif