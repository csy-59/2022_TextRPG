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
	//�������� ���� ����
	//��������
	int _stage = 1;
	int _battleCount = 0;

	//�÷��̾� �⺻ ����
	Player _player;
	int _statPoint = 0;

	//������ ����
	Item* _items[Item::ITEM_MAX];
};