#pragma once
#include "Scene.h"
#include "Player.h"
#include "GameManager.h"

class StatusScene : public Scene
{
public:
	StatusScene() = delete;
	StatusScene(const GameManager* gm);
	StatusScene(const StatusScene& other) = default;
	~StatusScene() = default;

	// Scene을(를) 통해 상속됨
	virtual void Render() const override;

	virtual enum SceneType Update(int input);

	static void UpdatePreScene(Scene::SceneType preScene);

private:
	virtual void printOptions() const override;

private:
	const GameManager* _gm = nullptr;
	static Scene::SceneType _previousScene;
};