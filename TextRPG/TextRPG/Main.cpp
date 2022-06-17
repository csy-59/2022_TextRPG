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

	enum Scene::SceneType nextScene = Scene::SCENE_NOCHANGE;
	while (isGameOver == false)
	{
		system("cls");
		
		scene.Render();

		int input;
		cin >> input;

		nextScene = scene.Update(input);

		if (nextScene == Scene::SCENE_EXIT) //게임 종료이면 게임을 종료시킴
		{
			isGameOver = true;
		}
		else if (nextScene != Scene::SCENE_NOCHANGE) //게임 씬에 전환이 없는 경우 씬을 전환하지 않음
		{
			//씬 전환
			scene = sceneList[nextScene];
		}
	}

	system("cls");

	return 0;
}