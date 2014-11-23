#include "Timer.h"
using namespace std;
using namespace chrono;
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


// Palauttaa kuluneen ajan annettuna yksikkönä.
// Jos yksikköä ei annettu parametrina, käytetään kelloon asetettua yksikköä.
float Timer::elapsed(TimeUnit timeUnit)
{
	TimeUnit tempUnit = timeUnit;
	if (timeUnit == unset)
		tempUnit = unit;

	switch (tempUnit)
	{
	case hour:
		return duration_cast<duration<float, ratio<3600>>>(clock::now() - startTime).count();
	case minute:
		return duration_cast<duration<float, ratio<60>>>(clock::now() - startTime).count();
	case second:
		return duration_cast<duration<float, ratio<1>>>(clock::now() - startTime).count();
	case millisecond:
		return duration_cast<duration<float, milli>>(clock::now() - startTime).count();
	case microsecond:
		return duration_cast<chrono::duration<float, micro>>(clock::now() - startTime).count();
	case nanosecond:
		return duration_cast<chrono::duration<float, nano>>(clock::now() - startTime).count();

	default:
		return duration_cast<duration<float, ratio<1>>>(clock::now() - startTime).count();
	}
	
}
