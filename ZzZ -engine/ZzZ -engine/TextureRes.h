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

		bool decodeImage();

	private:
		std::vector<unsigned char> image;
		unsigned width, height;
	};
}

