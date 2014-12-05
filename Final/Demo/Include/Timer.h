#pragma once
#include <chrono>

namespace ZZZ
{
	enum TimeUnit
	{
		unset = -1, 
		hour, minute, second, millisecond, microsecond, nanosecond
	};

	/* käyttöohje:
	 * pelin updaten alussa timer.startDeltaTime();
	 * viime kierrokseen kulunut aika timer.getDeltaTime();
	 * pelin updaten lopussa timer.setDeltaTime(); 
	 */
	class Timer
	{
	public:
		Timer(TimeUnit timeUnit = second);
		~Timer();

		void reset();
		float elapsed(TimeUnit timeUnit = unset);
		void startDeltaTime();
		void setDeltaTime();
		float getDeltaTime() { return deltaTime; }


	private:
		TimeUnit unit;
		typedef std::chrono::high_resolution_clock clock;
		std::chrono::time_point<clock> startTime;
		std::chrono::time_point<clock> interval;
		float deltaTime;

		float delta(std::chrono::time_point<clock> a, std::chrono::time_point<clock> b, TimeUnit timeUnit);
	};
}

