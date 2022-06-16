#include <iostream>
#include "Random.h"
#include "Scene.h"
#include "MainScene.h"
using namespace std;

int main()
{
	//랜덤 함수 초기화
	Random::Init();

	MainScene mainScene;

	//Scene 리스트
	static const Scene sceneList[Scene::SCENE_MAX] = {
		mainScene, mainScene, mainScene, mainScene
	};

	//사용할 씬 레퍼런스
	Scene& scene = mainScene;

	bool isGameOver = false;

	while (isGameOver == false)
	{
		scene.Render();

		Scene::SceneType
	}

	return 0;
}