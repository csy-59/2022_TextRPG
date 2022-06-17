#include "GameManager.h"

int GameManager::GetStageNumber() const
{
    return _stage;
}

int GameManager::GetBattleCount() const
{
    return _battleCount;
}

Player& GameManager::GetPlayer() const
{
    return *_player;
}
