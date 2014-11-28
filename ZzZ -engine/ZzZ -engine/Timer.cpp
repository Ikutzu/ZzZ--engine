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
	startTime = interval = clock::now();
	deltaTime = 0;
}


void Timer::startDeltaTime()
{
	interval = clock::now();
}


void Timer::setDeltaTime()
{
	deltaTime = delta(clock::now(), interval, TimeUnit::unset);
}


float Timer::elapsed(TimeUnit timeUnit)
{
	return delta(clock::now(), startTime, timeUnit);
}


// Palauttaa kuluneen ajan annettuna yksikkönä.
// Jos yksikköä ei annettu parametrina, käytetään kelloon asetettua yksikköä.
float Timer::delta(time_point<clock> a, time_point<clock> b, TimeUnit timeUnit)
{
	TimeUnit tempUnit = timeUnit;
	if (timeUnit == unset)
		tempUnit = unit;

	switch (tempUnit)
	{
	case hour:
		return duration_cast<duration<float, ratio<3600>>>(a - b).count();
	case minute:
		return duration_cast<duration<float, ratio<60>>>(a - b).count();
	case second:
		return duration_cast<duration<float, ratio<1>>>(a - b).count();
	case millisecond:
		return duration_cast<duration<float, milli>>(a - b).count();
	case microsecond:
		return duration_cast<duration<float, micro>>(a - b).count();
	case nanosecond:
		return duration_cast<duration<float, nano>>(a - b).count();

	default:
		return duration_cast<duration<float, ratio<1>>>(a - b).count();
	}
}