#pragma once
#include "InGameScene.h"
#include "Monster.h"
#include "GameManager.h"

class BattleScene :public InGameScene
{
public:
	BattleScene() = delete;
	BattleScene(GameManager* gm);
	BattleScene(const BattleScene& other) = delete;
	BattleScene& operator=(const BattleScene& other) = delete;
	~BattleScene() = default;

	virtual Scene::SceneType Update(int input) override;
private:

	// InGameScene을(를) 통해 상속됨
	virtual void PrintHeaderInfo() const override;
	virtual void PrintMainMessage() const override;
	virtual void PrintFooterInfo() const override;

	virtual void printOptions() const override;

	void PlayerGetAttacked();
	void GetRandomMonster();

	//전투 후 처리
	void AfterCheck();
	void PlayerLevelUp();
	void StageChange();
	Scene::SceneType BattleOver();

private:
	GameManager* _gm;
	
	Monster* monsterList[3][2];
	Monster* monster;

	bool isPlayerTurn = true;
	bool isBattleMain = true;
	
	bool isAttacking = false;
	int AttackNumber = 0;

	bool isUsingItem = false;
	int itemNumber = 0;

	int playerGetDamage = 0;
	
	bool isBattleOver = false;
	bool isPlayerDied = false;
	bool isMonsterDied = false;
	bool isPlayerLevelUp = false;
	bool isStageChange = false;
	bool isGameOver = false;
	bool isGameWin = false;

	std::string resultMassage = "";
};