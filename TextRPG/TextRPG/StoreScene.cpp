#include "StoreScene.h"
#include "Item.h"
#include <iostream>
#include <iomanip>

StoreScene::StoreScene(GameManager* gm)
	:_gm(gm) {}

Scene::SceneType StoreScene::Update(int input)
{
	//���� ȭ���� �ƴ� ���
	if (_isBuying == false)
	{
		//�̻��� �� ó��
		if (input < 1 || input > 4)
		{
			return Scene::SCENE_ERROR;
		}

		//���ư��� ��������� �ٽ� ������ ���ư�
		if (input == 4)
		{
			return Scene::SCENE_TOWN;
		}

		_isBuying = true; //���� ȭ������ ǥ��
		_selectItem = (Item::ItemType) (input - 1); //���� ������ ��ȣ ǥ��

		return Scene::SCENE_NOCHANGE;
	}
	//���� ȭ���� ���
	else
	{
		//���Ű� �Ұ����� ���
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
		//���� ������ ���
		else
		{
			if (input < 1 || input > 2)
			{
				return Scene::SCENE_ERROR;
			}

			//������ ���
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
	std::cout << "| �ι��丮: ";
	for (int i = 0; i < Item::ITEM_MAX; ++i)
	{
		std::cout << _gm->GetItem((Item::ItemType) i)->GetName() << " X " << _gm->GetPlayer()->GetItemCount()[i] << "  ";
	}
	std::cout << "\n�� ���� ������: " << _gm->GetPlayer()->GetCoinCount() << "G\n";
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
	std::cout << "\n\t�����̴�.\n\t� ���� ���?\n\n";
}

void StoreScene::BuyItem() const
{
	std::cout << "\n" << _gm->GetItem(_selectItem)->GetName() << "�� �����ߴ�.\n������ �����ұ�?";
	if (_gm->GetPlayer()->GetCoinCount() < _gm->GetItem(_selectItem)->GetPrice())
	{
		std::cout << "(���� �Ұ�)\n\n";
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
	std::cout << Item::ITEM_MAX + 1 << ". ������ ���ư���\n";
}

void StoreScene::ShowBuyOptions() const
{
	if (_gm->GetPlayer()->GetCoinCount() < _gm->GetItem(_selectItem)->GetPrice())
	{
		std::cout << "1. ���� ���\n";
	}
	else
	{
		std::cout << "1. �����ϱ�\n2. ���� ���\n";
	}
}

