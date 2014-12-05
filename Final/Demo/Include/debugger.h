#ifndef ZZZ_DEBUGGER
#define ZZZ_DEBUGGER
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>
#include <Windows.h>
#include "GL\glew.h"
/*
HOW_TO?
1. Use: Debugger::Print("your string here");
2. Read the file
3. ?????
4. Profit!
*/
class Debugger
{
public:
	static Debugger* Instance();
	static void Print(std::string debugString);
	template <typename T> static void Print(std::string debugString, T variable);
	static void checkGLError(std::string debugString);
protected:
	Debugger();
	~Debugger();
private:
	static Debugger* instance;
};

template <typename T>
static void Debugger::Print(std::string debugString, T variable)
{
	std::ostringstream stream;
	stream << debugString << variable;
	Debugger::Print(stream.str());
}
#endif // !ZZZ_DEBUGGER