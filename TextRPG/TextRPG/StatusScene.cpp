#include "StatusScene.h"
#include <iostream>
using namespace std;

StatusScene::StatusScene(const Player* player)
{
	_player = player;
}

void StatusScene::Render() const
{
	cout << "| 스탯 확인\n";
	cout << "레벨: "<<_player->GetLevel()<<"(다음 레벨업까지... "<<_player->GetNextLevelExp()<<")\n";
	cout << "체력: " << _player->GetCurrentHealth() << "/" << _player->GetMaxHealth() << "\n";
	cout << "공격력: " << _player->GetAttack() << "\n";
	cout << "방어력: " << _player->GetDefence() << "\n";
	cout << "스트레스: " << _player->GetStress() << "/" << Player::MAX_STRESS << "\n\n";

	cout << "| 인밴토리 확인\n";
	cout << "한솥 X " << _player->GetHansotCount() << "\n";
	cout << "NBB X " << _player->GetNBBCount() << "\n";
	cout << "몬스터 X " << _player->GetMonsterCount() << "\n";

	printOptions();
}

Scene::SceneType StatusScene::Update(int input)
{
	if (input != 1)
	{
		return Scene::SCENE_ERROR;
	}

	return Scene::SCENE_TOWN;
}

void StatusScene::printOptions() const
{
	cout << "1. 돌아가기\n";
}

