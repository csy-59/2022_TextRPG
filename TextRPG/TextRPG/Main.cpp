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

	while (isGameOver == false)
	{
		scene.Render();

		Scene::SceneType
	}

	return 0;
}