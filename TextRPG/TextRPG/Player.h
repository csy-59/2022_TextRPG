#pragma once
#include "Skill.h"

class Player
{
	static const int MAX_STRESS = 50;
public:

private:
	//�ִ� ü��
	int maxHealth = 15;
	//�ִ� ��Ʈ����

	//�ɷ�ġ
	int currentHealth = 15;
	int attack = 3;
	int defence = 0;
	int stress = 0;

	//���� ����
	int level = 1;
	int nextLevelExp = 12;

	//��ų ����
	Skill skills[2];
};