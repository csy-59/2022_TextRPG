#include "StoreScene.h"
#include "Item.h"
#include <iostream>
#include <iomanip>

StoreScene::StoreScene(GameManager* gm)
	:_gm(gm) {}

Scene::SceneType StoreScene::Update(int input)
{
	//구매 화면이 아닌 경우
	if (_isBuying == false)
	{
		//이상한 값 처리
		if (input < 1 || input > 4)
		{
			return Scene::SCENE_ERROR;
		}

		//돌아가기 선택지라면 다시 마을로 돌아감
		if (input == 4)
		{
			return Scene::SCENE_TOWN;
		}

		_isBuying = true; //구매 화면으로 표시
		_selectItem = (Item::ItemType) (input - 1); //구매 아이템 번호 표시

		return Scene::SCENE_NOCHANGE;
	}
	//구매 화면인 경우
	else
	{
		//구매가 불가능한 경우
		if (_gm->GetPlayer()->GetCoinCount() < _gm->GetItem(_selectItem)->GetPrice())
		{
			if (input != 1)
			{
				return Scene::SCENE_ERROR;
			}

			_isBuying = false;
			_selectItem = Item::ITEM_MAX;
			return Scene::SCENE_NOCHANGE;
		}
		//구매 가능한 경우
		else
		{
			if (input < 1 || input > 2)
			{
				return Scene::SCENE_ERROR;
			}

			//구매한 경우
			if (input == 1)
			{
				_gm->GetPlayer()->BuyItem(_selectItem, _gm->GetItem(_selectItem)->GetPrice());
			}

			_isBuying = false;
			_selectItem = Item::ITEM_MAX;
			return Scene::SCENE_NOCHANGE;			
		}
	}
}

void StoreScene::PrintHeaderInfo() const
{
	std::cout << "| 인밴토리: ";
	for (int i = 0; i < Item::ITEM_MAX; ++i)
	{
		std::cout << _gm->GetItem((Item::ItemType) i)->GetName() << " X " << _gm->GetPlayer()->GetItemCount()[i] << "  ";
	}
	std::cout << "\n※ 현재 소지금: " << _gm->GetPlayer()->GetCoinCount() << "G\n";
}

void StoreScene::PrintMainMessage() const
{
	if (_isBuying || _selectItem < Item::ITEM_MAX)
	{
		BuyItem();
	}
	else
	{
		ShowMainStore();		
	}
}

void StoreScene::PrintFooterInfo() const
{
	if (_isBuying || _selectItem < 0 || _selectItem < Item::ITEM_MAX)
	{
		std::cout << "| " << _gm->GetItem(_selectItem)->GetName() << ": " 
			<< _gm->GetItem(_selectItem)->GetInfo() << "\n";
	}
}

void StoreScene::printOptions() const
{
	if (_isBuying || _selectItem < Item::ITEM_MAX)
	{
		ShowBuyOptions();
	}
	else
	{
		ShowItems();
	}
}

void StoreScene::ShowMainStore() const
{
	std::cout << "\n\t상점이다.\n\t어떤 것을 살까?\n\n";
}

void StoreScene::BuyItem() const
{
	std::cout << "\n" << _gm->GetItem(_selectItem)->GetName() << "를 선택했다.\n정말로 구매할까?";
	if (_gm->GetPlayer()->GetCoinCount() < _gm->GetItem(_selectItem)->GetPrice())
	{
		std::cout << "(구매 불가)\n\n";
	}
	else
	{
		std::cout << " (-" << _gm->GetItem(_selectItem)->GetPrice() << "G)\n\n";
	}
}

void StoreScene::ShowItems() const
{
	for (int i = 0; i < Item::ITEM_MAX; ++i)
	{
		std::cout << (i + 1) << ". " << std::setw(InGameScene::SETW_NUM) << std::left << _gm->GetItem((Item::ItemType)i)->GetName()
			<< "(" << _gm->GetItem((Item::ItemType) i)->GetPrice() << "G)\n";
	}
	std::cout << Item::ITEM_MAX + 1 << ". 마을로 돌아가기\n";
}

void StoreScene::ShowBuyOptions() const
{
	if (_gm->GetPlayer()->GetCoinCount() < _gm->GetItem(_selectItem)->GetPrice())
	{
		std::cout << "1. 구매 취소\n";
	}
	else
	{
		std::cout << "1. 구매하기\n2. 구매 취소\n";
	}
}

