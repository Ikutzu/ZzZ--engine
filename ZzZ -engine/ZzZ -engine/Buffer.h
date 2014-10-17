#ifndef BUFFER_H
#define BUFFER_H

#include "GL\glew.h"

namespace ZZZ
{
	class Buffer
	{		
	public:
		
		enum type
		{
			VERTEX,
			INDEX
		};

		void createBuffer(unsigned size, type bufferType);
		  
		type getType(){ return bufferType; }
		GLuint getIndex(){ return index; }

	protected:

		GLfloat *data;
		GLuint index;
		type bufferType;

	};
}
#endif