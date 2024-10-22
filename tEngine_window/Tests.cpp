#include "pch.h"
#include "Tests.h"
#include "../tEngine_core/Enums.h"
#include "../tEngine_core/SpriteRenderer.h"
#include "../tEngine_core/Resources.h"
#include "../tEngine_core/TextureResource.h"
#include "../tEngine_core/Camera.h"
#include "../tEngine_core/SpriteEditor.h"
#include "Player.h"
#include "CameraFollower.h"

void PlayScene::Init()
{
	{
		auto texture = Resources::Load<graphics::TextureResource>(L"sample720.png");
		if (texture == nullptr)
		{
			return;
		}
		auto sheet = texture->GetSpriteSheet();
		editor::SpriteEditor spriteEditor(sheet);
		spriteEditor.Slice(2, 2); // the texture has 4 spites now.

		auto chara_texture = Resources::Load<graphics::TextureResource>(L"chara.png");
		if (chara_texture == nullptr)
		{
			return;
		}

		auto bg = Object::Instantiate<GameObject>(enums::eLayerType::BackGround, Types::Vector3(30, 30));
		bg->AddComponent<SpriteRenderer>();
		bg->GetComponent<SpriteRenderer>()->set_sprite(texture->GetSprite(0));

		auto bg2 = Object::Instantiate<GameObject>(enums::eLayerType::BackGround, Types::Vector3(500, 310));
		bg2->AddComponent<SpriteRenderer>();
		bg2->GetComponent<SpriteRenderer>()->set_sprite(texture->GetSprite(3));
		
		auto player = Object::Instantiate<GameObject>(enums::eLayerType::Player, Types::Vector3(100, 100, 0));
		player->AddComponent<Player>();
		player->AddComponent<SpriteRenderer>();
		player->GetComponent<SpriteRenderer>()
			->set_sprite(chara_texture->GetSprite());
		player->GetComponent<SpriteRenderer>()->set_scale({ 0.5f, 0.5f, 1 });

		auto camera = Object::Instantiate<GameObject>(enums::eLayerType::None);
		camera->AddComponent<Camera>();
		camera->GetComponent<Camera>()->set_resolution({ 1600, 900 });
		camera->AddComponent<CameraFollower>();
		camera->GetComponent<CameraFollower>()->InitObject();
		camera->GetComponent<CameraFollower>()->set_Target(player);

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
