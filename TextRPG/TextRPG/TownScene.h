#pragma once
#include "InGameScene.h"
#include "GameManager.h"

class TownScene : public InGameScene
{
public:
	TownScene() = delete;
	TownScene(const GameManager* gm);
	TownScene(const TownScene& other) = default;
	TownScene& operator=(const TownScene& other) = default;
	~TownScene() = default;

	virtual enum SceneType Update(int input);

private:

	// InGameScene을(를) 통해 상속됨
	virtual void PrintHeaderInfo() const override;

	virtual void PrintMainMessage() const override;

	virtual void PrintFooterInfo() const override;

	virtual void printOptions() const override;

private:
	const GameManager* _gm;
	static const int OPTION_COUNT = 3;
	const SceneType _optionsNextScene[OPTION_COUNT] = {
		SCENE_FOREST, SCENE_STORE, SCENE_STAT
	};
};