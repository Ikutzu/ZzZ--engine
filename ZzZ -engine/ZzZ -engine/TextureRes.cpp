#include "TextureRes.h"
using namespace std;
using namespace ZZZ;

TextureRes::TextureRes(string fn) : Resource(fn)
{
}


TextureRes::~TextureRes()
{
}


string TextureRes::getFullPath()
{
	return getFolder() + fileName + getFileType();
}
