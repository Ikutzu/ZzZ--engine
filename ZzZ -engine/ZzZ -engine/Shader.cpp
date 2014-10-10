#include "Shader.h"

using namespace ZZZ;

GLuint Shader::program = 0;

GLuint Shader::vertexShader;
GLuint Shader::fragmentShader;
GLint Shader::positionIndex;
GLint Shader::colorIndex;


static const GLchar*  VERTEX_SOURCE =
"attribute vec2 attrPosition;\n"
"attribute vec3 attrColor;\n"

//"varying vec3 varyColor;\n"

"void main(void)\n"
"{\n"
//"	varyColor = attrColor;\n"
//"	gl_Position = vec4(attrPosition, 0.0, 1.0);\n"
"}\n";

static const GLchar*  FRAGMENT_SOURCE =
//"varying vec3 varyColor;\n"

"void main (void)\n"
"{\n"
//"	gl_FragColor = vec4(varyColor, 1.0);\n"
"}\n";

int Shader::newShader(GLchar* vertexSource, GLchar* fragmentSource) // [shader]Source == null -> default
{
	if (program == 0)
	{
		program = glCreateProgram();
	}

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	if (vertexSource == nullptr)
		glShaderSource(vertexShader, 1u, &VERTEX_SOURCE, nullptr);
	else
		glShaderSource(vertexShader, 1u, &vertexSource, nullptr);
	
	glCompileShader(vertexShader);
	glAttachShader(program, vertexShader);


	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	if (fragmentSource == nullptr)
		glShaderSource(fragmentShader, 1u, &FRAGMENT_SOURCE, nullptr);
	else
		glShaderSource(fragmentShader, 1u, &fragmentSource, nullptr);

	glCompileShader(fragmentShader);
	glAttachShader(program, fragmentShader);

	
	glLinkProgram(program);


	GLint testResult;

	{
		glGetProgramiv(program, GL_LINK_STATUS, &testResult);
		if (testResult != GL_TRUE)
		{
			Debugger::Print("Program linking error.");
			return 1;
		}
		glGetProgramiv(vertexShader, GL_COMPILE_STATUS, &testResult);
		if (testResult != GL_TRUE)
		{
			Debugger::Print("Vertex shader compile error.");
			return 1;
		}
		glGetProgramiv(fragmentShader, GL_COMPILE_STATUS, &testResult);
		if (testResult != GL_TRUE)
		{
			Debugger::Print("Fragment shader compile error.");
			return 1;
		}
		positionIndex = glGetAttribLocation(program, "attrPosition");
		if (positionIndex < 0)
		{
			Debugger::Print("Missing 'attrPosition' from vertex shader.");
			return 1;
		}
		colorIndex = glGetAttribLocation(program, "attrColor");
		if (colorIndex < 0)
		{
			Debugger::Print("Missing 'attrColor' from vertex shader.");
			return 1;
		}
	}
	return 0;
}

void Shader::doSomething()
{
	glVertexAttribPointer(positionIndex, 2u, GL_FLOAT, GL_FALSE, 20u, reinterpret_cast<GLvoid*>(0u));
	glVertexAttribPointer(colorIndex, 3u, GL_FLOAT, GL_FALSE, 20u, reinterpret_cast<GLvoid*>(8u));
}