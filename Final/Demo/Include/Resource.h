#pragma once
#include <string>

namespace ZZZ
{
	class Resource
	{
	public:
		Resource();
		Resource(std::string fn);
		~Resource();

		std::string getFileName();
		virtual std::string getFullPath() = 0;

	protected:
		std::string fileName;
	};
}

