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
}


Animation* Animator::FindAnimation(const String& key)
{
	return nullptr;
}

void Animator::PlayAnimation(const String& key, bool loop)
{
}




NAMESPACE_CLOSE