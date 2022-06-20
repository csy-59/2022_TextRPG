#include "BattleScene.h"
#include <iostream>
#include <iomanip>
using namespace std;

BattleScene::BattleScene(GameManager* gm)
	:_gm(gm) 
{
	monsterList[0][0] = new Monster("�̷и�", "�������� ��� ����!", "��ü ������ ���α׷����̶� ��������?", 
		8, 8, 5, 3, 25, 5);
	monsterList[0][1] = new Monster("??��", "�귿 �����ڽ��ϴ�.", "��ũ�� ���ϸ��� �ϴ� �ɷ� �ٲٰڽ��ϴ�.", 
		10, 10, 3, 2, 25, 5);
	monsterList[1][0] = new Monster("�ǽ���", "���� �ٺ��� ����", "??: ���̺꽦�� ��������", 
		15, 15, 8, 5, 25, 10);
	monsterList[1][1] = new Monster("���ĸ�", "��...��...��....Zz...", "Zzz...", 
		20, 20, 5, 4, 25, 10);
	monsterList[2][0] = new Monster("��ũ���", "�и� ��� �ôµ�....", "�����ϸ� ���ѵ� ����", 
		25, 25, 12, 10, 30, 5);
	monsterList[2][0] = new Monster("���͵��", "�ƹ����� ���� �������ڴ� �ƴѵ��ϴ�.", "�ø��÷�! �ø��÷�!", 
		30, 30, 11, 9, 30, 5);

	monster = monsterList[0][0];
}

Scene::SceneType BattleScene::Update(int input)
{
	if (isMonsterDied)
	{
		if (input != 1)
		{
			return Scene::SCENE_ERROR;
		}

		isMonsterDied = false;

		GetRandomMonster();

		if (isGameWin) {
			return Scene::SCENE_NOCHANGE;
		}

		if (isPlayerLevelUp == false)
		{
			isBattleOver = true;
			return BattleOver();
		}

		return Scene::SCENE_NOCHANGE;
	}

	else if (isPlayerDied)
	{
		if (input != 1)
		{
			return Scene::SCENE_ERROR;
		}
		
		isGameOver = true;
		return BattleOver();
	}

	else if (isGameWin)
	{
		if (input != 1)
		{
			return Scene::SCENE_ERROR;
		}

		return BattleOver();
	}

	else if (isPlayerLevelUp)
	{
		if (_gm->GetStatPoint() <= 0)
		{
			if (input != 1)
			{
				return Scene::SCENE_ERROR;
			}

			_gm->SetStatPoint(2);
			_gm->GetPlayer()->LevelUp();

			return Scene::SCENE_NOCHANGE;
		}
		else
		{
			if (input < 1 || input > 2)
			{
				return Scene::SCENE_ERROR;
			}

			_gm->UseStatPoint();

			switch (input)
			{
			case 1:
				_gm->GetPlayer()->AddHealth();
				break;
			case 2:
				_gm->GetPlayer()->AddAttack();
				break;
			}

			if (_gm->GetStatPoint() <= 0)
			{
				isBattleOver = true;
				return BattleOver();
			}

			return Scene::SCENE_NOCHANGE;
		}
	}

	else if (isPlayerTurn)
	{
		//�׳� �����϶�
		if (isBattleMain)
		{
			if (input < 1 || input > 2)
			{
				return Scene::SCENE_ERROR;
			}

			isBattleMain = false;
			if (input == 1)
			{
				isAttacking = true;
			}
			else if(input == 2)
			{
				isUsingItem = true;
			}

			return Scene::SCENE_NOCHANGE;
		}
		//�������� ��
		else if (isAttacking)
		{
			//�ɼ� �������� ���
			if (AttackNumber == 0)
			{
				if (input < 1 || input > 3)
				{
					return Scene::SCENE_ERROR;
				}

				if (_gm->GetPlayer()->GetLevel() < 20 && input == 3)
				{
					return Scene::SCENE_ERROR;
				}
				else if (_gm->GetPlayer()->GetLevel() < 10 && input == 2)
				{
					return Scene::SCENE_ERROR;
				}

				switch (input)
				{
				case 1:
					monster->GetAttacked(_gm->GetPlayer()->GetAttack());
					break;
				case 2:
					monster->GetAttacked(_gm->GetPlayer()->GetAttack());
					break;
				case 3:
					monster->GetAttacked(_gm->GetPlayer()->GetAttack());
					break;
				}

				AttackNumber = input;

				AfterCheck();
			}
			//������ ��� â�� ���
			else
			{
				if (input != 1)
				{
					return Scene::Scene::SCENE_ERROR;
				}

				PlayerGetAttacked();
				AfterCheck();

				AttackNumber = 0;
				isBattleMain = true;
				isPlayerTurn = false;
				isAttacking = false;
			}

			return Scene::SCENE_NOCHANGE;
		}
		//������ ��� ���� ���
		else if (isUsingItem)
		{
			if (itemNumber == 0)
			{
				if (input < 1 || input > 4)
				{
					return Scene::SCENE_ERROR;
				}

				itemNumber = input;
				if (_gm->GetPlayer()->GetItemCount()[input - 1] > 0)
				{
					resultMassage = _gm->UseItem((Item::ItemType) (input - 1));
					_gm->GetPlayer()->UseItem(input - 1);
				}
				else
				{
					itemNumber = 0;
				}

				if (input == 4)
				{
					isPlayerTurn = true;
					isBattleMain = true;
					isAttacking = false;
					isUsingItem = false;

					return Scene::SCENE_NOCHANGE;
				}
			}
			else
			{
				if (input != 1)
				{
					return Scene::SCENE_ERROR;
				}

				itemNumber = 0;
				isPlayerTurn = false;
				isBattleMain = true;
				isAttacking = false;
				isUsingItem = false;

				PlayerGetAttacked();
			}
			return Scene::SCENE_NOCHANGE;
		}
	}
	else 
	{
		if (input != 1)
		{
			return Scene::SCENE_ERROR;
		}

		isPlayerTurn = true;
		isBattleMain = true;
		isAttacking = false;
		isUsingItem = false;
		itemNumber = 0;
		AttackNumber = 0;
		playerGetDamage = 0;

		return Scene::SCENE_NOCHANGE;
	}

}

void BattleScene::PrintHeaderInfo() const
{
	SETW_COUT << "<" + monster->GetName() + ">";
	SETW_COUT << " " << "��: " << monster->GetCurrentHealth() << "/" << monster->GetMaxHealth() << "\n";
}

void BattleScene::PrintMainMessage() const
{
	if (isMonsterDied)
	{
		cout << "\n\t" << monster->GetName() << "�� ��ġ����!\n";
		cout << "\t" << "�¸��ߴ�!\n";
		cout << "\t[ " << resultMassage << " ]\n\n";
	}

	else if (isPlayerDied)
	{
		if (_gm->GetPlayer()->GetCurrentHealth() <= 0)
		{
			cout << "\n\t���� �������� 0�� �Ǿ���...\n";
			cout << "\t���� ���� ���ߴ�...\n\n";
		}
		else
		{
			cout << "\n\t������ ��Ʈ������ �����ߴ�...\n";
			cout << "\t������ ���� ���ߴ�...\n\n";
		}
	}

	else if (isGameWin)
	{
		cout << "\n\t���� 30�� �����ߴ�!\n";
		cout << "\t���� ���� �����ߴ�!\n\n";
	}

	else if (isPlayerLevelUp)
	{
		if (_gm->GetStatPoint() <= 0)
		{
			cout << "\n\t������ �þ���!!\n";
			cout << "\t���� ���������!!\n";
			cout << "\t[ SP +2 ]\n\n";
		}
		else
		{
			cout << "\n\t��� ���� ����Ʈ�� ����ұ�?\n";
			cout << "\t[ SP: " << _gm->GetStatPoint() << " ]\n\n";
		}
	}

	else if (isPlayerTurn)
	{
		if (isBattleMain)
		{
			cout << "\n\t" << monster->GetName() << "�� ��Ÿ����!\n";
			cout << "\t" << monster->GetIntroduceString() << "\n\n";
		}

		else if (isAttacking)
		{
			switch (AttackNumber)
			{
			case 0:
				cout << "\n\t" << monster->GetName() << "�� ��Ÿ����!\n";
				cout << "\t" << monster->GetIntroduceString() << "\n\n";
				break;
			case 1:
				cout << "\n\t" << monster->GetName() << "�� �����ߴ�!\n";
				cout << "\t" << "[ �� -" << _gm->GetPlayer()->GetAttack() << " ]\n\n";
				break;
			case 2:
				break;
			case 3:
				break;
			}
		}

		else if (isUsingItem)
		{
			if (itemNumber == 0)
			{
				cout << "\n\t" << monster->GetName() << "�� ��Ÿ����!\n";
				cout << "\t" << monster->GetIntroduceString() << "\n\n";
			}
			else
			{
				cout << "\n\t" << _gm->GetItem((Item::ItemType)(itemNumber - 1))->GetName() << "��/�� �Ծ���.\n";
				cout << "\t[ " << resultMassage << " ]\n\n";
			}
		}
	}
	else
	{
		cout << "\n\t" << monster->GetName() << "�� �����ߴ�!\n";
		cout << "\t" << monster->GetAttackNoise() << "\n";
		cout << "\t[ �� -" << playerGetDamage << " ]\n\n";
	}
}

void BattleScene::PrintFooterInfo() const
{
	SETW_COUT << "| ��: " + to_string(_gm->GetPlayer()->GetCurrentHealth())
		+ "/" + to_string(_gm->GetPlayer()->GetMaxHealth()) << setw(SETW_NUM) << " ";
	cout << "S: " << _gm->GetPlayer()->GetStress() << "/" << Player::MAX_STRESS<<"\n";
}

void BattleScene::printOptions() const
{
	if (isMonsterDied)
	{
		cout << "1. ����.\n";
	}

	else if (isPlayerDied)
	{
		cout << "1. Game Over\n";
	}

	else if (isPlayerLevelUp)
	{
		if (_gm->GetStatPoint() <= 0)
		{
			cout << "1. ����\n";
		}
		else
		{
			cout << "1. ü��\n";
			cout << "2. ���ݷ�\n";
		}
	}

	else if (isGameWin)
	{
		cout << "1. ����\n";
	}

	else if (isPlayerTurn)
	{
		if (isBattleMain)
		{
			cout << "1. �����Ѵ�.\n";
			cout << "2. �������� ����Ѵ�.\n";
		}
		else if (isAttacking && AttackNumber == 0)
		{
			cout << "1. �⺻ ����\n";
			//��ų
		}
		else if (isUsingItem && itemNumber == 0)
		{
			for (int i = 0; i < Item::ITEM_MAX; ++i)
			{
				cout << i + 1 << ". " << _gm->GetItem((Item::ItemType)i)->GetName()
					<< " X " << _gm->GetPlayer()->GetItemCount()[i] << "\n";
			}
			cout << (Item::ITEM_MAX + 1) << ". ���ư���.\n";
		}
		else
		{
			cout << "1. ���Ͱ� �����ؿ´�.\n";
		}
	}
	else
	{
		cout << "1. ����\n";
	}
}

void BattleScene::PlayerGetAttacked()
{
	int damage = monster->Damage() * (1 + _gm->GetPlayer()->GetStress() / 100.0f);
	_gm->GetPlayer()->GotDamageFromMonster(damage);

	int stress = 3;
	float stressCal = (float)damage / _gm->GetPlayer()->GetCurrentHealth();
	if (stressCal >= 0.5f)
	{
		stress = 5;
	}
	else if (stressCal >= 0.3f)
	{
		stress = 4;
	}
	_gm->GetPlayer()->AddStress(stress);

	playerGetDamage = damage;
}

void BattleScene::GetRandomMonster()
{
	monster->SetCurrentHealth(monster->GetMaxHealth());
	monster = monsterList[_gm->GetStageNumber() - 1][Random::GetRandomNumberFromRange(0, 1)];
}

void BattleScene::AfterCheck()
{
	if (monster->GetCurrentHealth() <= 0)
	{
		isMonsterDied = true;
		
		int coin = monster->DropCoin();
		_gm->GetPlayer()->GotCoin(coin);
		resultMassage = "$ +" + to_string(coin);

		_gm->GetPlayer()->GotEXP(_gm->GetStageNumber() * 10);

		if (_gm->GetPlayer()->GetNextLevelExp() <= 0)
		{
			isPlayerLevelUp = true;
			_gm->GetPlayer()->GotCured(100);
		}

		if (isPlayerLevelUp && (_gm->GetPlayer()->GetLevel() + 1) % 5 == 0)
		{
			if ((_gm->GetPlayer()->GetLevel() + 1) >= 15)
			{
				isGameWin = true;
			}
			else
			{
				isStageChange = true;
				_gm->StageUp();
			}
		}
	}
	
	if (_gm->GetPlayer()->GetCurrentHealth() <= 0 || _gm->GetPlayer()->GetStress() >= Player::MAX_STRESS)
	{
		isPlayerDied = true;
		isGameOver = true;
	}
}

Scene::SceneType BattleScene::BattleOver()
{
	isPlayerTurn = true;
	isBattleMain = true;

	isAttacking = false;
	AttackNumber = 0;

	isUsingItem = false;
	itemNumber = 0;

	playerGetDamage = 0;

	isPlayerDied = false;
	isMonsterDied = false;
	isPlayerLevelUp = false;

	resultMassage = "";

	if (isBattleOver)
	{
		isBattleOver = false;
		isGameOver = false;
		isGameWin = false;

		if (isStageChange )
		{
			isStageChange = false;
			return Scene::SCENE_TOWN;
		}
		return Scene::SCENE_FOREST;
	}
	else if(isGameOver)
	{
		isBattleOver = false;
		isGameOver = false;
		isGameWin = false;
		return Scene::SCENE_MAIN;
	}
	else
	{
		isBattleOver = false;
		isGameOver = false;
		isGameWin = false;
		return Scene::SCENE_ENDING;
	}
}
