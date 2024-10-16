#include "pch.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"

NAMESPACE_OPEN(tEngine)

SpriteRenderer::SpriteRenderer(GameObject* gameObject)
	: Renderer(gameObject), _textureResource(nullptr),
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
	if (_textureResource == nullptr) return;

	auto image = _textureResource->image();
	if (image == nullptr) return;

	auto pos = gameObject()->transform()->position();

	Gdiplus::Graphics graphcis(hdc);
	
	graphcis.DrawImage(image, 
		Gdiplus::Rect(pos.x, pos.y, (int)_textureResource->width() * _scale.x, (int)_textureResource->height() * _scale.y));
}


NAMESPACE_CLOSE