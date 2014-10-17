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


bool TextureRes::decodeImage()
{
	return !lodepng::decode(image, width, height, getFullPath());
}
