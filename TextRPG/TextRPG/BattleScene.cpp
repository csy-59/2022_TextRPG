#include "BattleScene.h"
#include <iostream>
#include <iomanip>
using namespace std;

BattleScene::BattleScene(GameManager* gm)
	:_gm(gm) 
{
	monsterList[0][0] = new Monster("이론몬", "교수님의 기습 질문!", "객체 지향적 프로그래밍이란 무엇이죠?", 
		8, 8, 5, 3, 25, 5);
	monsterList[0][1] = new Monster("졸음몬", "포근한 침대 생각~", "눕고 싶다...", 
		10, 10, 3, 2, 25, 5);
	monsterList[1][0] = new Monster("실습몬", "나는 바보다 히히", "??: 라이브쉐어 들어오세요", 
		20, 20, 8, 5, 25, 10);
	monsterList[1][1] = new Monster("과식몬", "식...곤...증....Zz...", "Zzz...", 
		25, 25, 5, 4, 25, 10);
	monsterList[2][0] = new Monster("테크톡몬", "분명 어디서 봤는데....", "포기하면 편한데 히히", 
		30, 30, 12, 10, 30, 5);
	monsterList[2][0] = new Monster("스터디몬", "아무래도 나는 비전공자는 아닌듯하다.", "플립플롭! 플립플롭!", 
		35, 35, 11, 9, 30, 5);

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
		//그냥 메인일때
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
		//공격중일 때
		else if (isAttacking)
		{
			//옵션 선택중일 경우
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
			//공격한 결과 창일 경우
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
		//아이템 사용 중일 경우
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
	SETW_COUT << " " << "♥: " << monster->GetCurrentHealth() << "/" << monster->GetMaxHealth() << "\n";
}

void BattleScene::PrintMainMessage() const
{
	if (isMonsterDied)
	{
		cout << "\n\t" << monster->GetName() << "를 해치웠다!\n";
		cout << "\t" << "승리했다!\n";
		cout << "\t[ " << resultMassage << " ]\n\n";
	}

	else if (isPlayerDied)
	{
		if (_gm->GetPlayer()->GetCurrentHealth() <= 0)
		{
			cout << "\n\t나의 라이프가 0이 되었다...\n";
			cout << "\t집에 가지 못했다...\n\n";
		}
		else
		{
			cout << "\n\t과도한 스트레스로 요절했다...\n";
			cout << "\t집에도 가지 못했다...\n\n";
		}
	}

	else if (isGameWin)
	{
		cout << "\n\t레벨 30에 도달했다!\n";
		cout << "\t드디어 집에 도착했다!\n\n";
	}

	else if (isPlayerLevelUp)
	{
		if (_gm->GetStatPoint() <= 0)
		{
			cout << "\n\t지식이 늘었다!!\n";
			cout << "\t집과 가까워진다!!\n";
			cout << "\t[ SP +2 ]\n\n";
		}
		else
		{
			cout << "\n\t어디에 스탯 포인트를 사용할까?\n";
			cout << "\t[ SP: " << _gm->GetStatPoint() << " ]\n\n";
		}
	}

	else if (isPlayerTurn)
	{
		if (isBattleMain)
		{
			cout << "\n\t" << monster->GetName() << "이 나타났다!\n";
			cout << "\t" << monster->GetIntroduceString() << "\n\n";
		}

		else if (isAttacking)
		{
			switch (AttackNumber)
			{
			case 0:
				cout << "\n\t" << monster->GetName() << "이 나타났다!\n";
				cout << "\t" << monster->GetIntroduceString() << "\n\n";
				break;
			case 1:
				cout << "\n\t" << monster->GetName() << "을 공격했다!\n";
				cout << "\t" << "[ ♥ -" << _gm->GetPlayer()->GetAttack() << " ]\n\n";
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
				cout << "\n\t" << monster->GetName() << "이 나타났다!\n";
				cout << "\t" << monster->GetIntroduceString() << "\n\n";
			}
			else
			{
				cout << "\n\t" << _gm->GetItem((Item::ItemType)(itemNumber - 1))->GetName() << "을/를 먹었다.\n";
				cout << "\t[ " << resultMassage << " ]\n\n";
			}
		}
	}
	else
	{
		cout << "\n\t" << monster->GetName() << "이 공격했다!\n";
		cout << "\t" << monster->GetAttackNoise() << "\n";
		cout << "\t[ ♥ -" << playerGetDamage << " ]\n\n";
	}
}

void BattleScene::PrintFooterInfo() const
{
	SETW_COUT << "| ♥: " + to_string(_gm->GetPlayer()->GetCurrentHealth())
		+ "/" + to_string(_gm->GetPlayer()->GetMaxHealth()) << setw(SETW_NUM) << " ";
	cout << "S: " << _gm->GetPlayer()->GetStress() << "/" << Player::MAX_STRESS<<"\n";
}

void BattleScene::printOptions() const
{
	if (isMonsterDied)
	{
		cout << "1. 다음.\n";
	}

	else if (isPlayerDied)
	{
		cout << "1. Game Over\n";
	}

	else if (isPlayerLevelUp)
	{
		if (_gm->GetStatPoint() <= 0)
		{
			cout << "1. 다음\n";
		}
		else
		{
			cout << "1. 체력\n";
			cout << "2. 공격력\n";
		}
	}

	else if (isGameWin)
	{
		cout << "1. 다음\n";
	}

	else if (isPlayerTurn)
	{
		if (isBattleMain)
		{
			cout << "1. 공격한다.\n";
			cout << "2. 아이템을 사용한다.\n";
		}
		else if (isAttacking && AttackNumber == 0)
		{
			cout << "1. 기본 공격\n";
			//스킬
		}
		else if (isUsingItem && itemNumber == 0)
		{
			for (int i = 0; i < Item::ITEM_MAX; ++i)
			{
				cout << i + 1 << ". " << _gm->GetItem((Item::ItemType)i)->GetName()
					<< " X " << _gm->GetPlayer()->GetItemCount()[i] << "\n";
			}
			cout << (Item::ITEM_MAX + 1) << ". 돌아간다.\n";
		}
		else
		{
			cout << "1. 몬스터가 공격해온다.\n";
		}
	}
	else
	{
		cout << "1. 다음\n";
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
