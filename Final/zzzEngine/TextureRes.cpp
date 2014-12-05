#include "TextureRes.h"
using namespace std;
using namespace ZZZ;

TextureRes::TextureRes(string fn) : Resource(fn)
{
	decodeImage();
}


TextureRes::~TextureRes()
{
}


string TextureRes::getFullPath()
{
	return getFolder() + fileName + getFileType();
}


bool TextureRes::decodeImage()
{
	return !lodepng::decode(texture, width, height, getFullPath());
}
