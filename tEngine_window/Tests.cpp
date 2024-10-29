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
#include "../tEngine_core/Transform.h"
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

		auto bg = Object::Instantiate<GameObject>(enums::eLayerType::BackGround, Types::Vector3(330, 330));
		bg->AddComponent<SpriteRenderer>();
		bg->GetComponent<SpriteRenderer>()->set_sprite(texture->GetSprite(0));
		
		auto player = Object::Instantiate<GameObject>(enums::eLayerType::Player, Types::Vector3(100, 100, 0));
		//player->AddComponent<Player>();
		player->AddComponent<SpriteRenderer>();
		player->GetComponent<SpriteRenderer>()
			->set_sprite(chara_texture->GetSprite());
		player->transform()->set_scale({ 0.5f, 0.5f, 1 });

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
		chara->transform()->set_rotation({ 0, 0, 70 });
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
		chara->AddComponent<Player>();
	}
	

	/*
	{
		Vector<graphics::TextureResource*> frames =
		{
			Resources::Load<graphics::TextureResource>(L"hide//sample_01.png"),
			Resources::Load<graphics::TextureResource>(L"hide//sample_02.png"),
			Resources::Load<graphics::TextureResource>(L"hide//sample_03.png"),
			Resources::Load<graphics::TextureResource>(L"hide//sample_04.png"),
			Resources::Load<graphics::TextureResource>(L"hide//sample_05.png"),
			Resources::Load<graphics::TextureResource>(L"hide//sample_06.png"),
			Resources::Load<graphics::TextureResource>(L"hide//sample_07.png"),
			Resources::Load<graphics::TextureResource>(L"hide//sample_08.png"),
			Resources::Load<graphics::TextureResource>(L"hide//sample_09.png"),
			Resources::Load<graphics::TextureResource>(L"hide//sample_10.png"),
		};

		for (const auto* ptr : frames)
		{
			if (ptr == nullptr)
			{
				return;
			}
		}

		auto effect = Object::Instantiate<GameObject>(enums::eLayerType::Player, { 200, 200 });
		effect->transform()->set_rotation({0, 0, -30});
		effect->transform()->set_scale({ 3, 3, 1 });
		effect->AddComponent<Animator>();
		auto anim = effect->GetComponent<Animator>();
		Vector<Sprite*> sprites;
		for (const auto& texture : frames)
		{
			sprites.push_back(texture->GetSprite());
		}
		auto ret = anim->CreateAnimation(L"Idle",
			sprites,
			{ 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
			true);
		if (ret == false)
		{
			return;
		}
		anim->PlayAnimation(L"Idle");

	}*/
	
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
