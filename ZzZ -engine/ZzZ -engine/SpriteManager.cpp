#include "SpriteManager.h"


SpriteManager::SpriteManager()
{
}


SpriteManager::~SpriteManager()
{
}
void SpriteManager::newSprite(std::string name, float width, float height, int depth, unsigned char* spriteTexture)
{
	//Create a new sprite, allocate it into sprites vector and batch the sprites.
	Sprite* newSprite = new Sprite(name, width, height, depth, spriteTexture);
	sprites.push_back(newSprite);
	void batchSprites();
}
void SpriteManager::deleteSprite(std::string name)
{
	//Removes sprites of given name, then batches the sprites.
	for (int i = 0; i < sprites.size(); i++)
	{
		if (name == sprites[i]->getName())
			sprites.erase(sprites.begin() + i);

		i--;
	}

	void batchSprites();
}
bool SpriteSort(Sprite* A, Sprite* B)
{
	//Help function for sort
	if (A->getDepth() == B->getDepth())
		return A->getTexture() < B->getTexture();
	else
		return A->getDepth() < B->getDepth();
}
void SpriteManager::batchSprites()
{
	std::sort(sprites.begin(), sprites.end(), SpriteSort);
}
std::vector<float> SpriteManager::getVertexArray()
{
	std::vector<float> vertices;
	for (int i = 0; i < sprites.size(); i++)
	{
		vertices.insert(vertices.end(), sprites[i]->vertices, sprites[i]->vertices + 28);
	}
	return vertices;
}
std::vector<unsigned char*> SpriteManager::getTexturesArray()
{
	std::vector<unsigned char*> textures;
	for (int i = 0; i < sprites.size(); i++)
	{
		textures.push_back(sprites[i]->getTexture());
	}
	return textures;
}