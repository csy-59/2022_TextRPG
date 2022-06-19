#include "Item.h"
#include <iostream>

std::string Item::GetName() const
{
    return _name;
}

std::string Item::GetInfo() const
{
    return _info;
}

int Item::GetPrice() const
{
    return _price;
}

void Item::SetName(const std::string name)
{
    _name = name;
}

void Item::SetInfo(const std::string info)
{
    _info = info;
}

void Item::SetPrice(const int price)
{
    _price = price;
}

void Item::UseItem()
{
    std::cout << "ERROR!!! WORNG ITEM USES\n";
    return;
}
