#include <iostream>
#include "Random.h"
#include "Scene.h"
#include "MainScene.h"
#include "HowToScene.h"
#include "TownScene.h"
#include "StatusScene.h"
#include "StoreScene.h"
#include "ForestScene.h"
#include "BattleScene.h"
#include "EndingScene.h"
using namespace std;


int main()
{
	//���� �Լ� �ʱ�ȭ
	Random::Init();

	//Game����
	GameManager gameManager;

	//�� ��ü�� ����
	MainScene mainScene(&gameManager);
	HowToScene howToScene;

	TownScene townScene(&gameManager);
	StatusScene statusScene(&gameManager);
	StoreScene storeScene(&gameManager);
	ForestScene forestScene(&gameManager);
	BattleScene battleScene(&gameManager);
	
	EndingScene endingScene;

	//Scene ����Ʈ
	static Scene* sceneList[Scene::SCENE_MAX] = {
		&mainScene, &howToScene, 
		&townScene, &storeScene, &forestScene, & battleScene, &statusScene,
		&endingScene
	};

	//����� �� ���۷���
	Scene* scene = &mainScene;

	bool isGameOver = false;

	enum Scene::SceneType nextScene = Scene::SCENE_NOCHANGE;
	enum Scene::SceneType currentScene = Scene::SCENE_MAIN;
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
		statusScene.UpdatePreScene(currentScene);

		if (nextScene == Scene::SCENE_ERROR)
		{
			continue;
		}

		if (nextScene == Scene::SCENE_EXIT) //���� �����̸� ������ �����Ŵ
		{
			isGameOver = true;
		}
		else if (nextScene != Scene::SCENE_NOCHANGE) //���� ���� ��ȯ�� ���� ��� ���� ��ȯ���� ����
		{
			scene = sceneList[nextScene];
			currentScene = nextScene;
			scene->Init();
		}
	}

	system("cls");
	cout << "#######################\n";
	cout << "#      Game Over      #\n";
	cout << "#  �п����� �����ߴ�. #\n";
	cout << "#######################\n";

	return 0;
}