#include "StatusScene.h"
#include "Item.h"
#include <iostream>
using namespace std;

Scene::SceneType StatusScene::_previousScene = Scene::SCENE_MAIN;

StatusScene::StatusScene(const GameManager* gm)
	:_gm(gm) {}

void StatusScene::Render() const
{
	cout << "�� ���� Ȯ��\n";
	cout << "����: "<<_gm->GetPlayer()->GetLevel() << "(���� ����������... " << _gm->GetPlayer()->GetNextLevelExp() << ")\n";
	cout << "ü��: " << _gm->GetPlayer()->GetCurrentHealth() << "/" << _gm->GetPlayer()->GetMaxHealth() << "\n";
	cout << "���ݷ�: " << _gm->GetPlayer()->GetAttack() << "\n";
	cout << "��Ʈ����: " << _gm->GetPlayer()->GetStress() << "/" << Player::MAX_STRESS << "\n\n";

	cout << "�� �ι��丮 Ȯ��\n";
	for (int i = 0; i < Item::ITEM_MAX; i++)
	{
		cout << _gm->GetItem((Item::ItemType)i)->GetName() << " X " << _gm->GetPlayer()->GetItemCount()[i] << "\n";
	}

	printOptions();
}

Scene::SceneType StatusScene::Update(int input)
{
	if (input != 1)
	{
		return Scene::SCENE_ERROR;
	}

	return _previousScene;
	//return Scene::Scene::SCENE_TOWN;
}

void StatusScene::UpdatePreScene(Scene::SceneType preScene)
{
	_previousScene = preScene;
	return;
}

void StatusScene::printOptions() const
{
	cout << "1. ���ư���\n";
}

