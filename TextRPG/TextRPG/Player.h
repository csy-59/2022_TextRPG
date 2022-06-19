#pragma once
#include "Item.h"

class Player
{
public:
	Player();
	Player(const Player& other) = delete;
	Player& operator=(const Player& other) = delete;
	~Player();

	//능력치 관련
	int GetMaxHealth() const;
	int GetCurrentHealth() const;
	int GetAttack() const;
	int GetStress() const;

	//레벨 관련 Getter
	int GetLevel() const;
	int GetNextLevelExp() const;

	//아이템 관련 Getter
	int GetCoinCount() const;
	const int* GetItemCount() const;

	//아이템 구매
	void BuyItem(const int itemNumber, const int price);
	void UseItem(int itemNumber);

	//회복의 연못
	void GotToPond();

	//스트레스
	void AddStress(int inputStress);

	//전투 관련
	void GotDamageFromMonster(int inputDamage);
	int GotCured(float gainHealth);
	void GotCoin(int gainCoin);
	void GotEXP(int gainEXP);

	//레벨업 관련
	void AddHealth();
	void AddAttack();
	void LevelUp();

	//게임 재시작
	void Restart();

public:
	static const int MAX_STRESS = 50;

private:
	//최대 체력
	int _maxHealth = 18;

	//능력치
	int _currentHealth = 18;
	int _attack = 5;
	int _stress = 0;

	//코인
	int _coin = 10;

	//레벨 관련
	int _level = 1;
	int _nextLevelExp = 12;

	//아이템 관련
	int _itemCount[3] = { 0 };

	static const int STATUS_UP = 1;
};