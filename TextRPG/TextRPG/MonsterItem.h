#pragma once
#include "Item.h"

class Monster_Item :public Item
{
public:
	Monster_Item();
	Monster_Item(const Monster_Item& other) = delete;
	Monster_Item& operator=(const Monster_Item& other) = delete;
	~Monster_Item() = default;

	virtual std::string UseItem(Player* player) override;
};