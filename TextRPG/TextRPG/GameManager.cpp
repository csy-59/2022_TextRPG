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

void GameManager::StartBattle()
{
    ++_battleCount;
}
