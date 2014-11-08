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
	unsigned error = lodepng::decode(texture, width, height, getFullPath());
	if (error == 0)
	{
		Debugger::Print("Decoded image succesfully.");
		return true;
	}
	else
	{
		Debugger::Print("Decoding image failed.");
		return false;
	}
}
