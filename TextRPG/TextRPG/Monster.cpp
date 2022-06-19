#include "Monster.h"
#include "Random.h"

int Monster::Damage()
{
    return Random::GetRandomNumberFromRange(_minAttackDamage, _maxAttackDamage);
}

int Monster::GetMaxHealth()
{
    return _maxHealth;
}

int Monster::GetCurrentHealth()
{
    return _currentHealth;
}

void Monster::GetAttacked(int damage)
{
    _currentHealth -= damage;
    if (_currentHealth < 0)
    {
        _currentHealth = 0;
    }
}

int Monster::DropCoin()
{
    if (Random::GetRandomNumberFromRange(1, 100) <= _dropRate)
    {
        return _dropCoin;
    }

    return 0;
}

Monster::Monster(std::string name, std::string introduce, std::string attackNoise, int maxHealth, int currentHealth, int maxAttackDamage, int minAttackDame, int dropRate, int dropCoin)
{
    _name = name;
    _introduce = introduce;
    _attackNoise = attackNoise;

    _maxHealth = maxHealth;
    _currentHealth = currentHealth;
    _maxAttackDamage = maxAttackDamage;
    _minAttackDamage = minAttackDame;
    
    _dropRate = dropRate;
    _dropCoin = dropCoin;
}

void Monster::SetName(std::string name)
{
    _name = name;
}

void Monster::SetIntorduceString(std::string introduce)
{
    _introduce = introduce;
}

void Monster::SetAttackNoise(std::string attckNoise)
{
    _attackNoise = attckNoise;
}

void Monster::SetMaxHealth(int max)
{
    _maxHealth = max;
}

void Monster::SetCurrentHealth(int cur)
{
    _currentHealth = cur;
}

void Monster::SetMaxAttackDamage(int maxA)
{
    _maxAttackDamage = maxA;
}

void Monster::SetMinAttackDamage(int minA)
{
    _minAttackDamage = minA;
}

void Monster::SetDropRate(int drate)
{
    _dropRate = drate;
}

void Monster::SetDropCoin(int dcoin)
{
    _dropCoin = dcoin;
}

std::string Monster::GetName()
{
    return _name;
}

std::string Monster::GetIntroduceString()
{
    return _introduce;
}

std::string Monster::GetAttackNoise()
{
    return _attackNoise;
}
