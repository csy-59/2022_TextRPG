#pragma once
#include "Skill.h"

class Player
{
	static const int MAX_STRESS = 50;
public:

private:
	//최대 체력
	int maxHealth = 15;
	//최대 스트레스

	//능력치
	int currentHealth = 15;
	int attack = 3;
	int defence = 0;
	int stress = 0;

	//레벨 관련
	int level = 1;
	int nextLevelExp = 12;

	//스킬 관련
	Skill skills[2];
};