#include "MainScene.h"
#include <iostream>
using namespace std;

MainScene::MainScene()
{
	SetOptionCount(OPTION_NUMBER);
}

void MainScene::Render() const
{
	cout << "\t#############\n";
	cout << "\t##  가자,  ##\n";
	cout << "\t##   집에  ##\n";
	cout << "\t#############\n";

	printOptions();
}

Scene::SceneType MainScene::Update(int input)
{
	if (input < 1 || input > OPTION_NUMBER)
	{
		return Scene::SCENE_ERROR;
	}

	return _optionChoose[input - 1];
}

void MainScene::printOptions() const
{
	cout << "1. Start\n";
	cout << "2. How to Play\n";
	cout << "3. 나가기\n";
}
