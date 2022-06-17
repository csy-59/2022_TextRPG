#pragma once
#include "Scene.h"

class InGameScene :public Scene
{
public:
	InGameScene() = default;
	InGameScene(const InGameScene& other) = default;
	InGameScene& operator=(const InGameScene& other) = default;
	~InGameScene() = default;

	virtual void Render();
private:
	virtual void PrintHeaderInfo() const = 0;
	virtual void PrintMainMessage() const = 0;
	virtual void PrintFooterInfo() const = 0;
public:
	static const int SETW_NUM = 23;
};