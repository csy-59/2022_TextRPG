#include "EndingScene.h"
#include <iostream>

void EndingScene::Render() const
{
	std::cout << "##############################\n";
	std::cout << "\n\tGame Clear!!\n";
	std::cout << "\tHome, Sweat Home...\n\n";
	std::cout << "##############################\n";

	printOptions();
}

Scene::SceneType EndingScene::Update(int input)
{
	return Scene::SCENE_MAIN;
}

void EndingScene::printOptions() const
{
	std::cout << "1. Restart\n";
}
