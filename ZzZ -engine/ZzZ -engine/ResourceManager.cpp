#include "ResourceManager.h"
#include "debugger.h"
using namespace std;
using namespace ZZZ;

/*
void ResourceManager::initialize()
{
	if (instance == nullptr)
		instance = new ResourceManager();
}
*/


ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
	//delete instance;
}


bool ResourceManager::loadTexture(Texture& r, std::string fileName)
{
	size_t hash = hasher(fileName);

	if (!find(hash))
	{
		//r = Texture::createResource();
		//map.insert(make_pair(hash, r));
	}
	return nullptr;
}


void ResourceManager::debug()
{
	ostringstream ss;
	for (it = map.begin(); it != map.end(); it++)
	{
		ss << "hash " << (*it).first << ", name " << (*it).second << endl;
		Debugger::Print(ss.str());
	}
}


bool ResourceManager::find(size_t hash)
{
	for (it = map.begin(); it != map.end(); it++)
	{
		if (hash == (*it).first)
			return true;
	}
	return false;
}

