#pragma once
#include "Item.h"

class NBB_Item :public Item
{
public:
	NBB_Item();
	NBB_Item(const NBB_Item& other) = delete;
	NBB_Item& operator=(const NBB_Item& other) = delete;
	~NBB_Item() = default;

	virtual void UseItem();
};