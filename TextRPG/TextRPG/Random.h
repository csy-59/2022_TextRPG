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

	/// <summary>
	/// Random을 초기화한다.
	/// </summary>
	static void Init();

	/// <summary>
	/// [minNum, maxNum]까지의 랜덤 수를 생성한다.
	/// </summary>
	/// <param name="minNum">최소 수</param>
	/// <param name="maxNum">최대 수</param>
	/// <returns>생성한 난수</returns>
	static int GetRandomNumberFromRange(int minNum, int maxNum);

	/// <summary>
	/// [minNum, maxNum]까지의 랜덤 실수를 생성한다.
	/// </summary>
	/// <param name="minNum">최소 수</param>
	/// <param name="maxNum">최대 수</param>
	/// <returns>생성한 랜덤 실수</returns>
	static float GetRandomFloatNumberFromRange(float minNum, float maxNum);
};

