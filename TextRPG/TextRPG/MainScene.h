#pragma once
#include "Scene.h"
#include "GameManager.h"

class MainScene : public Scene
{
public:
	MainScene() = delete;
	MainScene(GameManager* gm);
	MainScene(const MainScene&) = default;
	MainScene& operator=(const MainScene&) = default;
	~MainScene() = default;

	// Scene을(를) 통해 상속됨
	virtual void Init() override;

	virtual void Render() const override;

	virtual enum SceneType Update(int input);

private:
	virtual void printOptions() const override;

private:
	GameManager* _gm;
	static const int OPTION_NUMBER = 3;
	const SceneType _optionChoose[OPTION_NUMBER] = {
		SCENE_TOWN, SCENE_HOWTOPLAY, SCENE_EXIT
	};
};