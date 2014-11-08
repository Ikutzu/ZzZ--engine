#include "Texture.h"

using namespace ZZZ;

void Texture::createTexture(TextureRes* resource)
{
	glGenTextures(1, &index);
	glBindTexture(GL_TEXTURE_2D, index);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, resource->getWidth(), resource->getHeight(),
		0, GL_RGBA, GL_UNSIGNED_BYTE, resource->getTexture().data());
	glBindTexture(GL_TEXTURE_2D, 0u);
}