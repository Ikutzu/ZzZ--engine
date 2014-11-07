#include "ResourceManager.h"
#include "debugger.h"
using namespace std;
using namespace ZZZ;

void ResourceManager::printAll()
{
	for (mapType::iterator it = storage.begin(); it != storage.end(); it++)
	{
		ostringstream ss;
		ss << (*it).first << " | " << (*it).second->getFullPath();
		Debugger::Print(ss.str());
	}
}
