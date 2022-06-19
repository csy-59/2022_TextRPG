#include <iostream>
#include "Random.h"
#include "Scene.h"
#include "MainScene.h"
#include "HowToScene.h"
#include "TownScene.h"
#include "StatusScene.h"
#include "StoreScene.h"
using namespace std;


int main()
{
	//���� �Լ� �ʱ�ȭ
	Random::Init();

	//Game����
	GameManager gameManager;

	//�� ��ü�� ����
	MainScene mainScene;
	HowToScene howToScene;
	TownScene townScene(&gameManager);
	StatusScene statusScene(&gameManager);
	StoreScene storeScene(&gameManager);

	//Scene ����Ʈ
	static Scene* sceneList[Scene::SCENE_MAX] = {
		&mainScene, &howToScene, 
		&townScene, &storeScene, &townScene, &townScene, &statusScene
	};

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
		}
	}

	system("cls");
	cout << "#######################\n";
	cout << "#      Game Over      #\n";
	cout << "#  �п����� �����ߴ�. #\n";
	cout << "#######################\n";

	return 0;
}