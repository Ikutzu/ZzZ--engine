#pragma once
#include <functional>
#include <string>
#include <map>
#include <utility>
#include <sstream>



//TODO: singleton
class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();
	//void initialize();

	bool load(std::string name);
	void debug();

private:

	bool find(std::string name);

	//ResourceManager* instance;
	std::map<size_t, std::string> map;
	std::map<size_t, std::string>::iterator it;
	std::hash<std::string> hasher;
};

