#pragma once
#include <string>
#include "Player.h"
#include "Monster.h"

class Skill
{
public:
	//생성자
	Skill() = default;
	Skill(std::string name, std::string info, std::string usedInfo,
		int maxSkillPoint, int currentSkillPoint);

	//Setter
	void SetName(std::string);
	void SetInfo(std::string);
	void SetUsedInfo(std::string);
	void SetMaxSkillPoint(int);
	void SetCurrentSkillPoint(int);

	//접근자
	std::string GetName();
	std::string GetInfo();
	int GetMaxSkillPoint();
	int GetCurrentSkillPoint();

	//스킬 사용
	//virtual std::string* Use(Player& player, Monster& monster);

private:
	//안내문
	std::string name = "";
	std::string info = "";
	std::string usedInfo = "";

	//스킬 포인트
	int maxSkillPoint = 0;
	int currentSkillPoint = 0;
};