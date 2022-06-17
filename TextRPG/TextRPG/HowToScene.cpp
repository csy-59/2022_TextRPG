#include "HowToScene.h"
#include <iostream>
using namespace std;

void HowToScene::Render() const
{
	cout << "[How to Play]\n";
	cout << "# ������ �̵�: ���� �Է� �� enter\n";
	cout << "\n";
	cout << "# ��: ü��. 0�� �Ǹ� ����մϴ�.\n";
	cout << "# S: ��Ʈ����. ��Ʈ������ ������ �� ���� ������ �޽��ϴ�.\n";
	cout << "	 ��Ʈ������ 50�� �����ϸ� ����մϴ�.\n";
	cout << "\n";
	cout << "���� Ŭ���� ����: ������ 30�� �Ǹ� ���� Ŭ����!\n";

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
	cout << "1. Ÿ��Ʋ��\n";
}
