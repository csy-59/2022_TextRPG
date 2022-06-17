#include "TownScene.h"
#include <iostream>
#include <iomanip>
using namespace std;

Scene::SceneType TownScene::Update(int input)
{
	return SceneType();
}

void TownScene::PrintHeaderInfo() const
{
	cout << std::left << std::setw(InGameScene::SETW_NUM) << "Stage " << _gm->GetStageNumber();
	cout << std::left << std::setw(InGameScene::SETW_NUM) << "Battle " << _gm->GetStageNumber() << "\n";
	cout << std::left << std::setw(InGameScene::SETW_NUM) << "Lev. " << _gm->GetPlayer().GetLevel();
	cout << std::left << std::setw(InGameScene::SETW_NUM) << "$ " << _gm->GetPlayer().GetCoinCount() << "G\n";
	cout << std::left << std::setw(InGameScene::SETW_NUM) << "¢¾: " << _gm->GetPlayer().GetCoinCount() << "G\n";
}

void TownScene::PrintMainMessage() const
{
}

void TownScene::PrintFooterInfo() const
{
	return;
}
