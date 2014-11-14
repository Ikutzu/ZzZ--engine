#pragma once
#include <string.h>
#include <stdio.h>
#include <vector>
#include "debugger.h"
#include "Texture.h"
#include "Buffer.h"
#include "Shader.h"

class Sprite
{
public:
	Sprite(std::string spriteName, float spriteWidth, float spriteHeight, ZZZ::Texture* spriteTexture);
	~Sprite();
	void moveSprite(float x, float y);
	void setPosition(float x, float y);
	void setScale(float spriteScale);
	void rotate(float angleInDegrees);
	void setRotation(float angleInDegrees);
	std::string getName();
	void setTexture(ZZZ::Texture* spriteTexture);
	ZZZ::Texture* getTexture();
	int getDepth();
	float vertices[28];
	unsigned int indices[6];
	void setLayerDepth(int layerDepth);
	void draw(ZZZ::Buffer* vertexBuffer, ZZZ::Buffer* indiceBuffer);

private:


	/* How the vertices work
	First 7 points are for first vertex.
	The first 2 values are position, x, y
	0.0f, 1.0f,
	The next 3 values are color.
	1.0f, 1.0f, 1.0f,
	The last 2 values are for textures.
	0.5f, -1.0f

	This is repeated 4 times for all the vertices.

	current vertex positions
	vertex 2	vertex 4
	vertex 1	vertex 3

	Indices are set as following:
	bottom left, top left, bottom right;
	bottom right, top left, top right;

	*/
	std::string name;
	int depth;
	ZZZ::Texture* texture;
	float scale;
	float width, height;
	float originX, originY;

};

