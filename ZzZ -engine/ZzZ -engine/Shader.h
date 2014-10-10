#ifndef SHADER_H
#define SHADER_H

#include "debugger.h"
#include "GL\glew.h"

namespace ZZZ
{
	class Shader
	{
	public:
	
		static int newShader(GLchar* shaderSource, GLchar* fragmentSource);
		
		static void doSomething();

	private:

		Shader(){};
		~Shader(){};

		static GLuint program;		
		static GLuint vertexShader;
		static GLuint fragmentShader;
		static GLint positionIndex;
		static GLint colorIndex;
	};
}

#endif