#pragma once
#include <string>
#include "Player.h"

class Monster
{
public:
	Monster() = default;
	Monster(std::string name, std::string introduce, std::string, std::string attackNoise,
		int maxHealth, int currentHealth, int maxAttackDamage, int minAttackDame,
		int defence, int dropRate, int dropCoin);
	Monster(const Monster& other) = default;
	Monster& operator=(const Monster& other) = default;
	~Monster() = default;

	//setter
	void SetName(std::string);
	void SetIntorduceString(std::string);
	void SetAttackNoise(std::string);

	void SetMaxHealth(int);
	void SetCurrentHealth(int);

	void SetMaxAttackDamage(int);
	void SetMinAttackDamage(int);

	void SetDefence(int);

	void SetDropRate(int);
	void SetDropCoin(int);

	//접근자
	std::string GetName();
	std::string GetIntroduceString();
	std::string GetAttackNoise();

	int GetMaxHealth();
	int GetCurrentHealth();

	//void Attack(Player& player);
	void GetAttacked(int damage);
	int DropCoin();

private:
	//몬스터 이름
	std::string name = "";
	std::string introduce = "";
	std::string attackNoise = "";

	//몬스터 능력치
	int maxHealth = 0;
	int currentHealth = 0;

	int maxAttackDamage = 0;
	int minAttackDamage = 0;

	int defence = 0;

	//보상 관련
	int dropRate = 0;
	int dropCoin = 0;
};