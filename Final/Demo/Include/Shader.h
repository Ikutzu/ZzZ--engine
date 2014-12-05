#ifndef SHADER_H
#define SHADER_H

#include "debugger.h"
#include "GL\glew.h"

namespace ZZZ
{
	class Shader
	{
	public:
	
		static int newShader(GLchar* shaderSource, GLchar* fragmentSource, RECT windowCoordinates);
		
		static GLuint* getProgram();
		static void useShader();

	private:

		Shader(){};
		~Shader(){};

		static GLuint program;		
		static GLuint vertexShader;
		static GLuint fragmentShader;
		static GLint positionIndex;
		static GLint colorIndex;
		static GLint texIndex;
		static GLint projectionLocation;
	};
}

#endif