#include <iostream>
#include "Random.h"
#include "Scene.h"
#include "MainScene.h"
using namespace std;

int main()
{
	//���� �Լ� �ʱ�ȭ
	Random::Init();

	MainScene mainScene;

	//Scene ����Ʈ
	static const Scene sceneList[Scene::SCENE_MAX] = {
		mainScene, mainScene, mainScene, mainScene
	};

	//����� �� ���۷���
	Scene& scene = mainScene;

	bool isGameOver = false;

	enum Scene::SceneType nextScene = Scene::SCENE_NOCHANGE;
	while (isGameOver == false)
	{
		system("cls");
		
		scene.Render();

		int input;
		cin >> input;

		nextScene = scene.Update(input);

		if (nextScene == Scene::SCENE_EXIT) //���� �����̸� ������ �����Ŵ
		{
			isGameOver = true;
		}
		else if (nextScene != Scene::SCENE_NOCHANGE) //���� ���� ��ȯ�� ���� ��� ���� ��ȯ���� ����
		{
			//�� ��ȯ
			scene = sceneList[nextScene];
		}
	}

	system("cls");

	return 0;
}