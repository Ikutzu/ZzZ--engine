#include "Texture.h"

using namespace ZZZ;

Texture::Texture(TextureRes* resource)
{
	createTexture(resource);
}

Texture::~Texture()
{

}

void Texture::createTexture(TextureRes* resource)
{
	glGenTextures(1, &index);
	glBindTexture(GL_TEXTURE_2D, index);

	glTexImage2D(GL_TEXTURE_2D, 0, 4, resource->getWidth(), resource->getHeight(),
		0, GL_RGBA, GL_UNSIGNED_BYTE, &resource->getTexture()[0]);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0u);
}