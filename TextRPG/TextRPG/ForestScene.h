#pragma once
#include "InGameScene.h"
#include "GameManager.h"

class ForestScene: public InGameScene
{
public:
	ForestScene() = delete;
	ForestScene(GameManager* gm);
	ForestScene(const ForestScene& other) = delete;
	ForestScene& operator=(const ForestScene& other) = delete;
	~ForestScene() = default;

	virtual Scene::SceneType Update(int input) override;
private:
	// InGameScene을(를) 통해 상속됨
	virtual void PrintHeaderInfo() const override;

	virtual void PrintMainMessage() const override;

	virtual void PrintFooterInfo() const override;

	virtual void printOptions() const override;

private:
	GameManager* _gm;
	bool _isInPond = false;
	int _pondSceneCount = 0;
};