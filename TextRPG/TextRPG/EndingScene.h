#pragma once
#include "Scene.h"

class EndingScene: public Scene
{
public:
	EndingScene() = default;
	EndingScene(const EndingScene&) = default;
	EndingScene& operator=(const EndingScene&) = default;
	~EndingScene() = default;

	// Scene을(를) 통해 상속됨
	virtual void Render() const override;

	virtual enum SceneType Update(int input);

private:
	virtual void printOptions() const override;

};