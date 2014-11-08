#ifndef TEXTURE_H
#define TEXTURE_H

#include "GL\glew.h"
#include "TextureRes.h"

namespace ZZZ
{
	class Texture
	{
	public:
		void createTexture(TextureRes* resource);

		GLuint getIndex(){ return index; };

	private:
		GLuint index;

	};
}
#endif