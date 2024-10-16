#include "pch.h"
#include "Tests.h"
#include "../tEngine_core/Enums.h"
#include "../tEngine_core/SpriteRenderer.h"
#include "../tEngine_core/Resources.h"
#include "../tEngine_core/TextureResource.h"
#include "Player.h"

void PlayScene::Init()
{
	{
		auto texture = Resources::Load<graphics::TextureResource>(L"sample720.png");
		if (texture == nullptr)
		{
			return;
		}

		auto bg = Object::Instantiate<GameObject>(enums::eLayerType::BackGround, Types::Vector3(30, 30));
		bg->AddComponent<SpriteRenderer>();
		bg->GetComponent<SpriteRenderer>()->set_texture_resource(texture);
		
		auto player = Object::Instantiate<GameObject>(enums::eLayerType::Player, Types::Vector3(100, 100, 0));
		player->AddComponent<Player>();
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
