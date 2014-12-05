#pragma once
#include <string.h>
#include <stdio.h>
#include <vector>
#include "debugger.h"
#include "Texture.h"
#include "Buffer.h"
#include "Shader.h"
#include <math.h>

namespace ZZZ
{
	class Sprite
	{
	public:
		Sprite(ZZZ::Texture* spriteTexture, float spriteWidth, float spriteHeight);
		~Sprite();
		// Moves sprite by given ammount
		void moveSprite(float x, float y);
		// Sets absolute position according to upper left corner
		void setPosition(float x, float y);
		// Changes the common Scale
		void setScale(float spriteScale);
		// Changes the scale of width and height separately
		void setScale(float x, float y);
		// Rotates the sprite
		void rotate(float angleInDegrees);
		// Changes the rotation to absolute value
		void setRotation(float angleInDegrees);
		// Changes the Texture used
		void setTexture(ZZZ::Texture* spriteTexture);
		// Changes coordinates for the edges of the sprite
		void setTextureCoordinates(float left, float top, float right, float bottom);
		// Higher depth sprites are drawn first
		void setLayerDepth(int layerDepth);
		// Used by SpriteManager
		void setID(int spriteID){ id = spriteID; }
		// Colour values between 0 and 255
		void setColour(float red, float green, float blue);
		
		ZZZ::Texture* getTexture();
		int getDepth();
		int getID() { return id; };
		float getLeft();
		float getTop();
		float getRight();
		float getBottom();
		
		const bool contains(float x, float y);
		const bool intersects(Sprite* collider);
		void draw(ZZZ::Buffer* vertexBuffer, ZZZ::Buffer* indiceBuffer);

		float vertices[28];
		unsigned int indices[6];
		
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
		int depth, id;
		ZZZ::Texture* texture;
		float scale, scaleX, scaleY;
		float width, height;
		float originX, originY;
		float currentAngle;

	};

}