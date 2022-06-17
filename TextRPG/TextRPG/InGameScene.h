#pragma once
#include "Scene.h"

class InGameScene :public Scene
{
public:
	virtual void Render();
private:
	virtual void PrintHeaderInfo() const = 0;
	virtual void PrintMainMessage() const = 0;
	virtual void PrintFooterInfo() const = 0;
};