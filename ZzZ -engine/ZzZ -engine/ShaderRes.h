#pragma once
#include "Resource.h"

namespace ZZZ
{
	class ShaderRes : public Resource
	{
	public:
		ShaderRes(std::string fn);
		~ShaderRes();

		std::string getFullPath();
		static std::string getFolder(){ return "Assets\\Shaders\\"; };
		static std::string getFileType(){ return ".txt"; };

	private:

	};
}

