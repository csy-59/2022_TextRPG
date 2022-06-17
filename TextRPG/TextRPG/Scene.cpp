#include "Scene.h"

Scene::SceneType Scene::Update(int input)
{
	return Scene::SCENE_ERROR;
}

void Scene::SetOptionCount(int optionCount)
{
	_optionCount = optionCount;
}

void Scene::Render() const
{
	return;
}

void Scene::printOptions() const
{
	return;
}