#include "Sprite.h"

using namespace ZZZ;

Sprite::Sprite(std::string spriteName, float spriteWidth, float spriteHeight, ZZZ::Texture* spriteTexture, int spriteID)
{
	
	float base = 1;
	scale = 1;
	depth = 1;
	id = spriteID;
	width = spriteWidth;
	height = spriteHeight;
	name = spriteName;
	
	//Vertex 1
	vertices[0] = 0.0f; //x
	vertices[1] = base * height; //y
	vertices[2] = 0.0f; //red
	vertices[3] = 0.0f; //green
	vertices[4] = 0.0f; //blue
	vertices[5] = 0.0f; //tex x
	vertices[6] = 1.0f; //tex y
	//Vertex 2
	vertices[7] = 0.0f; //x
	vertices[8] = 0.0f; //y
	vertices[9] = 0.0f; //red
	vertices[10] = 0.0f; //green
	vertices[11] = 0.0f; //blue
	vertices[12] = 0.0f; //tex x 
	vertices[13] = 0.0f; //tex y
	//Vertex 3
	vertices[14] = base * width; //x
	vertices[15] = base * height; //y
	vertices[16] = 0.0f; //red
	vertices[17] = 0.0f; //green
	vertices[18] = 0.0f; //blue
	vertices[19] = 1.0f; //tex x
	vertices[20] = 1.0f; //tex y
	//vertex 4
	vertices[21] = base * width; //x
	vertices[22] = 0.0f; //y
	vertices[23] = 0.0f; //red
	vertices[24] = 0.0f; //green
	vertices[25] = 0.0f; //blue
	vertices[26] = 1.0f; //tex x
	vertices[27] = 0.0f; //tex y

	texture = spriteTexture;

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 2;
	indices[4] = 1;
	indices[5] = 3;

	originX = width / 2;
	originY = height / 2;

}


Sprite::~Sprite()
{
}
void Sprite::setLayerDepth(int layerDepth)
{
	depth = layerDepth;
}

void Sprite::moveSprite(float x, float y)
{
	//Move the vertex by given value
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
	//Set absolute position for the sprite

	vertices[7] -= vertices[0];
	vertices[14] -= vertices[0];
	vertices[21] -= vertices[0];
	vertices[1] -= vertices[22];
	vertices[8] -= vertices[22];
	vertices[15] -= vertices[22];
	originX -= vertices[0];
	originY -= vertices[22];
	vertices[0] -= vertices[0];
	vertices[22] -= vertices[22];

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
	//Scales the sprite
	scale = spriteScale;
	vertices[1] = vertices[8] + (scale * height); //y

	vertices[14] = vertices[7] + (scale * width); //x
	vertices[15] = vertices[8] + (scale * height); //y

	vertices[21] = vertices[7] + (scale * width); //x

	originX = width / 2 * scale;
	originY = height / 2 * scale;
}
void Sprite::rotate(float angleInDegrees)
{
	//Rotates the sprite
	float conv = angleInDegrees * 3.13159265 / 180;
	float rotationMatrix[2][2] = { { cos(conv), sin(conv) }, { -sin(conv), cos(conv) } };
	float vertex1[2] = { vertices[0] - originX, vertices[1] - originY };
	float vertex2[2] = { vertices[7] - originX, vertices[8] - originY };
	float vertex3[2] = { vertices[14] - originX, vertices[15] - originY };
	float vertex4[2] = { vertices[21] - originX, vertices[22] - originY };

	float x = 1;
	float y = 1;

	//Vertex 1
	x = ((vertex1[0] * rotationMatrix[0][0]) - (vertex1[1] * rotationMatrix[0][1]));
	y = ((vertex1[0] * rotationMatrix[1][0]) - (vertex1[1] * rotationMatrix[1][1]));
	vertices[0] = x;// +originX;
	vertices[1] = y;// +originY;
	//Vertex 2
	x = ((vertex2[0] * rotationMatrix[0][0]) - (vertex2[1] * rotationMatrix[0][1]));
	y = ((vertex2[0] * rotationMatrix[1][0]) - (vertex2[1] * rotationMatrix[1][1]));
	vertices[7] = x;// +originX;
	vertices[8] = y;// +originY;
	//Vertex 3
	x = ((vertex3[0] * rotationMatrix[0][0]) - (vertex3[1] * rotationMatrix[0][1]));
	y = ((vertex3[0] * rotationMatrix[1][0]) - (vertex3[1] * rotationMatrix[1][1]));
	vertices[14] = x;// +originX;
	vertices[15] = y;// +originY;
	//Vertex 4
	x = ((vertex4[0] * rotationMatrix[0][0]) - (vertex3[1] * rotationMatrix[0][1]));
	y = ((vertex4[0] * rotationMatrix[1][0]) - (vertex3[1] * rotationMatrix[1][1]));
	vertices[21] = x;// +originX;
	vertices[22] = y;// +originY;
}
void Sprite::setRotation(float angleInDegrees)
{
	//Sets absolute rotation for the sprite.
	float rotationMatrix[2][2] = { { cosf(angleInDegrees), sinf(angleInDegrees) }, { -sinf(angleInDegrees), cosf(angleInDegrees) } };
	float vertex1[2] = { (-width / 2) * scale, (-height / 2) * scale };
	float vertex2[2] = { (-width / 2) * scale, (height / 2) * scale };
	float vertex3[2] = { (width / 2) * scale, (-height / 2) * scale };
	float vertex4[2] = { (width / 2) * scale, (height / 2) * scale };

	float x, y;

	//Vertex 1
	x = ((vertex1[1] * rotationMatrix[1][1]) - (vertex1[2] * rotationMatrix[1][2]));
	y = ((vertex1[1] * rotationMatrix[2][1]) - (vertex1[2] * rotationMatrix[2][2]));
	vertices[0] = x + originX;
	vertices[1] = y + originY;
	//Vertex 2
	x = ((vertex2[1] * rotationMatrix[1][1]) - (vertex2[2] * rotationMatrix[1][2]));
	y = ((vertex2[1] * rotationMatrix[2][1]) - (vertex2[2] * rotationMatrix[2][2]));
	vertices[7] = x + originX;
	vertices[8] = y + originY;
	//Vertex 3
	x = ((vertex3[1] * rotationMatrix[1][1]) - (vertex3[2] * rotationMatrix[1][2]));
	y = ((vertex3[1] * rotationMatrix[2][1]) - (vertex3[2] * rotationMatrix[2][2]));
	vertices[14] = x + originX;
	vertices[15] = y + originY;
	//Vertex 4
	x = ((vertex4[1] * rotationMatrix[1][1]) - (vertex4[2] * rotationMatrix[1][2]));
	y = ((vertex4[1] * rotationMatrix[2][1]) - (vertex4[2] * rotationMatrix[2][2]));
	vertices[21] = x + originX;
	vertices[22] = y + originY;

}


std::string Sprite::getName()
{
	return name;
}
void Sprite::setTexture(ZZZ::Texture* spriteTexture)
{
	texture = spriteTexture;

}
int Sprite::getDepth()
{
	return depth;
}
ZZZ::Texture* Sprite::getTexture()
{
	return texture;
}

void Sprite::draw(ZZZ::Buffer* vertexBuffer, ZZZ::Buffer* indiceBuffer)
{
	vertexBuffer->pushData(sizeof(vertices), &vertices);
	indiceBuffer->pushData(sizeof(indices), &indices);
	
	glBindBuffer(GL_ARRAY_BUFFER, *vertexBuffer->getIndex());
	ZZZ::Shader::useShader();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *indiceBuffer->getIndex());
	glBindTexture(GL_TEXTURE_2D, *texture->getIndex());

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, reinterpret_cast<GLvoid*>(0));
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	Debugger::checkGLError("draw");
}