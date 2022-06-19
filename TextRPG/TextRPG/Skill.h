#pragma once
#include <string>
#include "Player.h"
#include "Monster.h"

class Skill
{
public:
	//������
	Skill() = default;
	Skill(std::string name, std::string info, std::string usedInfo,
		int maxSkillPoint, int currentSkillPoint);

	//Setter
	void SetName(std::string);
	void SetInfo(std::string);
	void SetUsedInfo(std::string);
	void SetMaxSkillPoint(int);
	void SetCurrentSkillPoint(int);

	//������
	std::string GetName();
	std::string GetInfo();
	int GetMaxSkillPoint();
	int GetCurrentSkillPoint();

	//��ų ���
	//virtual std::string* Use(Player& player, Monster& monster);

private:
	//�ȳ���
	std::string name = "";
	std::string info = "";
	std::string usedInfo = "";

	//��ų ����Ʈ
	int maxSkillPoint = 0;
	int currentSkillPoint = 0;
};