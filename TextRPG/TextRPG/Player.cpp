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

void Player::BuyItem(const int itemNumber, const int price)
{
	_coin -= price;
	++_itemCount[itemNumber];
}

void Player::UseItem(int itemNumber)
{
	--_itemCount[itemNumber];
}

void Player::GotToPond()
{
	_coin -= 10;
	_stress -= 5;

	if (_stress < 0)
	{
		_stress = 0;
	}
}

void Player::AddStress(int inputStress)
{
	_stress += inputStress;
}

void Player::GotDamageFromMonster(int inputDamage)
{
	_currentHealth -= inputDamage;

	if (_currentHealth < 0)
	{
		_currentHealth = 0;
	}
}

int Player::GotCured(float gainHealth)
{
	int result = _currentHealth;

	_currentHealth *= gainHealth;

	result = _currentHealth - result;
	if (result < 3)
	{
		result = 3;
		_currentHealth += 3;
	}

	if (_currentHealth > _maxHealth)
	{
		_currentHealth = _maxHealth;
	}

	return result;
}

void Player::GotCoin(int gainCoin)
{
	_coin += gainCoin;
}

void Player::GotEXP(int gainEXP)
{
	_nextLevelExp -= gainEXP;
}

void Player::AddHealth()
{
	_maxHealth += STATUS_UP;
	_currentHealth = _maxHealth;
}

void Player::AddAttack()
{
	_attack += STATUS_UP;
}

void Player::LevelUp()
{
	++_level;
	switch (_level / 5)
	{
	case 0:
		_nextLevelExp = 10 + _level * 2;
		break;
	case 1:
		_nextLevelExp = 20 + _level;
		break;
	case 2:
		_nextLevelExp = 30 + _level * 0.5f;
		break;
	}
}

void Player::Restart()
{
	//최대 체력
	int _maxHealth = 18;

	//능력치
	_currentHealth = 18;
	_attack = 5;
	_stress = 0;

	//코인
	_coin = 10;

	//레벨 관련
	_level = 1;
	_nextLevelExp = 12;

	//아이템 관련
	 _itemCount[0] = 0;
	 _itemCount[1] = 0;
	 _itemCount[2] = 0;
}

