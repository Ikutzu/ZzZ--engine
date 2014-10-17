#pragma once
#include <string.h>
#include <stdio.h>
#include "debugger.h"
class Sprite
{
public:
	Sprite(float width, float height);
	~Sprite();
	void moveSprite(float x, float y);
	void setPosition(float x, float y);
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
	*/

	float vertices[28];

};

