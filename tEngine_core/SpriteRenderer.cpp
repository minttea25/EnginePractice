#include "pch.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"

NAMESPACE_OPEN(tEngine)

SpriteRenderer::SpriteRenderer(GameObject* gameObject)
	: Renderer(gameObject), _textureResource(nullptr)
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

	Transform* tr = gameObject()->GetComponent<Transform>();
	auto pos = tr->position();

	Gdiplus::Graphics graphcis(hdc);
	
	graphcis.DrawImage(image, 
		Gdiplus::Rect(pos.x, pos.y, (int)_textureResource->width(), (int)_textureResource->height()));
}


NAMESPACE_CLOSE