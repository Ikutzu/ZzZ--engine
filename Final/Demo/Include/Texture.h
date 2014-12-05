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
		int getWidth(){ return width; };
		int getHeight(){ return height; };

	private:
		void createTexture(TextureRes* resource);

		GLuint index;
		int width, height;
	};
}
#endif