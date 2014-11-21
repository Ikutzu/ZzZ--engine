#pragma once
#include <chrono>

namespace ZZZ
{
	enum TimeUnit
	{
		hour, minute, second, milli, nano
	};

	class Timer
	{
	public:
		Timer(TimeUnit timeUnit = second);
		~Timer();

		void reset();
		float elapsed();

	private:
		TimeUnit unit;
		typedef std::chrono::high_resolution_clock clock;
		std::chrono::time_point<clock> startTime;
	};
}

