#pragma once
#include "Item.h"

class Hansot_Item :public Item
{
public:
	Hansot_Item();
	Hansot_Item(const Hansot_Item& other) = delete;
	Hansot_Item& operator=(const Hansot_Item& other) = delete;
	~Hansot_Item() = default;

	virtual std::string UseItem(Player* player) override;
};