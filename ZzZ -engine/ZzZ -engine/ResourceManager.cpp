#include "ResourceManager.h"
#include "debugger.h"
using namespace std;


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


//return ?-pointer
bool ResourceManager::load(string value)
{
	size_t hash = hasher(value);

	if (!find(value))
	{
		map.insert(make_pair(hash, value));
		//fileManager::loadFile(hash) ???
	}
	return true;
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


bool ResourceManager::find(string value)
{
	for (it = map.begin(); it != map.end(); it++)
	{
		if (hasher(value) == (*it).first)
			return true;
	}
	return false;
}

