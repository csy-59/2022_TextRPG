#pragma once
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
	int GetStress() const;

	//���� ���� Getter
	int GetLevel() const;
	int GetNextLevelExp() const;

	//������ ���� Getter
	int GetCoinCount() const;
	const int* GetItemCount() const;

	//������ ����
	void BuyItem(const int itemNumber, const int price);
	void UseItem(int itemNumber);

	//ȸ���� ����
	void GotToPond();

	//��Ʈ����
	void AddStress(int inputStress);

	//���� ����
	void GotDamageFromMonster(int inputDamage);
	int GotCured(float gainHealth);
	void GotCoin(int gainCoin);
	void GotEXP(int gainEXP);

	//������ ����
	void AddHealth();
	void AddAttack();
	void LevelUp();

	//���� �����
	void Restart();

public:
	static const int MAX_STRESS = 50;

private:
	//�ִ� ü��
	int _maxHealth = 18;

	//�ɷ�ġ
	int _currentHealth = 18;
	int _attack = 5;
	int _stress = 0;

	//����
	int _coin = 10;

	//���� ����
	int _level = 1;
	int _nextLevelExp = 12;

	//������ ����
	int _itemCount[3] = { 0 };

	static const int STATUS_UP = 1;
};