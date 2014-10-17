#include "SpriteManager.h"


SpriteManager::SpriteManager()
{
}


SpriteManager::~SpriteManager()
{
}
void SpriteManager::newSprite(std::string name, float width, float height, int depth)
{
	sprites.push_back(Sprite(name, width, height, depth));

	void batchSprites();
}
void SpriteManager::deleteSprite(std::string name)
{
	for (int i = 0; i < sprites.size(); i++)
	{
		if (name == sprites[i].getName)
			sprites.erase(sprites.begin + i);

		i--;
	}

	void batchSprites();
}
void SpriteManager::batchSprites()
{
	std::sort(sprites.begin(), sprites.end(), SpriteSort);
}

bool SpriteSort(const Sprite& A, const Sprite& B)
{
	if (A.getDepth == B.getDepth)
		return A.getTexture < B.getTexture;
	else
		return A.getDepth < B.getDepth;
}