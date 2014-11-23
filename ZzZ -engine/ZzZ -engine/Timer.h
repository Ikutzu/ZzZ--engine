#pragma once
#include <chrono>

namespace ZZZ
{
	enum TimeUnit
	{
		unset = -1, 
		hour, minute, second, millisecond, microsecond, nanosecond
	};

	class Timer
	{
	public:
		Timer(TimeUnit timeUnit = second);
		~Timer();

		void reset();
		float elapsed(TimeUnit timeUnit = unset);

	private:
		TimeUnit unit;
		typedef std::chrono::high_resolution_clock clock;
		std::chrono::time_point<clock> startTime;
	};
}

