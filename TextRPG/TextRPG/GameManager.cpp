#include "GameManager.h"
#include "HansotItem.h"
#include "MonsterItem.h"
#include "NBBItem.h"

GameManager::GameManager()
{
    _items[Item::ITEM_HANSOT] = new Hansot_Item;
    _items[Item::ITEM_NBB] = new NBB_Item;
    _items[Item::ITEM_MONSTER] = new Monster_Item;
}

GameManager::~GameManager()
{
    for (int i = 0; i < Item::ITEM_MAX; ++i)
    {
        delete _items[i];
    }
}

int GameManager::GetStageNumber() const
{
    return _stage;
}

int GameManager::GetBattleCount() const
{
    return _battleCount;
}

const Player* GameManager::GetPlayer() const
{
    return &_player;
}

Player* GameManager::GetPlayer()
{
    return &_player;
}

const Item* GameManager::GetItem(Item::ItemType itemtype) const
{
    return _items[itemtype];
}

int GameManager::GetStatPoint() const
{
    return _statPoint;
}

void GameManager::SetStatPoint(int StatPoint)
{
    _statPoint = StatPoint;
}

void GameManager::StartBattle()
{
    ++_battleCount;
    _player.AddStress(_stage);
}

std::string GameManager::UseItem(Item::ItemType itemType)
{
    if (itemType < 0 || itemType >= Item::ITEM_MAX) {
        return "";
    }

    return _items[itemType]->UseItem(&_player);
}

void GameManager::UseStatPoint()
{
    --_statPoint;
}

void GameManager::StageUp()
{
    ++_stage;
    _player.AddStress(_player.GetStress() / 0.3f);
    _battleCount = 0;
}

void GameManager::Restart()
{
    _stage = 1;
    _battleCount = 0;
    _statPoint = 0;

    _player.Restart();
}
