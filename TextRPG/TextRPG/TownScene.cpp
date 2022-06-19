#include "TownScene.h"
#include <iostream>
#include <iomanip>
using namespace std;

TownScene::TownScene(const GameManager* gm)
{
	_gm = gm;
}

Scene::SceneType TownScene::Update(int input)
{
	if (input < 1 || input > OPTION_COUNT)
	{
		return Scene::SCENE_ERROR;
	}

	return _optionsNextScene[input - 1];
}

void TownScene::PrintHeaderInfo() const
{
	SETW_COUT << "Stage " << std::setw(SETW_NUM) << std::right << _gm->GetStageNumber()<<" ";
	SETW_COUT << "| Battle " << std::setw(SETW_NUM) << std::right << _gm->GetBattleCount() << "\n";

	SETW_COUT << "Lev. " << std::setw(SETW_NUM) << std::right << _gm->GetPlayer()->GetLevel() << " ";
	SETW_COUT << "| $ " << std::setw(SETW_NUM - 1) << std::right << _gm->GetPlayer()->GetCoinCount() << "G\n";

	SETW_COUT << "��: " << std::setw(SETW_NUM - 3) << std::right << _gm->GetPlayer()->GetCurrentHealth() << "/" 
		<< std::right <<std::setw(2) << _gm->GetPlayer()->GetMaxHealth() << " ";
	SETW_COUT << "| S: " << std::setw(SETW_NUM - 3) << std::right << _gm->GetPlayer()->GetStress() << "/" 
		<< std::right << std::setw(2) << Player::MAX_STRESS << "\n";
}

void TownScene::PrintMainMessage() const
{
	static const std::string mainMessages[2] = {
		"�����̴�...\n",
		"������ �ұ�?\n"
	};

	cout << "\n";
	cout << "\t" + mainMessages[0];
	cout << "\t" + mainMessages[1];
	cout << "\n";
}

void TownScene::PrintFooterInfo() const
{
	return;
}

void TownScene::printOptions() const
{
	static const std::string options[OPTION_COUNT] = {
		"������ ���Ѵ�.\n",
		"�������� ���Ѵ�.\n",
		"�� ������ Ȯ���Ѵ�.\n",
	};

	for (int i = 0; i < OPTION_COUNT; i++)
	{
		cout << (i + 1) << ". " + options[i];
	}
}
