#pragma once
#include "Player.h"
#include "Monster.h"
#include <string>

class GameManager
{
public:
	int GetStageNumber() const;
	int GetBattleCount() const;
	Player& GetPlayer() const;

private:
	//스테이지 관련 정보
	//스테이지
	int _stage = 1;
	int _battleCount = 0;

	//플레이어 기본 정보
	Player* _player;
	
};