#pragma once

#include "Scene.h"

class SceneManager
{
public:
	SceneManager() = default;
	SceneManager(const SceneManager& other) = delete;
	SceneManager& operator=(const SceneManager& other) = delete;
	~SceneManager() = default;

	void Init();
	void Render();
	void Update(int input);
	bool isSceneChanged();
	bool isGameOver();
	void SceneChange();

private:
	Scene currentScene;
	Scene::SceneType nextScene = Scene::SCENE_MAIN;
	static const Scene* sceneList[Scene::SCENE_MAX];
};