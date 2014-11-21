#include "ResourceManager.h"
#include "debugger.h"
using namespace std;
using namespace ZZZ;

ResourceManager* ResourceManager::instanceObj = NULL;

void ResourceManager::printAll()
{
	for (mapType::iterator it = storage.begin(); it != storage.end(); it++)
	{
		ostringstream ss;
		ss << (*it).first << " | " << (*it).second->getFullPath();
		Debugger::Print(ss.str());
	}
}

ResourceManager* ResourceManager::instance()
{
	if (!instanceObj)
	{
		instanceObj = new ResourceManager;
	}

	return instanceObj;
}