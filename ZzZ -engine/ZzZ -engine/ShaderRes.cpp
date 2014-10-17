#include "ShaderRes.h"
using namespace std;
using namespace ZZZ;

ShaderRes::ShaderRes(string fn) : Resource(fn)
{
}


ShaderRes::~ShaderRes()
{
}


string ShaderRes::getFullPath()
{
	return getFolder() + fileName + getFileType();
}
std::string ShaderRes::loadFromFile(const char *filePath)
{
	std::ifstream fileStream(filePath, std::ios::in);

	if (!fileStream.is_open()) {
		printf("Filename is incorrect");
		return "";
	}

	std::string line = "";
	while (!fileStream.eof()) {
		std::getline(fileStream, line);
		content.append(line + "\n");
	}

	fileStream.close();
	return content;
}
std::string ShaderRes::getShaderSource()
{
	return content;
}

