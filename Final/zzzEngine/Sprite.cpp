#include "Sprite.h"
#include "SpriteManager.h"

using namespace ZZZ;

Sprite::Sprite(ZZZ::Texture* spriteTexture,float spriteWidth, float spriteHeight)
{
	
	float base = 1;
	scale = 1;
	scaleX = 1;
	scaleY = 1;
	depth = 1;
	width = spriteWidth;
	height = spriteHeight;
	currentAngle = 0;
	
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

	SpriteManager::instance()->newSprite(this);
}


Sprite::~Sprite()
{
	SpriteManager::instance()->deleteSprite(this->getID());
}
void Sprite::setLayerDepth(int layerDepth)
{
	depth = layerDepth;
	SpriteManager::instance()->batchSprites();
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
	scale = spriteScale;
	vertices[0] = originX - width / 2 * scale * scaleX;
	vertices[1] = originY + height / 2 * scale * scaleY;
	vertices[7] = originX  - width / 2 * scale * scaleX;
	vertices[8] = originY - height / 2 * scale * scaleY;
	vertices[14] = originX + width / 2 * scale * scaleX;
	vertices[15] = originY + height / 2 * scale * scaleY;
	vertices[21] = originX + width / 2 * scale * scaleX;
	vertices[22] = originY  - height / 2 * scale * scaleY;
	setRotation(currentAngle);
}
void Sprite::setScale(float x, float y)
{
	//Scales the sprite
	scaleX = x;	
	scaleY = y;
	setScale(scale);
	
}
void Sprite::rotate(float angleInDegrees)
{
	//Rotates the sprite
	//Rotates counter clockwise.
	currentAngle += angleInDegrees;
	setRotation(currentAngle);
}
void Sprite::setRotation(float angleInDegrees)
{

	//Sets absolute rotation for the sprite.
	//Rotates counter clockwise.
	float conv = angleInDegrees * 3.14159265 / 180;
	float rotationMatrix[2][2] = { { cos(conv), sin(conv) }, { -sin(conv), cos(conv) } };
	float vertex1[2] = { -width * scaleX * scale / 2, -height * scaleY * scale / 2 };
	float vertex2[2] = { -width * scaleX * scale / 2, height * scaleY * scale / 2 };
	float vertex3[2] = { width * scaleX * scale / 2, -height * scaleY * scale / 2 };
	float vertex4[2] = { width * scaleX * scale / 2, height * scaleY * scale / 2 };

	float x, y;

	//Vertex 1
	x = ((vertex1[0] * rotationMatrix[0][0]) - (vertex1[1] * rotationMatrix[0][1]));
	y = ((vertex1[0] * rotationMatrix[1][0]) - (vertex1[1] * rotationMatrix[1][1]));
	vertices[0] = x + originX;
	vertices[1] = y + originY;
	//Vertex 2
	x = ((vertex2[0] * rotationMatrix[0][0]) - (vertex2[1] * rotationMatrix[0][1]));
	y = ((vertex2[0] * rotationMatrix[1][0]) - (vertex2[1] * rotationMatrix[1][1]));
	vertices[7] = x + originX;
	vertices[8] = y + originY;
	//Vertex 3
	x = ((vertex3[0] * rotationMatrix[0][0]) - (vertex3[1] * rotationMatrix[0][1]));
	y = ((vertex3[0] * rotationMatrix[1][0]) - (vertex3[1] * rotationMatrix[1][1]));
	vertices[14] = x + originX;
	vertices[15] = y + originY;
	//Vertex 4
	x = ((vertex4[0] * rotationMatrix[0][0]) - (vertex4[1] * rotationMatrix[0][1]));
	y = ((vertex4[0] * rotationMatrix[1][0]) - (vertex4[1] * rotationMatrix[1][1]));
	vertices[21] = x + originX;
	vertices[22] = y + originY;

}
void Sprite::setColour(float red, float green, float blue)
{
	red = red / 255;
	green = green / 255;
	blue = blue / 255;
	vertices[2] = red; //red
	vertices[3] = green; //green
	vertices[4] = blue; //blue
	vertices[9] = red; //red
	vertices[10] = green; //green
	vertices[11] = blue; //blue
	vertices[16] = red; //red
	vertices[17] = green; //green
	vertices[18] = blue; //blue
	vertices[23] = red; //red
	vertices[24] = green; //green
	vertices[25] = blue; //blue
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
void Sprite::setTextureCoordinates(float left, float top, float right, float bottom)
{
	float normWidth = 1.0f / (float)texture->getWidth();
	float normHeight = 1.0f / (float)texture->getHeight();

	float tempLeft, tempTop, tempRight, tempBottom;

	tempLeft = normWidth * left;
	tempTop = normHeight * top;
	tempRight = normWidth * right;
	tempBottom = normHeight * bottom;

	vertices[5] = tempLeft;
	vertices[6] = tempBottom;

	vertices[12] = tempLeft;
	vertices[13] = tempTop;

	vertices[19] = tempRight;
	vertices[20] = tempBottom;

	vertices[26] = tempRight;
	vertices[27] = tempTop;
}

float Sprite::getLeft()
{
	float temp;

	//left
	for (int i = 0; i < 4; i++)
	{
		if ((i == 0) || (temp > vertices[i * 7]))
			temp = vertices[i * 7];
	}
	return temp;
}
float Sprite::getTop()
{
	float temp = 0;

	//top
	for (int i = 0; i < 4; i++)
	{
		if ((i == 0) || (temp > vertices[i * 7 + 1]))
			temp = vertices[i * 7 + 1];
	}
	return temp;
}
float Sprite::getRight()
{
	float temp = 0;

	//right
	for (int i = 0; i < 4; i++)
	{
		if ((i == 0) || (temp < vertices[i * 7]))
			temp = vertices[i * 7];
	}
	return temp;
}
float Sprite::getBottom()
{
	float temp = 0;

	//bottom
	for (int i = 0; i < 4; i++)
	{
		if ((i == 0) || (temp < vertices[i * 7 + 1]))
			temp = vertices[i * 7 + 1];
	}
	return temp;
}

const bool Sprite::contains(float x, float y)
{
	float ownArray[4] = {
		this->getLeft(),
		this->getTop(),
		this->getRight(),
		this->getBottom()
	};

	if (((ownArray[0] < x) && (ownArray[2] > x)) && ((ownArray[1] < y) && (ownArray[3] > y)))
		return true;
	else
		return false;
}

const bool Sprite::intersects(Sprite* collider)
{
	float colliderArray[4] = {
							collider->getLeft(),
							collider->getTop(),
							collider->getRight(),
							collider->getBottom() 
						  };

	float ownArray[4] = {
							this->getLeft(),
							this->getTop(),
							this->getRight(),
							this->getBottom()
	};

	float tempArray[4];

	//intersect rectangle left side
	if (ownArray[0] >= colliderArray[0])
		tempArray[0] = ownArray[0];
	else
		tempArray[0] = colliderArray[0];

	//intersect rectangle top side
	if (ownArray[1] >= colliderArray[1])
		tempArray[1] = ownArray[1];
	else
		tempArray[1] = colliderArray[1];

	//intersect rectangle right side
	if (ownArray[2] < colliderArray[2])
		tempArray[2] = ownArray[2];
	else
		tempArray[2] = colliderArray[2];

	//intersect rectangle bottom side
	if (ownArray[3] < colliderArray[3])
		tempArray[3] = ownArray[3];
	else
		tempArray[3] = colliderArray[3];

	//if left < right and if top < bottom, an intersection has happened => return true
	if ((tempArray[0] < tempArray[2]) && (tempArray[1] < tempArray[3]))
		return true;
	else
		return false;
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