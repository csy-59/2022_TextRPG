#include "InGameScene.h"
#include <iostream>

void InGameScene::Render() const
{
	PrintHeaderInfo();
	std::cout << "-----------------------------------\n";
	PrintMainMessage();
	std::cout << "-----------------------------------\n";
	PrintFooterInfo();

	printOptions();
}