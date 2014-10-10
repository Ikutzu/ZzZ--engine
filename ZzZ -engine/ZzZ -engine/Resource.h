#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

namespace ZZZ
{
	class Resource
	{
	protected:
		virtual bool createResource(){ return true; }
		std::string fileName;

	};
}

#endif