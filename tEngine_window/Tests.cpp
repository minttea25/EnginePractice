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
#include "../tEngine_core/AnimationCurve.h"
#include "../tEngine_core/AnimatorController.h"
#include "../tEngine_core/AnimationClip.h"
#include "../tEngine_core/AnimationDiscrete.h"
#include "Player.h"
#include "CameraFollower.h"
#include <typeinfo>

void PlayScene::Init()
{
	/*
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
	}*/


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

	{
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

		auto go = Object::Instantiate<GameObject>(enums::eLayerType::Player, { 100, 100 });
		go->AddComponent<SpriteRenderer>();
		go->GetComponent<SpriteRenderer>()->set_sprite(chara1->GetSprite());
		go->AddComponent<Animator>();

		AnimationDiscrete* discrete = new AnimationDiscrete(typeid(tEngine::Sprite));
		discrete->AddKey(0, chara1->GetSprite());
		discrete->AddKey(0.5f, chara2->GetSprite());
		discrete->AddKey(1, chara3->GetSprite());
		discrete->AddKey(1.5f, chara1->GetSprite());
		discrete->AddKey(2.0f, chara2->GetSprite());
		discrete->AddKey(2.5f, chara3->GetSprite());
		discrete->AddKey(3.0f, chara1->GetSprite());
		discrete->AddKey(3.5f, chara2->GetSprite());
		discrete->AddKey(4.0f, chara3->GetSprite());
		discrete->Build();
		AnimationProperty* p1 = new AnimationProperty();
		void* ptr1 = go->GetComponent<SpriteRenderer>()->get_sprite_ref();
		//p1->BindRef(ptr1);
		//p1->BindRef(&SpriteRenderer::_sprite, go->GetComponent<SpriteRenderer>());
		p1->BindRef(go->GetComponent<SpriteRenderer>()->get_sprite_ref());

		AnimationCurve* curve = new AnimationCurve(AnimationCurveInterpolationMode::Lerp);
		curve->AddKey(KeyFrame(0.0f, 100.0f));
		curve->AddKey(KeyFrame(2.0f, 200));
		curve->AddKey(KeyFrame(4.0f, 300));
		curve->AddKey(KeyFrame(6.0f, 400));
		curve->AddKey(KeyFrame(8.0f, 500));
		AnimationProperty* p2 = new AnimationProperty();
		void* ptr = go->transform()->position_ref()->get_x_ref();
		p2->BindRef(ptr);

		AnimationClip* clip = new AnimationClip();
		clip->SetCurve("TEMP", *p2, curve);
		clip->SetDiscrete("TEMP", *p1, discrete);

		AnimatorController* animController = new AnimatorController();
		animController->set_clip(clip);
		auto anim = go->GetComponent<Animator>();
		anim->set_animatorController(animController);

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
