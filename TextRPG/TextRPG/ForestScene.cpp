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

		if (_gm->GetBattleCount() % 3 == 0 && _gm->GetBattleCount() != 0)
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

	SETW_COUT << "♥: " << std::setw(SETW_NUM - 3) << std::right << _gm->GetPlayer()->GetCurrentHealth() << "/"
		<< std::right << std::setw(2) << _gm->GetPlayer()->GetMaxHealth() << " ";
	SETW_COUT << "| S: " << std::setw(SETW_NUM - 3) << std::right << _gm->GetPlayer()->GetStress() << "/"
		<< std::right << std::setw(2) << Player::MAX_STRESS << "\n";
}

void ForestScene::PrintMainMessage() const
{
	const static std::string pondMessage[2][3] = {
		"회복의 연못이다...", "연못에 동전을 던졌다.", "동전이 연못 속으로 사라져간다...",
		"주변이 고요해진다...", "집에 가고싶은 마음이 충만해졌다..!!","[ $ -10G\tS -5]"
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
		cout << "\n\t숲에 들어왔다...\n\t무엇을 할까?\n\n";
	}
}

void ForestScene::PrintFooterInfo() const
{
	return;
}

void ForestScene::printOptions() const
{
	static const std::string mainOptions[3] = {
		"몬스터와 싸운다.",
		"회복의 연못으로 향한다."
	};

	static const std::string PondOptions[3] = {
		"다음",
		"다시 숲속으로 걸어간다."
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
		cout << "상세 스탯을 확인한다.\n";

	}
}
