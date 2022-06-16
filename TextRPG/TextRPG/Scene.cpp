#include "Scene.h"

Scene::SceneType Scene::Update(int input)
{
	return SCENE_ERROR;
}

void Scene::SetOptionCount(int optionCount)
{
	_optionCount = optionCount;
}

int Scene::GetOptionCount()
{
	return _optionCount;
}

void Scene::Init() const
{
	return;
}

void Scene::Render() const
{
	return;
}
