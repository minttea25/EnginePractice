#include "pch.h"
#include "Animation.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Sprite.h"
#include "TypeUtils.h"

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

void Animation::CreateAnimation(Vector<Sprite*> spriteSheet, Vector<float> intervals)
{
	_sprites = spriteSheet;
	_intervals = intervals;
	
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
		if (_index >= _intervals.size() - 1)
		{
			_complete = true;
		}
		else _index++;
	}
}

void Animation::LateUpdate()
{
}

void Animation::Render(HDC hdc)
{
	if (_sprites.size() == 0) return;
	auto sprite = _sprites[_index];
	auto image = sprite->texture()->image();

	auto pos = transform()->position();

	//Gdiplus::ImageAttributes imgAttr = {};
	//imgAttr.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

	Gdiplus::Graphics graphics(hdc);

	float rotation = transform()->RotationZ();

	graphics.TranslateTransform(pos.x, pos.y);
	graphics.RotateTransform(rotation);
	graphics.TranslateTransform(-pos.x, -pos.y);



	auto rect = utils::ToRectFDrawDest(sprite->rect(), pos, transform()->scale());

	graphics.DrawImage(image, rect,
		sprite->rect().x, sprite->rect().y,
		sprite->width(), sprite->height(), Gdiplus::UnitPixel);

	/*graphics.DrawImage(image, (INT)pos.x, (INT)pos.y,
		(INT)sprite->rect().x, (INT)sprite->rect().y,
		(INT)(sprite->width() * scale.x), (INT)(sprite->height() * scale.y),
		Gdiplus::UnitPixel);*/

}

void Animation::Reset()
{
	_time = 0;
	_index = 0;
	_complete = false;
}






NAMESPACE_CLOSE