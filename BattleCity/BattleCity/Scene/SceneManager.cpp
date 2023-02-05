#include "framework.h"
#include "SceneManager.h"

#include "BattleCityScenes/TestScene.h"
#include "BattleCityScenes/Stage1.h"
#include "BattleCityScenes/Stage2.h"

SceneManager* SceneManager::_instance = nullptr;

SceneManager::SceneManager()
{
	shared_ptr<Scene> test = make_shared<TestScene>();
	_sceneTable[0] = test;
	shared_ptr<Scene> stage1 = make_shared<Stage1>();
	_sceneTable[1] = stage1;
	shared_ptr<Scene> stage2 = make_shared<Stage2>();
	_sceneTable[2] = stage2;

	_curScene = test;
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update()
{
	if (_curScene.expired() == false)
		_curScene.lock()->Update();
}

void SceneManager::Render()
{
	if (_curScene.expired() == false)
		_curScene.lock()->Render();
}

void SceneManager::PreRender()
{
	if (_curScene.expired() == false)
		_curScene.lock()->PreRender();
}

void SceneManager::PostRender()
{
	if (_curScene.expired() == false)
		_curScene.lock()->PostRender();
}

void SceneManager::ChangeScene(int sceneNumber)
{
	_curScene = _sceneTable[sceneNumber];
}
