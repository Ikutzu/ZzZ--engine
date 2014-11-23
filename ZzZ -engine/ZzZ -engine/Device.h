#ifndef DEVICE_H
#define DEVICE_H

#include "Buffer.h"
#include "debugger.h"
#include "GameWindow.h"
#include "ResourceManager.h"
#include "Shader.h"
#include "SpriteManager.h"
#include "Input.h"
#include "Timer.h"


namespace ZZZ
{
	class Device
	{
	public:
		void initialize(std::string wName, RECT wClientCoord);
		void setBackgroundColor(float red, float green, float blue);
		Texture* loadTexture(std::string textureName);
		void update();
		float getDeltaTime() { return deltaTime; }

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
		Timer timer;
		float deltaTime;
	};
}
#endif