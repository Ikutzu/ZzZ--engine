#include "SpriteManager.h"


SpriteManager::SpriteManager()
{
}


SpriteManager::~SpriteManager()
{
}
void SpriteManager::newSprite(std::string name, float width, float height)
{
	sprites.push_back(Sprite(name, width, height));
}
void SpriteManager::deleteSprite(std::string name)
{
	for (int i = 0; i < sprites.size(); i++)
	{
		if (name == sprites[i].getName)
			sprites.erase(sprites.begin + i);

		i--;
	}
}