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
	/// Random�� �ʱ�ȭ�Ѵ�.
	/// </summary>
	static void Init();

	/// <summary>
	/// [minNum, maxNum]������ ���� ���� �����Ѵ�.
	/// </summary>
	/// <param name="minNum">�ּ� ��</param>
	/// <param name="maxNum">�ִ� ��</param>
	/// <returns>������ ����</returns>
	static int GetRandomNumberFromRange(int minNum, int maxNum);

	/// <summary>
	/// [minNum, maxNum]������ ���� �Ǽ��� �����Ѵ�.
	/// </summary>
	/// <param name="minNum">�ּ� ��</param>
	/// <param name="maxNum">�ִ� ��</param>
	/// <returns>������ ���� �Ǽ�</returns>
	static float GetRandomFloatNumberFromRange(float minNum, float maxNum);
};

