#include "Shader.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"

using namespace ZZZ;

GLuint Shader::program = 0;

GLuint Shader::vertexShader;
GLuint Shader::fragmentShader;
GLint Shader::positionIndex;
GLint Shader::colorIndex;
GLint Shader::texIndex;
GLint Shader::projectionLocation;


static const GLchar*  VERTEX_SOURCE =
"attribute vec2 attrPosition;\n"
"attribute vec3 attrColor;\n"
"attribute vec2 attrTexture;\n"

"uniform mat4 unifProjection;\n"

"varying vec3 varyColor;\n"
"varying vec2 textureCoords;\n"

"void main(void)\n"
"{\n"
"	textureCoords = attrTexture;\n"
"	varyColor = attrColor;\n"
"	gl_Position = unifProjection * vec4(attrPosition, 0.0, 1.0);\n"
"}\n";

static const GLchar*  FRAGMENT_SOURCE =
"varying vec3 varyColor;\n"
"varying vec2 textureCoords;\n"
"uniform sampler2D sampleri;\n"

"void main (void)\n"
"{\n"
"	gl_FragColor = texture(sampleri, textureCoords) + vec4(varyColor, 0.0);\n"
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
		texIndex = glGetAttribLocation(program, "attrTexture");
		if (texIndex < 0)
		{
			Debugger::Print("Missing 'attrTexture' from vertex shader.");
			return 1;
		}
		projectionLocation = glGetUniformLocation(program, "unifProjection");
		if (projectionLocation < 0)
		{
			Debugger::Print("Missing 'unifProjection' from vertex shader.");
			return 1;
		}
	}

	glEnableVertexAttribArray(positionIndex);
	glEnableVertexAttribArray(colorIndex);
	glEnableVertexAttribArray(texIndex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glm::mat4 projection = glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);

	glUseProgram(program);

	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, reinterpret_cast<float*>(&projection));

	glUseProgram(0u);

	return 0;
}

void Shader::useShader()
{
	glVertexAttribPointer(positionIndex, 2u, GL_FLOAT, GL_FALSE, 28u, reinterpret_cast<GLvoid*>(0u));
	glVertexAttribPointer(colorIndex, 3u, GL_FLOAT, GL_FALSE, 28u, reinterpret_cast<GLvoid*>(8u));
	glVertexAttribPointer(texIndex, 2u, GL_FLOAT, GL_FALSE, 28u, reinterpret_cast<GLvoid*>(20u));
}