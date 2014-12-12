#include "zzzEngine.h"
using namespace ZZZ;

int main()
{
	static const int winW = 1024;
	static const int winH = 768;
	
	ZZZ::Device testi;
	testi.initialize("ZZZ Engine - Demo", winW, winH);
	testi.update();
	testi.setBackgroundColor(0.0f, 125.0f, 0.0f);

	Timer timer = Timer(millisecond);

	Texture zzzTexture("lode_test_in");
	Texture koalaTexture("koala");
	Texture boobs("boobs");
	Texture explosions("explosions");

	Sprite sprite1(&zzzTexture, 300, 450);
	sprite1.setPosition(winW*0.5f - 300*0.5f, winH*0.5f - 450*0.5f);
	sprite1.setLayerDepth(2);
	std::vector<Sprite*> koalaFarmi;

	float angle = 0;
	float move = 0;
	float scale = 1;
	while (testi.isRunning)
	{
		//start timer
		timer.startDeltaTime();

		angle = 0.06 * timer.getDeltaTime();
		move = 0.3 * timer.getDeltaTime();

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
			scale += 0.001 * timer.getDeltaTime();
			sprite1.setScale(scale);
		}

		//Scale Down
		if (testi.input.isKeyDown(Key::F))
		{
			scale -= 0.001 * timer.getDeltaTime();
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
			float r = std::rand() % 255;
			float g = std::rand() % 255;
			float b = std::rand() % 255;
			Sprite* koala = new Sprite(&koalaTexture, 128, 128);
			koala->setPosition(x, y);
			koala->setTextureCoordinates(0.0f, 0.0f, tx, ty);
			koala->setColour(r, g, b);
			koalaFarmi.push_back(koala);

		}

		//Despawn Koala
		if (testi.input.isKeyPressed(Key::MouseLeft))
		{
			std::vector<Sprite*>::iterator i;
			for (i = koalaFarmi.begin(); i != koalaFarmi.end();)
			{
				if ((*i)->contains(testi.input.getCursorPos().x, testi.input.getCursorPos().y))
				{
					delete *i;
					i = koalaFarmi.erase(i);
				}
				else
					i++;
			}
			koalaFarmi.shrink_to_fit();
		}

		//Remove all Koalas
		if (testi.input.isKeyPressed(Key::T))
		{
			for (std::vector<Sprite*>::iterator i = koalaFarmi.begin(); i != koalaFarmi.end(); i++)
				delete *i;
			koalaFarmi.clear();
		}


		if (testi.input.isKeyPressed(Key::MouseMiddle))
		{

			float r = std::rand() % 255;
			float g = std::rand() % 255;
			float b = std::rand() % 255;
			testi.setBackgroundColor(r, g, b);

		}
		{
			int x = std::rand() % (winW - 128);
			int y = std::rand() % (winH - 128);
			float tx = std::rand() % 512;
			float ty = std::rand() % 512;
			float r = std::rand() % 255;
			float g = std::rand() % 255;
			float b = std::rand() % 255;
			Sprite* koala = new Sprite(&koalaTexture, 128, 128);
			koala->setPosition(x, y);
			koala->setTextureCoordinates(0.0f, 0.0f, tx, ty);
			koala->setColour(r, g, b);
			koalaFarmi.push_back(koala);
		}
		int joku = koalaFarmi.size();
		char jokuc[128];
		itoa(joku, jokuc, 10);
		std::string vittunytoikeasti = jokuc;
		vittunytoikeasti += "\n";
		OutputDebugString(vittunytoikeasti.c_str());


		testi.input.update();
		//Do-things
		testi.update();
		timer.setDeltaTime();
		_CrtCheckMemory();
	}

	return 0;
}