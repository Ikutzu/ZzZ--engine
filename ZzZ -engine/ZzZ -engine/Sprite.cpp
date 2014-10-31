#include "Sprite.h"


Sprite::Sprite(std::string spriteName, float spriteWidth, float spriteHeight, int layerDepth, unsigned char* spriteTexture)
{
	float base = 1;
	width = spriteWidth;
	height = spriteHeight;
	name = spriteName;
	depth = layerDepth;
	vertices[0] = 0.0f; //x
	vertices[1] = base * height; //y
	vertices[2] = 1.0f; //red
	vertices[3] = 1.0f; //green
	vertices[4] = 1.0f; //blue
	vertices[5] = 0.0f; //tex x
	vertices[6] = 1.0f; //tex y
	vertices[7] = 0.0f; //x
	vertices[8] = 0.0f; //y
	vertices[9] = 1.0f; //red
	vertices[10] = 1.0f; //green
	vertices[11] = 1.0f; //blue
	vertices[12] = 0.0f; //tex x 
	vertices[13] = 0.0f; //tex y
	vertices[14] = base * width; //x
	vertices[15] = base * height; //y
	vertices[16] = 1.0f; //red
	vertices[17] = 1.0f; //green
	vertices[18] = 1.0f; //blue
	vertices[19] = 1.0f; //tex x
	vertices[20] = 1.0f; //tex y
	vertices[21] = base * width; //x
	vertices[22] = 0.0f; //y
	vertices[23] = 1.0f; //red
	vertices[24] = 1.0f; //green
	vertices[25] = 1.0f; //blue
	vertices[26] = 1.0f; //tex x
	vertices[27] = 0.0f; //tex y
	texture = spriteTexture;

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 3;

	originX = width / 2;
	originY = height / 2;

}


Sprite::~Sprite()
{
}

void Sprite::moveSprite(float x, float y)
{
	//How does it work?
	//Move all of the vertices by values set
	vertices[0] += x;
	vertices[7] += x;
	vertices[14] += x;
	vertices[21] += x;
	vertices[1] += y;
	vertices[8] += y;
	vertices[15] += y;
	vertices[22] += y;

	originX += x;
	originY += y;
}
void Sprite::setPosition(float x, float y)
{
	// How does it work?
	// set position to 0.0
	// then set position to wanted values;

	vertices[0] -= vertices[0];
	vertices[7] -= vertices[0];
	vertices[14] -= vertices[0];
	vertices[21] -= vertices[0];
	vertices[1] -= vertices[22];
	vertices[8] -= vertices[22];
	vertices[15] -= vertices[22];
	vertices[22] -= vertices[22];
	originX -= vertices[0];
	originY -= vertices[22];

	vertices[0] += x;
	vertices[7] += x;
	vertices[14] += x;
	vertices[21] += x;
	vertices[1] += y;
	vertices[8] += y;
	vertices[15] += y;
	vertices[22] += y;
	originX += x;
	originY += y;
}
void Sprite::setScale(float spriteScale)
{
	scale = spriteScale;
	float tempWidth = width*scale;
	float tempHeight = height*scale;
	vertices[1] = scale * height; //y

	vertices[14] = scale * width; //x
	vertices[15] = scale * height; //y

	vertices[21] = scale * width; //x
}

std::string Sprite::getName()
{
	return name;
}
void Sprite::setTexture(unsigned char* spriteTexture)
{
	texture = spriteTexture;

}
int Sprite::getDepth()
{
	return depth;
}
unsigned char* Sprite::getTexture()
{
	return texture;
}