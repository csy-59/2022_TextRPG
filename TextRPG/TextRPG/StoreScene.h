#pragma once
#include "InGameScene.h"
#include "GameManager.h"

class StoreScene: public InGameScene
{
public:
	StoreScene() = delete;
	StoreScene(GameManager* gm);
	StoreScene(const StoreScene& other) = delete;
	StoreScene& operator=(const StoreScene& other) = delete;
	~StoreScene() = default;

	virtual enum SceneType Update(int input);
private:
	// InGameScene을(를) 통해 상속됨
	virtual void PrintHeaderInfo() const override;

	virtual void PrintMainMessage() const override;

	virtual void PrintFooterInfo() const override;

	virtual void printOptions() const override;

	void ShowMainStore() const;
	void BuyItem() const;
	void ShowItems() const;
	void ShowBuyOptions() const;
private:
	GameManager* _gm;
	bool _isBuying = false;
	Item::ItemType _selectItem = Item::ITEM_MAX;
};