#pragma once
#include "Resource.h"
#include "lodepng.h"
#include <vector>
#include "debugger.h"

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

		std::vector<unsigned char> getTexture(){ return texture; };
		unsigned getWidth(){ return width; };
		unsigned getHeight(){ return height; };
		unsigned getSize(){ return size; };

	private:
		std::vector<unsigned char> texture;
		unsigned width, height, size;

		bool decodeImage();
	};
}

