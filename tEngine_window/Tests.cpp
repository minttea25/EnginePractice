#include "pch.h"
#include "Tests.h"
#include "../tEngine_core/Enums.h"
#include "../tEngine_core/SpriteRenderer.h"
#include "../tEngine_core/Resources.h"
#include "../tEngine_core/TextureResource.h"
#include "../tEngine_core/Camera.h"
#include "../tEngine_core/SpriteEditor.h"
#include "../tEngine_core/Animation.h"
#include "../tEngine_core/Animator.h"
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

		auto chara1 = Resources::Load<graphics::TextureResource>(L"Chara01.png");
		if (chara1 == nullptr)
		{
			return;
		}
		auto chara2 = Resources::Load<graphics::TextureResource>(L"Chara02.png");
		if (chara2 == nullptr)
		{
			return;
		}
		auto chara3 = Resources::Load<graphics::TextureResource>(L"Chara03.png");
		if (chara3 == nullptr)
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

		auto animObj = Object::Instantiate<GameObject>(enums::eLayerType::Player, { 150, 150 });
		animObj->AddComponent<Animator>();
		auto ret = animObj->GetComponent<Animator>()
			->CreateAnimation(
				L"Idle",
				{ texture->GetSprite(0), texture->GetSprite(1), texture->GetSprite(2), texture->GetSprite(3) },
				{1, 2, 3, 4},
				true
			);
		if (ret == false)
		{
			return;
		}
		animObj->GetComponent<Animator>()->PlayAnimation(L"Idle");

		auto chara = Object::Instantiate<GameObject>(enums::eLayerType::Player, { 500, 500 });
		chara->AddComponent<Animator>();
		auto ret2 = chara->GetComponent<Animator>()
			->CreateAnimation(
				L"Idle",
				{ chara1->GetSprite(), chara2->GetSprite(), chara3->GetSprite() },
				{ 0.3f, 0.6f, 0.9f },
				true
			);
		if (ret2 == false)
		{
			return;
		}
		chara->GetComponent<Animator>()->PlayAnimation(L"Idle");
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
