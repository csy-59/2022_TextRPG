#pragma once
#include "Player.h"
#include <string>

class Item
{
public:
	static enum ItemType {
		ITEM_HANSOT,
		ITEM_NBB,
		ITEM_MONSTER,
		ITEM_MAX
	};

public:
	Item() = default;
	Item(const Item& other) = default;
	Item& operator=(const Item& other) = default;
	~Item() = default;

	//getter
	std::string GetName() const;
	std::string GetInfo() const;
	int GetPrice() const;

	virtual std::string UseItem(class Player* player);

protected:
	//setter
	void SetName(const std::string name);
	void SetInfo(const std::string info);
	void SetPrice(const int price);


private:
	std::string _name = "";
	std::string _info = "";
	int _price = 0;
};