#pragma once
#include "Scene.h"
#define SETW_COUT cout << std::left << std::setw(InGameScene::SETW_NUM)

class InGameScene :public Scene
{
public:
	InGameScene() = default;
	InGameScene(const InGameScene& other) = default;
	InGameScene& operator=(const InGameScene& other) = default;
	~InGameScene() = default;

	virtual void Render() const;
private:
	virtual void PrintHeaderInfo() const = 0;
	virtual void PrintMainMessage() const = 0;
	virtual void PrintFooterInfo() const = 0;
public:
	static const int SETW_NUM = 8;
};