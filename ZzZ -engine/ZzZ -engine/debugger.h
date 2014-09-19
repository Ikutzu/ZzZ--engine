#ifndef ZZZ_DEBUGGER
#define ZZZ_DEBUGGER

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

/*
HOW_TO?
1. Use:Debugger::Print("your string here");
2. Read the file
3. ?????
4. Profit!
*/

class Debugger
{
public:
	static Debugger* Instance();
	static void Print(std::string str);
protected:
	Debugger();
	~Debugger();
private:
	static Debugger* instance;
};


#endif // !ZZZ_DEBUGGER
