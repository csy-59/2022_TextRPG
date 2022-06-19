#include "Player.h"
#include "GameManager.h"

Player::Player()
{
}

Player::~Player()
{
}

int Player::GetMaxHealth() const
{
	return _maxHealth;
}

int Player::GetCurrentHealth() const
{
	return _currentHealth;
}

int Player::GetAttack() const
{
	return _attack;
}

int Player::GetDefence() const
{
	return _defence;
}

int Player::GetStress() const
{
	return _stress;
}

int Player::GetLevel() const
{
	return _level;
}

int Player::GetNextLevelExp() const
{
	return _nextLevelExp;
}

int Player::GetCoinCount() const
{
	return _coin;
}

const int* Player::GetItemCount() const
{
	return _itemCount;
}

void Player::BuyItem(const Item::ItemType itemNumber, const int price)
{
	_coin -= price;
	++_itemCount[itemNumber];
}

void Player::GotToPond()
{
	_coin -= 10;
	_stress -= 5;
}

