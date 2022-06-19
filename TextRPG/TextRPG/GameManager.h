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

	void StartBattle();

private:
	//�������� ���� ����
	//��������
	int _stage = 1;
	int _battleCount = 0;

	//�÷��̾� �⺻ ����
	Player _player;

	//������ ����
	Item* _items[Item::ITEM_MAX];
};