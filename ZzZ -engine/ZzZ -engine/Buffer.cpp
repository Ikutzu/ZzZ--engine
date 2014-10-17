#include "Buffer.h"

using namespace ZZZ;


void Buffer::createBuffer(unsigned size, type bufferType)
{
	if (bufferType == VERTEX)
	{
		glGenBuffers(1, &index);
		glBindBuffer(GL_ARRAY_BUFFER, index);
		glBufferData(GL_ARRAY_BUFFER, size, &data, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0u);
	}
	if (bufferType == INDEX)
	{
		glGenBuffers(1, &index);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, &data, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0u);
	}
}