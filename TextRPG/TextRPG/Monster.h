#pragma once
#include <string>
#include "Player.h"
#include "Random.h"

class Monster
{
public:
	Monster() = default;
	Monster(std::string name, std::string introduce, std::string attackNoise, 
		int maxHealth, int currentHealth, int maxAttackDamage, int minAttackDame,
		int dropRate, int dropCoin);
	Monster(const Monster& other) = default;
	Monster& operator=(const Monster& other) = default;
	~Monster() = default;

	//setter
	void SetName(std::string);
	void SetIntorduceString(std::string);
	void SetAttackNoise(std::string attckNoise);

	void SetMaxHealth(int max);
	void SetCurrentHealth(int cur);

	void SetMaxAttackDamage(int maxA);
	void SetMinAttackDamage(int minA);

	void SetDropRate(int drate);
	void SetDropCoin(int dcoin);

	//접근자
	std::string GetName();
	std::string GetIntroduceString();
	std::string GetAttackNoise();

	int Damage();

	int GetMaxHealth();
	int GetCurrentHealth();

	//전투 관련
	void GetAttacked(int damage);
	int DropCoin();

private:
	//몬스터 이름
	std::string _name = "";
	std::string _introduce = "";
	std::string _attackNoise = "";

	//몬스터 능력치
	int _maxHealth = 0;
	int _currentHealth = 0;

	int _maxAttackDamage = 0;
	int _minAttackDamage = 0;

	//보상 관련
	int _dropRate = 0;
	int _dropCoin = 0;
};