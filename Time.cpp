#include "Time.h"
#include <iostream>

Time::Time(): started(std::chrono::high_resolution_clock::now()), end()
{}

void Time::stop()
{
	end = std::chrono::high_resolution_clock::now();
}

void Time::start()
{
	started = std::chrono::high_resolution_clock::now();
}

float Time::getMilliseconds()
{
	return static_cast<float>(std::chrono::duration_cast<std::chrono::milliseconds>(end - started).count());
}

float Time::getMicroseconds()
{
	return static_cast<float>(std::chrono::duration_cast<std::chrono::microseconds>(end - started).count());
}

float Time::getNanoseconds()
{
	return static_cast<float>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - started).count());
}

float Time::getSeconds()
{
	return static_cast<float>(std::chrono::duration_cast<std::chrono::seconds>(end - started).count());
}
