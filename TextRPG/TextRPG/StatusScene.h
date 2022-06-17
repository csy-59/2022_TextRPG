#pragma once
#include "Scene.h"
#include "Player.h"

class StatusScene : public Scene
{
public:
	StatusScene() = delete;
	StatusScene(const Player* player);
	StatusScene(const StatusScene& other) = default;
	~StatusScene() = default;

	// Scene��(��) ���� ��ӵ�
	virtual void Render() const override;

	virtual enum SceneType Update(int input);

private:
	virtual void printOptions() const override;

private:
	const Player* _player = nullptr;
};