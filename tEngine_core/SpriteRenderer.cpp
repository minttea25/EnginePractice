#include "pch.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "Sprite.h"
#include "TextureResource.h"

NAMESPACE_OPEN(tEngine)

SpriteRenderer::SpriteRenderer(GameObject* gameObject)
	: Renderer(gameObject), _sprite(nullptr),
	_scale(Types::Vector3::One())
{
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Init()
{
}

void SpriteRenderer::Update()
{
}

void SpriteRenderer::LateUpdate()
{
}

void SpriteRenderer::Render(HDC hdc)
{
	/*if (_textureResource == nullptr) return;

	auto image = _textureResource->image();
	if (image == nullptr) return;

	auto pos = gameObject()->transform()->position();

	Gdiplus::Graphics graphcis(hdc);
	
	graphcis.DrawImage(image, 
		Gdiplus::Rect(pos.x, pos.y, (int)_textureResource->width() * _scale.x, (int)_textureResource->height() * _scale.y));*/

	if (_sprite == nullptr) return;

	auto image = _sprite->texture()->image();

	auto pos = transform()->position();

	Gdiplus::Graphics graphics(hdc);
	graphics.DrawImage(image, (INT)pos.x, (INT)pos.y,
		(INT)_sprite->rect().x, (INT)_sprite->rect().y,
		(INT)(_sprite->rect().width), (INT)(_sprite->rect().height),
		Gdiplus::UnitPixel);
}


NAMESPACE_CLOSE