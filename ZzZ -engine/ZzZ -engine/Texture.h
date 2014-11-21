#ifndef TEXTURE_H
#define TEXTURE_H

#include "GL\glew.h"
#include "TextureRes.h"

namespace ZZZ
{
	class Texture
	{
	public:
		Texture(std::string fileName);
		~Texture();

		GLuint* getIndex(){ return &index; };

	private:
		void createTexture(TextureRes* resource);

		GLuint index;

	};
}
#endif