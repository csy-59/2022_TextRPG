#include <iostream>
#include "Random.h"
#include "Scene.h"
#include "MainScene.h"
#include "HowToScene.h"
using namespace std;

int main()
{
	//랜덤 함수 초기화
	Random::Init();

	//씬 객체들 생성
	MainScene mainScene;
	HowToScene howToScene;

	//Scene 리스트
	//static Scene sceneList[Scene::SCENE_MAX] = {
	//	mainScene, howToScene, mainScene, mainScene
	//};

	//사용할 씬 레퍼런스
	Scene* scene = &mainScene;

	bool isGameOver = false;

	enum Scene::SceneType nextScene = Scene::SCENE_NOCHANGE;
	while (isGameOver == false)
	{
		//전처리
		system("cls");

		//화면 출력
		scene->Render();

		//입력 받기
		cout << ">> ";
		int input;
		cin >> input;

		//받은 입력으로 업데이트
		nextScene = scene->Update(input);

		//씬 후처리
		if (nextScene == Scene::SCENE_EXIT) //게임 종료이면 게임을 종료시킴
		{
			isGameOver = true;
		}
		else if (nextScene != Scene::SCENE_NOCHANGE) //게임 씬에 전환이 없는 경우 씬을 전환하지 않음
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
	cout << "#  학원에서 요절했다. #\n";
	cout << "#######################\n";

	return 0;
}