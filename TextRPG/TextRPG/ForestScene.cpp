#include "ForestScene.h"
#include <iostream>
#include <iomanip>
using namespace std;

ForestScene::ForestScene(GameManager* gm)
	:_gm(gm) {}

Scene::SceneType ForestScene::Update(int input)
{
	if (_isInPond)
	{
		if (input != 1)
		{
			return Scene::SCENE_ERROR;
		}

		if (_pondSceneCount == 0)
		{
			++_pondSceneCount;
			_isInPond = true;
			_gm->GetPlayer()->GotToPond();
		}
		else
		{
			_isInPond = false;
			_pondSceneCount = 0;
		}

		return Scene::SCENE_NOCHANGE;
	}
	else
	{
		if (input == 1)
		{
			_gm->StartBattle();
			return Scene::SCENE_BATTLE;
		}

		if (_gm->GetBattleCount() % 3 == 0 && _gm->GetBattleCount() != 0 && _gm->GetPlayer()->GetCoinCount() >= 10)
		{
			if (input < 2 || input > 3)
			{
				return Scene::SCENE_ERROR;
			}

			if (input == 2)
			{
				_isInPond = true;
				_pondSceneCount = 0;
				return Scene::SCENE_NOCHANGE;
			}
			else if (input == 3)
			{
				return Scene::SCENE_STAT;
			}
		}
		else
		{
			if (input != 2)
			{
				return Scene::SCENE_ERROR;
			}

			return Scene::SCENE_STAT;
		}
	}
}

void ForestScene::PrintHeaderInfo() const
{
	SETW_COUT << "Stage " << std::setw(SETW_NUM) << std::right << _gm->GetStageNumber() << " ";
	SETW_COUT << "| Battle " << std::setw(SETW_NUM) << std::right << _gm->GetBattleCount() << "\n";

	SETW_COUT << "Lev. " << std::setw(SETW_NUM) << std::right << _gm->GetPlayer()->GetLevel() << " ";
	SETW_COUT << "| $ " << std::setw(SETW_NUM - 1) << std::right << _gm->GetPlayer()->GetCoinCount() << "G\n";

	SETW_COUT << "��: " << std::setw(SETW_NUM - 2) << std::right << _gm->GetPlayer()->GetCurrentHealth() << "/"
		<< std::right << std::setw(2) << _gm->GetPlayer()->GetMaxHealth() << " ";
	SETW_COUT << "| S: " << std::setw(SETW_NUM - 3) << std::right << _gm->GetPlayer()->GetStress() << "/"
		<< std::right << std::setw(2) << Player::MAX_STRESS << "\n";
}

void ForestScene::PrintMainMessage() const
{
	const static std::string pondMessage[2][3] = {
		"ȸ���� �����̴�...", "������ ������ ������.", "������ ���� ������ ���������...",
		"�ֺ��� ���������...", "���� ������� ������ �游������..!!","[ $ -10G\tS -5]"
	};

	if (_isInPond)
	{
		cout << "\n";
		for (int i = 0; i < 3; ++i)
		{
			cout << "\t" + pondMessage[_pondSceneCount][i] << "\n";
		}
		cout << "\n";
	}
	else
	{
		cout << "\n\t���� ���Դ�...\n\t������ �ұ�?\n\n";
	}
}

void ForestScene::PrintFooterInfo() const
{
	return;
}

void ForestScene::printOptions() const
{
	static const std::string mainOptions[3] = {
		"���Ϳ� �ο��.",
		"ȸ���� �������� ���Ѵ�."
	};

	static const std::string PondOptions[3] = {
		"����",
		"�ٽ� �������� �ɾ��."
	};

	if (_isInPond)
	{
		cout << "1. " << PondOptions[_pondSceneCount] << "\n";
	}
	else
	{
		cout << "1. " << mainOptions[0] << "\n";
		if (_gm->GetBattleCount() % 3 == 0 && _gm->GetBattleCount() != 0 && _gm->GetPlayer()->GetCoinCount() >= 10)
		{
			cout << "2. " << mainOptions[1] << "\n";
			cout << "3. ";
		}
		else
		{
			cout << "2. ";
		}
		cout << "�� ������ Ȯ���Ѵ�.\n";

	}
}
