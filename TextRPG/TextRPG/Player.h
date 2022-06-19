#pragma once
#include "Skill.h"
#include "Item.h"

class Player
{
public:
	Player();
	Player(const Player& other) = delete;
	Player& operator=(const Player& other) = delete;
	~Player();

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
	int GetCoinCount() const;
	const int* GetItemCount() const;

	//������ ����
	void BuyItem(const Item::ItemType itemNumber, const int price);

	//ȸ���� ����
	void GotToPond();

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

	//����
	int _coin = 10;

	//���� ����
	int _level = 1;
	int _nextLevelExp = 12;

	//��ų ����
	Skill _skills[2];

	//������ ����
	int _itemCount[Item::ITEM_MAX] = { 0 };
};