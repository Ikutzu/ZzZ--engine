#pragma once
#include "Sprite.h"
#include "Texture.h"
#include <vector>
#include <algorithm>
#include "Buffer.h"
class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	//Create a new sprite and add it to sprites vector
	void newSprite(std::string name, float width, float height, ZZZ::Texture* spriteTexture);
	//Remove all sprites of given name from sprites vector
	void deleteSprite(std::string name);
	//Getters for vectors of specific attribute from all sprites.
	std::vector<float> getVerticesVector();
	std::vector<unsigned int> getIndicesVector();
	std::vector<ZZZ::Texture*> getTexturesVector();
	void SpriteManager::drawSprites(ZZZ::Buffer* vertexBuffer, ZZZ::Buffer* indiceBuffer);

private:
	std::vector<Sprite*> sprites;

	//spritejen batchaaminen
	void batchSprites();
};

/*
Miten t‰m‰ toimii t‰ll‰ hetkell‰?
Kun luodaan uusi sprite, se lis‰t‰‰n sprites vectoriin.
Jos spritej‰ poistetaan, ne etsit‰‰n nimen perusteella ja poistetaan kaikki sen nimiset spritet.
Kun spritej‰ lis‰t‰‰n tai poistetaan, j‰rkestet‰‰n spritet ensin syvyyden, sitten texturen mukaan.
Nyt sprite vectorin voi piirt‰‰ j‰rjestyksess‰, ensin kaikki pohjalla olevat spritet textuuri j‰rjestyksess‰.
N‰in edet‰‰n kunnes kaikki spritet on piirretty, syvyys kerrallaan.
*/