#pragma once
#include <vector>
#include "Sprite.h"
#include <algorithm>
class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	//Luo uusi sprite ja lis‰‰ se sprites vectoriin
	void newSprite(std::string name, float width, float height, int depth, unsigned char* spriteTexture);
	//K‰y sprites vectori l‰pi ja poista halutun nimiset spritet.
	void deleteSprite(std::string name);
private:
	std::vector<Sprite> sprites;

	//spritejen patchaamiseen tarvittavat funktiot
	bool SpriteSort(Sprite& a, Sprite &b);
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