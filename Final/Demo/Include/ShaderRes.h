#pragma once
#include "Resource.h"
#include <fstream>
#include <iostream>
#include "debugger.h"

namespace ZZZ
{
	class ShaderRes : public Resource
	{
	public:
		ShaderRes(std::string fn);
		~ShaderRes();
		


		std::string getFullPath();
		static std::string getFolder(){ return "Assets\\Shaders\\"; };
		static std::string getFileType(){ return ".glsl"; };
		std::string getShaderSource();
		std::string loadFromFile(const char *filePath);
	private:
		std::string content;
	};
}

