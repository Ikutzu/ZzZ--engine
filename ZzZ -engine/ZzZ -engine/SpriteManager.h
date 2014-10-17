#pragma once
#include <vector>
#include "Sprite.h"
class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();
	void newSprite(std::string name, float width, float height);
	void deleteSprite(std::string name);
private:
	std::vector<Sprite> sprites;
};

