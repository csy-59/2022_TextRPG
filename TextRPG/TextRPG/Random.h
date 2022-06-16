#pragma once
#include <cmath>
#include <time.h>

class Random
{
public:
	Random() = delete;
	Random(const Random&) = delete;
	Random& operator=(const Random&) = delete;
	~Random() = default;

	static void Init();
	static int GetRandomNumberFromRange(int minNum, int maxNum);
};
void Random::Init()
{
	srand(time(NULL));
}

int Random::GetRandomNumberFromRange(int minNum, int maxNum)
{
	float normalized = (float) rand() / RAND_MAX;
	int range = maxNum - minNum + 1;
	int result = minNum + (int)(range * normalized);

	return result;
}
