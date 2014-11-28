#pragma once
#include "Sprite.h"
#include "Texture.h"
#include <vector>
#include <algorithm>
#include "Buffer.h"
namespace ZZZ
{
	class SpriteManager
	{
	public:

		static SpriteManager* instance();
		
		//Create a new sprite and add it to sprites vector
		void newSprite(Sprite* sprite);
		//Remove all sprites of given name from sprites vector
		void deleteSprite(int spriteID);
		//Ask all sprites to draw themselfs
		void SpriteManager::drawSprites(ZZZ::Buffer* vertexBuffer, ZZZ::Buffer* indiceBuffer);
		//Return handle to a sprite
		Sprite* getSprite(int spriteID);
		void batchSprites();
		////Ei tarvita uudella tyylill‰
		////Getters for vectors of specific attribute from all sprites.
		//std::vector<float> getVerticesVector();
		//std::vector<unsigned int> getIndicesVector();
		//std::vector<ZZZ::Texture*> getTexturesVector();
	protected:
		SpriteManager();
		~SpriteManager();

	private:

		static SpriteManager* instanceObj;
		std::vector<Sprite*> sprites;
		int nextID;
		//spritejen batchaaminen
	};

	/*
	Miten t‰m‰ toimii t‰ll‰ hetkell‰?
	Kun luodaan uusi sprite, se lis‰t‰‰n sprites vectoriin.
	Jos spritej‰ poistetaan, ne etsit‰‰n ID:n perusteella ja poistetaan kyseinen sprite.
	Kun spritej‰ lis‰t‰‰n tai poistetaan, j‰rkestet‰‰n spritet ensin syvyyden, sitten texturen mukaan.
	Nyt sprite vectorin voi piirt‰‰ j‰rjestyksess‰, ensin kaikki pohjalla olevat spritet textuuri j‰rjestyksess‰.
	N‰in edet‰‰n kunnes kaikki spritet on piirretty, syvyys kerrallaan.
	*/
}