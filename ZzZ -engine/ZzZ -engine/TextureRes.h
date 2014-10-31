#pragma once
#include "Resource.h"
#include "lodepng.h"
#include <vector>

namespace ZZZ
{
	class TextureRes :public Resource
	{
	public:
		TextureRes(std::string fn);
		~TextureRes();

		std::string getFullPath();
		static std::string getFolder(){ return "Assets\\Textures\\"; };
		static std::string getFileType(){ return ".png"; };

		unsigned char* getTexture(){ return texture; };
		unsigned getWidth(){ return width; };
		unsigned getHeight(){ return height; };
		unsigned getSize(){ return size; };

	private:
		unsigned char* texture;
		unsigned width, height, size;

		bool decodeImage();
	};
}

