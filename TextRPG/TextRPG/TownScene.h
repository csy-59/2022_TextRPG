#pragma once
#include "InGameScene.h"
#include "GameManager.h"

class TownScene : public InGameScene
{
	virtual enum SceneType Update(int input);

private:

	// InGameScene��(��) ���� ��ӵ�
	virtual void PrintHeaderInfo() const override;

	virtual void PrintMainMessage() const override;

	virtual void PrintFooterInfo() const override;

private:
	GameManager* _gm;
};