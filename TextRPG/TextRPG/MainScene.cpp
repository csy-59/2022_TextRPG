#include "MainScene.h"
#include <iostream>
using namespace std;

MainScene::MainScene(GameManager* gm)
	:_gm(gm) 
{
	SetOptionCount(OPTION_NUMBER);
}

void MainScene::Init()
{
	_gm->Restart();
}

void MainScene::Render() const
{
	cout << "###################\n";
	cout << "##     가자,     ##\n";
	cout << "##      집에     ##\n";
	cout << "###################\n";

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
