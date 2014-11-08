#include "debugger.h"


Debugger* Debugger::instance = 0;

Debugger::Debugger()
{
}


Debugger::~Debugger()
{
}

Debugger* Debugger::Instance()
{
	if (instance == 0)
	{
		instance = new Debugger;

	}
	return instance;
}

void Debugger::Print(std::string debugString)
{
	std::ofstream outputFile("Log/DebugLog.txt", std::ios::out | std::ios::app);

	time_t perkele = time(0);

	

	if (outputFile)
	{
		outputFile << asctime(localtime(&perkele));
		outputFile << debugString << std::endl;
	}

	debugString += "\n";

	outputFile.close();
	OutputDebugString(debugString.c_str());
}

void Debugger::checkGLError(std::string debugString)
{
	GLenum error = 0;
	error = glGetError();
	while (error != 0)
	{
		error = glGetError();
		Print(debugString);
	}
}