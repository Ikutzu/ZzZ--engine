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
	
	Texture testiTex("lode_test_in");
	Sprite sprite1(&testiTex, 300, 450);

	float angle = 0;
	while (testi.isRunning)
	{
		timer.startDeltaTime();

		// kursorin koordinaatit ikkunan suhteen
		if (testi.input.isKeyDown(Key::Space))
		{
		}

		// input pit�� p�ivitt�� mahdollisimman pian viimeisen input-kutsun j�lkeen
		testi.input.update();

		angle += 0.01 * timer.getDeltaTime();
		if (angle > 360)
			angle -= 360;
		sprite1.setRotation(angle);


		if (testi.input.isKeyPressed(Key::Space))
		{
		}

		testi.update();
		timer.setDeltaTime();
	}

	return 0;
}
