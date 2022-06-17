#include "HowToScene.h"
#include <iostream>
using namespace std;

void HowToScene::Render() const
{
	cout << "[How to Play]\n";
	cout << "# 선택지 이동: 숫자 입력 후 enter\n";
	cout << "\n";
	cout << "# ♥: 체력. 0이 되면 사망합니다.\n";
	cout << "# S: 스트레스. 스트레스가 높으면 더 높은 공격을 받습니다.\n";
	cout << "	 스트레스가 50에 도달하면 사망합니다.\n";
	cout << "\n";
	cout << "게임 클리어 조건: 레벨이 30이 되면 게임 클리어!\n";

	printOptions();
}

Scene::SceneType HowToScene::Update(int input)
{
	if (input != 1)
	{
		return Scene::SCENE_ERROR;
	}

	return Scene::SCENE_MAIN;
}

void HowToScene::printOptions() const
{
	cout << "1. 타이틀로\n";
}
