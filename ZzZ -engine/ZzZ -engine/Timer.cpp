#include "Timer.h"
using namespace std;
using namespace ZZZ;

Timer::Timer(TimeUnit timeUnit)
{
	unit = timeUnit;
	reset();
}


Timer::~Timer()
{
}


void Timer::reset()
{
	startTime = clock::now();
}


float Timer::elapsed()
{
	switch (unit)
	{
	case hour:
		return chrono::duration_cast<chrono::duration<float, std::ratio<3600>>>(clock::now() - startTime).count();
	case minute:
		return chrono::duration_cast<chrono::duration<float, ratio<60>>>(clock::now() - startTime).count();
	case second:
		return chrono::duration_cast<chrono::duration<float, ratio<1>>>(clock::now() - startTime).count();
	case milli:
		return chrono::duration_cast<chrono::duration<float, std::milli>>(clock::now() - startTime).count();
	case nano:
		return chrono::duration_cast<chrono::duration<float, std::nano>>(clock::now() - startTime).count();

	default:
		return chrono::duration_cast<chrono::duration<float, std::ratio<1>>>(clock::now() - startTime).count();
	}
	
}
