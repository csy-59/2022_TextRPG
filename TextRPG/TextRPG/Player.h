#pragma once
#include "Skill.h"
#include "Item.h"

class Player
{
public:


	//능력치 관련
	int GetMaxHealth() const;
	int GetCurrentHealth() const;
	int GetAttack() const;
	int GetDefence() const;
	int GetStress() const;

	//레벨 관련 Getter
	int GetLevel() const;
	int GetNextLevelExp() const;

	//아이템 관련 Getter
	int GetCoinCount() const;
	int GetHansotCount() const;
	int GetNBBCount() const;
	int GetMonsterCount() const;

public:
	static const int MAX_STRESS = 50;

private:
	//최대 체력
	int _maxHealth = 15;

	//능력치
	int _currentHealth = 15;
	int _attack = 3;
	int _defence = 0;
	int _stress = 0;

	//코인
	int _coin = 10;

	//레벨 관련
	int _level = 1;
	int _nextLevelExp = 12;

	//스킬 관련
	Skill _skills[2];

	//아이템 관련
	static const Item _items[3];
	int _itemCount[3] = { 0 };
};