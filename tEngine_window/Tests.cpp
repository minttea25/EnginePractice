#include "pch.h"
#include "Tests.h"
#include "../tEngine_core/Enums.h"
#include "../tEngine_core/SpriteRenderer.h"

void PlayScene::Init()
{
	{
		auto bg = Object::Instantiate<BgObject>(enums::eLayerType::BackGround, Types::Vector3(30, 30));
		bg->AddComponent<SpriteRenderer>();
		bg->GetComponent<SpriteRenderer>()->LoadImage_Gdiplus(L"..\\Resource\\sample720.png");
		auto player = Object::Instantiate<Player>(enums::eLayerType::Player, Types::Vector3(100, 100, 0));
	}
}

void PlayScene::Update()
{
}

void PlayScene::LateUpdate()
{
}

void PlayScene::Render(HDC hdc)
{
}
