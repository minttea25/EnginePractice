#include "pch.h"
#include "Animation.h"

NAMESPACE_OPEN(tEngine)

Animation::Animation(GameObject* gameObject)
	: Behaviour(gameObject),
	_animator(nullptr), _isPlaying(false),
	_index(-1), _time(0), _complete(false)
{
}

Animation::~Animation()
{
}

void Animation::CreateAnimation(const String& animation, graphics::TextureResource* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, unsigned int spriteLength, float duration)
{
}

void Animation::Init()
{
}

void Animation::Update()
{
	if (_complete) return;

	_time += Time::deltaTime();


	ASSERT_CRASH(_index <= _intervals.size());

	if (_intervals[_index] < _time)
	{
		_index++;
		if (_index == _intervals.size())
		{
			_complete = true;
		}
	}
}

void Animation::LateUpdate()
{
}

void Animation::Render(HDC hdc)
{
}

void Animation::Reset()
{
	_time = 0;
	_index = 0;
	_complete = false;
}






NAMESPACE_CLOSE