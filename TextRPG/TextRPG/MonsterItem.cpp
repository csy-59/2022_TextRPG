#include "MonsterItem.h"

Monster_Item::Monster_Item()
{
	SetName("¸ó½ºÅÍ");
	SetInfo("¢¾+2.0, S +1");
	SetPrice(12);
}

std::string Monster_Item::UseItem(Player* player)
{
	player->AddStress(1);

	std::string result = "¢¾ +" + 
		std::to_string(player->GotCured(2.0f)) + "  S +1";
	return result;
}
