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

