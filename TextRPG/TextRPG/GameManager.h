#pragma once
#include "Player.h"
#include "Monster.h"
#include <string>

class GameManager
{
public:
	GameManager();
	GameManager(const GameManager& other) = delete;
	GameManager& operator=(const GameManager& other) = delete;
	~GameManager();

	int GetStageNumber() const;
	int GetBattleCount() const;
	const Player* GetPlayer() const;
	Player* GetPlayer();

	const Item* GetItem(Item::ItemType itemtype) const;
	int GetStatPoint() const;
	void SetStatPoint(int StatPoint) ;

	void StartBattle();
	std::string UseItem(Item::ItemType itemType);
	void UseStatPoint();
	void StageUp();

	void Restart();

private:
	//스테이지 관련 정보
	//스테이지
	int _stage = 1;
	int _battleCount = 0;

	//플레이어 기본 정보
	Player _player;
	int _statPoint = 0;

	//아이템 종류
	Item* _items[Item::ITEM_MAX];
};