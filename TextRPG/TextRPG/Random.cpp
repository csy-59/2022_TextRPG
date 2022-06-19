#include "Random.h"

void Random::Init()
{
	srand(time(NULL));
}

int Random::GetRandomNumberFromRange(int minNum, int maxNum)
{
	float normalized = (float)rand() / RAND_MAX;
	int range = maxNum - minNum + 1;
	int result = minNum + (int)(range * normalized);

	return result;
}

float Random::GetRandomFloatNumberFromRange(float minNum, float maxNum)
{
	float normalized = (float)rand() / RAND_MAX;
	float range = maxNum - minNum + 1;
	float result = minNum + range * normalized;

	return result;
}
