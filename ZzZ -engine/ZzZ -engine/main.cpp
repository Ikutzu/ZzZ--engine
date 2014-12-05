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
	semmone.left = 0;
	semmone.top = 0;
	semmone.bottom = 600;
	semmone.right = 800;

	ZZZ::Device testi;
	testi.initialize("akkuna", semmone);
	testi.update();
	testi.setBackgroundColor(0.0f, 0.5f, 0.0f);

	Timer timer = Timer(millisecond);
	
	Texture zzzTexture("lode_test_in");
	Texture koalaTexture("koala");
	Texture boobs("boobs");
	Texture explosions("explosions");

	Sprite sprite1(&zzzTexture, 300, 450);
	sprite1.setLayerDepth(2);
	std::vector<Sprite*> koalaFarmi;

	float angle = 0;
	float move = 0;
	float scale = 1;
	while (testi.isRunning)
	{
		//start timer
		timer.startDeltaTime();

		angle = 0.03 * timer.getDeltaTime();
		move = 0.1 * timer.getDeltaTime();
		
		//Move Up
		if (testi.input.isKeyDown(Key::W))
		{
			sprite1.moveSprite(0.0f, -move);
		}

		//Move Left
		if (testi.input.isKeyDown(Key::A))
		{
			sprite1.moveSprite(-move, 0.0f);
		}

		//Move Down
		if (testi.input.isKeyDown(Key::S))
		{
			sprite1.moveSprite(0.0f, move);
		}

		//Move Right
		if (testi.input.isKeyDown(Key::D))
		{
			sprite1.moveSprite(move, 0.0f);
		}

		//Rotate Counterclockwise
		if (testi.input.isKeyDown(Key::Q))
		{
			sprite1.rotate(angle);
		}

		//Rotate Clockwise
		if (testi.input.isKeyDown(Key::E))
		{
			sprite1.rotate(-angle);
		}

		//Scale Up
		if (testi.input.isKeyDown(Key::R))
		{
			scale += 0.01;
			sprite1.setScale(scale);
		}

		//Scale Down
		if (testi.input.isKeyDown(Key::F))
		{
			scale -= 0.01;
			sprite1.setScale(scale);
		}

		//Previous Texture
		if (testi.input.isKeyPressed(Key::Z))
		{
			if (sprite1.getTexture() == &zzzTexture)
			{
				sprite1.setTexture(&boobs);
			}
			else if (sprite1.getTexture() == &boobs)
			{
				sprite1.setTexture(&explosions);
			}
			else if (sprite1.getTexture() == &explosions)
			{
				sprite1.setTexture(&zzzTexture);
			}
		}

		//Next Texture
		if (testi.input.isKeyPressed(Key::X))
		{
			if (sprite1.getTexture() == &zzzTexture)
			{
				sprite1.setTexture(&explosions);
			}
			else if (sprite1.getTexture() == &boobs)
			{
				sprite1.setTexture(&zzzTexture);
			}
			else if (sprite1.getTexture() == &explosions)
			{
				sprite1.setTexture(&boobs);
			}
		}

		//Spawn Koala
		if (testi.input.isKeyPressed(Key::C))
		{
			int x = std::rand() % 600;
			int y = std::rand() % 800;
			float tx = std::rand() % 512;
			float ty = std::rand() % 512;
			Sprite* koala = new Sprite(&koalaTexture, 128, 128);
			koala->setPosition(x, y);
			koala->setTextureCoordinates(0.0f, 0.0f, tx, ty);
			koalaFarmi.push_back(koala);
	
		}

		//Despawn Koala
		if (testi.input.isKeyPressed(Key::MouseLeft))
		{
			int dii = 0;
			for (std::vector<Sprite*>::iterator i = koalaFarmi.begin(); i < koalaFarmi.end(); i++)
			{
				if (koalaFarmi[dii]->contains(testi.input.getCursorPos().x, testi.input.getCursorPos().y))
				{
					Debugger::Print("Ny");
					delete koalaFarmi.at(dii);
				}
				dii++;
			}
		}












		testi.input.update();
		//Do-things
		testi.update();
		timer.setDeltaTime();
	}

	return 0;
}
