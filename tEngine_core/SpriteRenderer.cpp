#include "pch.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"
#include "Sprite.h"
#include "TextureResource.h"

NAMESPACE_OPEN(tEngine)

SpriteRenderer::SpriteRenderer(GameObject* gameObject)
	: Renderer(gameObject), _sprite(nullptr)
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
	if (_sprite == nullptr) return;

	auto image = _sprite->texture()->image();

	auto pos = transform()->position();
	auto scale = transform()->scale();

	Gdiplus::Graphics graphics(hdc);
	graphics.DrawImage(image, (INT)pos.x, (INT)pos.y,
		(INT)_sprite->rect().x, (INT)_sprite->rect().y,
		(INT)(_sprite->rect().width * scale.x), (INT)(_sprite->rect().height * scale.y),
		Gdiplus::UnitPixel);
}


NAMESPACE_CLOSE