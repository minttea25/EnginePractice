#include "pch.h"
#include "Animator.h"
#include "Animation.h"
#include "AnimatorController.h"
#include "AnimationClip.h"

NAMESPACE_OPEN(tEngine)

Animator::Animator(GameObject* gameObject)
	: Behaviour(gameObject),
	_loop(true),
	_enabled(true),
	_time(0.0f),
	_animUnitTime(0.0f),
	_animController(nullptr)
{
}

Animator::~Animator()
{
	/*for (auto& anim : _animations)
	{
		delete anim.second;
	}
	_animations.clear();*/
}

void Animator::Init()
{
}

void Animator::Update()
{
	/*if (_currentAnimation)
	{
		_currentAnimation->Update();
		if (_currentAnimation->IsComplete() && _loop)
		{
			_currentAnimation->Reset();
		}
	}*/
	_time += Time::deltaTime();

	if (_animController->get_clip()->IsLoop())
	{
		_time = fmodf(_time, _animUnitTime);
	}

	// TODO : If the animation is not loop?
	// Now: Just play animation from last frame animation
	// How about : Check the animation is finished, and call nothing.
	
	if (_animController)
	{
		_animController->PlayAnimation(_time);
	}
}

void Animator::LateUpdate()
{
}

void Animator::Render(HDC hdc)
{
	// if (_currentAnimation) _currentAnimation->Render(hdc);
}

void Animator::set_animatorController(AnimatorController* animController)
{
	ASSERT_CRASH(animController != nullptr);
	ASSERT_CRASH(animController->get_clip() != nullptr);
	_animController = animController;

	_animUnitTime = _animController->get_clip()->length();
}

//bool Animator::CreateAnimation(const String& animation, Vector<Sprite*> sprites, Vector<float> intervals, bool loop)
//{
//	if (sprites.size() != intervals.size())
//	{
//		// error : wrong animation structur
//		return false;
//	}
//
//	Animation* anim = nullptr;
//	anim = FindAnimation(animation);
//	if (anim != nullptr)
//	{
//		// error : already exists
//		return false;
//	}
//
//	anim = new Animation(gameObject());
//	anim->set_animator(this);
//	anim->CreateAnimation(sprites, intervals);
//	_animations.insert({ animation, anim } );
//
//	return true;
//}
//
//
//Animation* Animator::FindAnimation(const String& key)
//{
//	auto it = _animations.find(key);
//	if (it == _animations.end()) return nullptr;
//
//	return it->second;
//}

//void Animator::CreateAnimation(const String& animation, Vector<Sprite> spriteSheet, Vector<float> intervals, bool loop = true)
//{
//	Animation* anim = nullptr;
//	anim = FindAnimation(animation);
//	if (anim != nullptr) return;
//	
//
//	anim = new Animation(gameObject());
//	anim->CreateAnimation(animation, spriteSheet)
//}

//void Animator::PlayAnimation(const String& key, bool loop)
//{
//	Animation* anim = FindAnimation(key);
//	if (anim == nullptr) return;
//
//	_currentAnimation = anim;
//	_currentAnimation->Reset();
//	_loop = loop;
//}





NAMESPACE_CLOSE