#include "pch.h"
#include "Tests.h"
#include "../tEngine_core/Enums.h"

void PlayScene::Init()
{
	_player = new Player();
	AddGameObject(_player, enums::eLayerType::Player);

	Scene::Init();
}

void PlayScene::Update()
{
	Scene::Update();
}

void PlayScene::LateUpdate()
{
	Scene::LateUpdate();
}

void PlayScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
