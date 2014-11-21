#pragma once
#include "ShaderRes.h"
#include "TextureRes.h"
#include <string>
#include <map>
#include <sstream>


namespace ZZZ
{
	/*
	* Tekstuurin lataus:
	*
	* ResourceManager rm;
	* TextureRes* tr = rm.load<TextureRes>(filename_without_extension);
	* Texture tex;
	* tex.createTexture(tr);
	*/
	class ResourceManager
	{
	public:
		static ResourceManager* instance();

		void printAll();

		template<typename T>T* load(std::string fileName);
		template<typename T>T* find(size_t hash);
		
	private:
		
		static ResourceManager* instanceObj;
		typedef std::map<size_t, Resource*> mapType;
		mapType storage;
	};

	template<typename T>
	T* ResourceManager::load(std::string fileName)
	{
		std::hash<std::string> hasher;
		size_t hash = hasher(T::getFolder() + fileName);
		T* obj = find<T>(hash);
		if (obj == nullptr)
		{
			obj = new T(fileName);
			storage.insert(std::make_pair(hash, obj));
		}
		return obj;
	}


	template<typename T>
	T* ResourceManager::find(size_t hash)
	{
		mapType::iterator it = storage.find(hash);
		if (it == storage.end())
			return nullptr;
		else
			return static_cast<T*>(it->second);
	}
}

