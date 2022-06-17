#pragma once
#include "Scene.h"

class HowToScene : public Scene
{
public:
	HowToScene() = default;
	HowToScene(const HowToScene&) = default;
	HowToScene& operator=(const HowToScene&) = default;
	~HowToScene() = default;

	// Scene을(를) 통해 상속됨
	virtual void Render() const override;

	virtual enum SceneType Update(int input);

private:
	virtual void printOptions() const override;
};