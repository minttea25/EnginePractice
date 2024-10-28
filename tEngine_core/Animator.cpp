#include "pch.h"
#include "Animator.h"
#include "Animation.h"

NAMESPACE_OPEN(tEngine)

Animator::Animator(GameObject* gameObject)
	: Behaviour(gameObject),
	_currentAnimation(nullptr),
	_loop(true),
	_enabled(true)
{
}

Animator::~Animator()
{
	for (auto& anim : _animations)
	{
		delete anim.second;
	}
	_animations.clear();
}

void Animator::Init()
{
}

void Animator::Update()
{
	if (_currentAnimation)
	{
		_currentAnimation->Update();
		if (_currentAnimation->IsComplete() && _loop)
		{
			_currentAnimation->Reset();
		}
	}
}

void Animator::LateUpdate()
{
}

void Animator::Render(HDC hdc)
{
	if (_currentAnimation) _currentAnimation->Render(hdc);
}

bool Animator::CreateAnimation(const String& animation, Vector<Sprite*> sprites, Vector<float> intervals, bool loop)
{
	if (sprites.size() != intervals.size())
	{
		// error : wrong animation structur
		return false;
	}

	Animation* anim = nullptr;
	anim = FindAnimation(animation);
	if (anim != nullptr)
	{
		// error : already exists
		return false;
	}

	anim = new Animation(gameObject());
	anim->set_animator(this);
	anim->CreateAnimation(sprites, intervals);
	_animations.insert({ animation, anim } );

	return true;
}


Animation* Animator::FindAnimation(const String& key)
{
	auto it = _animations.find(key);
	if (it == _animations.end()) return nullptr;

	return it->second;
}

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

void Animator::PlayAnimation(const String& key, bool loop)
{
	Animation* anim = FindAnimation(key);
	if (anim == nullptr) return;

	_currentAnimation = anim;
	_currentAnimation->Reset();
	_loop = loop;
}




NAMESPACE_CLOSE