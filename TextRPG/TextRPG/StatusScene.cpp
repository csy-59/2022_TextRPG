#include "StatusScene.h"
#include <iostream>
using namespace std;

StatusScene::StatusScene(const Player* player)
{
	_player = player;
}

void StatusScene::Render() const
{
	cout << "| ���� Ȯ��\n";
	cout << "����: "<<_player->GetLevel()<<"(���� ����������... "<<_player->GetNextLevelExp()<<")\n";
	cout << "ü��: " << _player->GetCurrentHealth() << "/" << _player->GetMaxHealth() << "\n";
	cout << "���ݷ�: " << _player->GetAttack() << "\n";
	cout << "����: " << _player->GetDefence() << "\n";
	cout << "��Ʈ����: " << _player->GetStress() << "/" << Player::MAX_STRESS << "\n\n";

	cout << "| �ι��丮 Ȯ��\n";
	cout << "�Ѽ� X " << _player->GetHansotCount() << "\n";
	cout << "NBB X " << _player->GetNBBCount() << "\n";
	cout << "���� X " << _player->GetMonsterCount() << "\n";

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
	cout << "1. ���ư���\n";
}

