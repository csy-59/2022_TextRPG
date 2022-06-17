#pragma once
#include "Scene.h"

class MainScene : public Scene
{
public:
	MainScene();
	MainScene(const MainScene&) = default;
	MainScene& operator=(const MainScene&) = default;
	~MainScene() = default;

	// Scene��(��) ���� ��ӵ�
	virtual void Render() const override;

	virtual enum SceneType Update(int input);

private:
	virtual void printOptions() const override;

private:
	static const int OPTION_NUMBER = 3;
	const SceneType _optionChoose[OPTION_NUMBER] = {
		SCENE_TOWN, SCENE_HOWTOPLAY, SCENE_EXIT
	};
};