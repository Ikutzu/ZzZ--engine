#include "SpriteManager.h"


SpriteManager::SpriteManager()
{
	nextID = 0;
}


SpriteManager::~SpriteManager()
{
}
int SpriteManager::newSprite(std::string name, float width, float height, ZZZ::Texture* spriteTexture)
{
	//Create a new sprite, allocate it into sprites vector and batch the sprites.
	//Sprite* newSprite = new Sprite(name, width, height, spriteTexture);
	//batchSprites();
	nextID++;
	sprites.push_back(new Sprite(name, width, height, spriteTexture, nextID));
	return nextID;
}
void SpriteManager::deleteSprite(int spriteID)
{
	//Removes sprites of given name, then batches the sprites.
	for (int i = 0; i < sprites.size(); i++)
	{
		if (spriteID == sprites[i]->getID())
			sprites.erase(sprites.begin() + i);

		i--;
	}

	//batchSprites();
}

void SpriteManager::drawSprites(ZZZ::Buffer* vertexBuffer, ZZZ::Buffer* indiceBuffer)
{
	for (int i = 0; i < sprites.size(); i++)
	{
		sprites[i]->draw(vertexBuffer, indiceBuffer);
	}
}
////Ei tarvita uudella tyylill�
//bool SpriteSort(Sprite* A, Sprite* B)
//{
//	//Help function for sort
//	if (A->getDepth() == B->getDepth())
//		return A->getTexture() < B->getTexture();
//	else
//		return A->getDepth() < B->getDepth();
//}
//void SpriteManager::batchSprites()
//{
//	std::sort(sprites.begin(), sprites.end(), SpriteSort);
//}
//std::vector<float> SpriteManager::getVerticesVector()
//{
//	//Returns all vertices of all sprites
//	std::vector<float> vertices;
//	for (int i = 0; i < sprites.size(); i++)
//	{
//		vertices.insert(vertices.end(), sprites[i]->vertices, sprites[i]->vertices + 28);
//	}
//	return vertices;
//}
//std::vector<unsigned int> SpriteManager::getIndicesVector()
//{
//	//Returns all indices of all sprites.
//	std::vector<unsigned int> indices;
//	for (int i = 0; i < sprites.size(); i++)
//	{
//		indices.insert(indices.end(), sprites[i]->indices, sprites[i]->indices + 6);
//	}
//	return indices;
//}
//std::vector<ZZZ::Texture*> SpriteManager::getTexturesVector()
//{
//	//Returns all textures of all sprites
//	std::vector<ZZZ::Texture*> textures;
//	for (int i = 0; i < sprites.size(); i++)
//	{
//		textures.push_back(sprites[i]->getTexture());
//	}
//	return textures;
//}