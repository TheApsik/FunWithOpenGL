#pragma once
#include <chrono>
class Time
{
private:
	std::chrono::steady_clock::time_point started;
	std::chrono::steady_clock::time_point end;
public:
	Time();
	void stop();
	void start();
	float getMilliseconds();
	float getMicroseconds();
	float getNanoseconds();
	float getSeconds();
};

