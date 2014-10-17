#pragma once
#include "Resource.h"

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

	private:

	};
}

