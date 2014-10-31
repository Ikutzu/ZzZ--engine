#ifndef BUFFER_H
#define BUFFER_H

#include "GL\glew.h"

namespace ZZZ
{
	enum bufferType
	{
		ZZZVERTEX,
		ZZZINDEX
	};

	class Buffer
	{		
	public:
		
		~Buffer();

		void createBuffer(bufferType type);
		void pushData(unsigned size, void *data);

		bufferType getType(){ return type; }
		GLuint* getIndex(){ return &index; }

	protected:

		GLuint index;
		bufferType type;

	};
}
#endif