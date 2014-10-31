#include "Buffer.h"

using namespace ZZZ;

void Buffer::createBuffer(bufferType type)
{
	this->type = type;

	glGenBuffers(1, &index);
}

void Buffer::pushData(unsigned size, void *data)
{
	if (type == ZZZVERTEX)
	{
		glBindBuffer(GL_ARRAY_BUFFER, index);
		glBufferData(GL_ARRAY_BUFFER, size, &data, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0u);
	}
	if (type == ZZZINDEX)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, &data, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0u);
	}
}