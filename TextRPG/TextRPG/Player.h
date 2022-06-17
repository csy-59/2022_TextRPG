#pragma once
#include "Skill.h"
#include "Item.h"

class Player
{
public:


	//�ɷ�ġ ����
	int GetMaxHealth() const;
	int GetCurrentHealth() const;
	int GetAttack() const;
	int GetDefence() const;
	int GetStress() const;

	//���� ���� Getter
	int GetLevel() const;
	int GetNextLevelExp() const;

	//������ ���� Getter
	int GetHansotCount() const;
	int GetNBBCount() const;
	int GetMonsterCount() const;

public:
	static const int MAX_STRESS = 50;

private:
	//�ִ� ü��
	int _maxHealth = 15;

	//�ɷ�ġ
	int _currentHealth = 15;
	int _attack = 3;
	int _defence = 0;
	int _stress = 0;

	//���� ����
	int _level = 1;
	int _nextLevelExp = 12;

	//��ų ����
	Skill _skills[2];

	//������ ����
	static const Item _items[3];
	int _itemCount[3] = { 0 };
};