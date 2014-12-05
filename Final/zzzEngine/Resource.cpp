#include "Resource.h"
using namespace std;
using namespace ZZZ;



Resource::Resource()
{
	fileName = "";
}


Resource::Resource(string fn)
{
	fileName = fn;
}


Resource::~Resource()
{
}


string Resource::getFileName()
{
	return fileName;
}
