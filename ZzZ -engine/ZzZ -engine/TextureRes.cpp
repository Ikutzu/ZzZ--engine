#include "TextureRes.h"
using namespace std;
using namespace ZZZ;

TextureRes::TextureRes(string fn) : Resource(fn)
{
	decodeImage();
}


TextureRes::~TextureRes()
{
	delete texture;
}


string TextureRes::getFullPath()
{
	return getFolder() + fileName + getFileType();
}


bool TextureRes::decodeImage()
{
	vector<unsigned char> temp;
	if (!lodepng::decode(temp, width, height, getFullPath()))
	{
		size = temp.size();
		texture = new unsigned char[temp.size()];
		for (int i = 0; i < size; i++)
		{
			texture[i] = temp.at(i);
		}
		return true;
	}
	else 
		return false;
}
