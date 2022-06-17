#include <iostream>
#include "Random.h"
#include "Scene.h"
#include "MainScene.h"
#include "HowToScene.h"
using namespace std;

int main()
{
	//���� �Լ� �ʱ�ȭ
	Random::Init();

	//�� ��ü�� ����
	MainScene mainScene;
	HowToScene howToScene;

	//Scene ����Ʈ
	//static Scene sceneList[Scene::SCENE_MAX] = {
	//	mainScene, howToScene, mainScene, mainScene
	//};

	//����� �� ���۷���
	Scene* scene = &mainScene;

	bool isGameOver = false;

	enum Scene::SceneType nextScene = Scene::SCENE_NOCHANGE;
	while (isGameOver == false)
	{
		//��ó��
		system("cls");

		//ȭ�� ���
		scene->Render();

		//�Է� �ޱ�
		cout << ">> ";
		int input;
		cin >> input;

		//���� �Է����� ������Ʈ
		nextScene = scene->Update(input);

		//�� ��ó��
		if (nextScene == Scene::SCENE_EXIT) //���� �����̸� ������ �����Ŵ
		{
			isGameOver = true;
		}
		else if (nextScene != Scene::SCENE_NOCHANGE) //���� ���� ��ȯ�� ���� ��� ���� ��ȯ���� ����
		{
			switch (nextScene)
			{
			case Scene::SCENE_MAIN:
				scene = &mainScene;
				break;
			case Scene::SCENE_HOWTOPLAY:
				scene = &howToScene;
				break;
			case Scene::SCENE_TOWN:
				scene = &mainScene;
				break;
			case Scene::SCENE_STAT:
				scene = &mainScene;
				break;
			case Scene::SCENE_STORE:
				scene = &mainScene;
				break;
			case Scene::SCENE_BATTLE:
				scene = &mainScene;
				break;
			case Scene::SCENE_HEALING:
				scene = &mainScene;
				break;
			}
		}
	}

	system("cls");
	cout << "#######################\n";
	cout << "#      Game Over      #\n";
	cout << "#  �п����� �����ߴ�. #\n";
	cout << "#######################\n";

	return 0;
}