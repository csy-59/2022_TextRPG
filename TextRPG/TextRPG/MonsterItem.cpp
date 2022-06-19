#include "MonsterItem.h"

Monster_Item::Monster_Item()
{
	SetName("����");
	SetInfo("��+2.0, S +1");
	SetPrice(12);
}

std::string Monster_Item::UseItem(Player* player)
{
	player->AddStress(1);

	std::string result = "�� +" + 
		std::to_string(player->GotCured(2.0f)) + "  S +1";
	return result;
}
