#include "Buffer.h"

using namespace ZZZ;

unsigned Buffer::size = 128;

Buffer::~Buffer()
{
	glDeleteBuffers(1, &index);
}

void Buffer::createBuffer(bufferType type)
{
	this->type = type;

	glGenBuffers(1, &index);

	if (this->type == ZZZVERTEX)
	{
		glBindBuffer(GL_ARRAY_BUFFER, index);
		glBufferData(GL_ARRAY_BUFFER, size * 28 * sizeof(float), nullptr, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0u);
	}
	if (this->type == ZZZINDEX)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * 6 * sizeof(float), nullptr, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0u);
	}
}

void Buffer::pushData(unsigned size, void *data)
{
	if (type == ZZZVERTEX)
	{
		glBindBuffer(GL_ARRAY_BUFFER, index);
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, &data);
		
		if (glGetError() == GL_INVALID_VALUE)
		{
			this->size *= 2;
			glDeleteBuffers(1, &index);
			createBuffer(type);
			glBufferSubData(GL_ARRAY_BUFFER, 0, size, &data);
		}

		glBindBuffer(GL_ARRAY_BUFFER, 0u);
	}
	if (type == ZZZINDEX)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, size, &data);

		if (glGetError() == GL_INVALID_VALUE)
		{
			this->size *= 2;
			glDeleteBuffers(1, &index);
			createBuffer(type);
			glBufferSubData(GL_ARRAY_BUFFER, 0, size, &data);
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0u);
	}
}