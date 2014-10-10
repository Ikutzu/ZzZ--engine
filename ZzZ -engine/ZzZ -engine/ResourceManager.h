#pragma once
#include <functional>
#include <string>
#include <map>
#include <utility>
#include <sstream>
#include "Resource.h"
#include "Texture.h"


//TODO: singleton
namespace ZZZ
{
	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();
		//void initialize();

		bool loadTexture(Texture& r, std::string fileName);
		//bool loadShader(Texture& r, std::string name);
		void debug();

	private:

		bool find(size_t hash);

		//ResourceManager* instance;
		std::map<size_t, Resource*> map;
		std::map<size_t, Resource*>::iterator it;
		std::hash<std::string> hasher;
	};
}

