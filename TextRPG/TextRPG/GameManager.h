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
	//�������� ���� ����
	//��������
	int _stage = 1;
	int _battleCount = 0;

	//�÷��̾� �⺻ ����
	Player* _player;
	
};