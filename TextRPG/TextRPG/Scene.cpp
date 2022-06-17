#include "Scene.h"

Scene::SceneType Scene::Update(int input)
{
	return Scene::SCENE_ERROR;
}

void Scene::SetOptionCount(int optionCount)
{
	_optionCount = optionCount;
}

int Scene::GetOptionCount()
{
	return _optionCount;
}

void Scene::Render() const
{
	return;
}

void Scene::printOptions() const
{
	return;
}
