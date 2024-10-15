#include "pch.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include "Transform.h"

NAMESPACE_OPEN(tEngine)

SpriteRenderer::SpriteRenderer(GameObject* gameObject)
	: Renderer(gameObject), _width(0), _height(0), _image(nullptr)
{
}

SpriteRenderer::~SpriteRenderer()
{
	if (_image != nullptr) delete _image;
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
	Transform* tr = gameObject()->GetComponent<Transform>();
	auto pos = tr->position();

	Gdiplus::Graphics graphcis(hdc);
	graphcis.DrawImage(_image, Gdiplus::Rect(pos.x, pos.y, _width, _height));
}

void SpriteRenderer::LoadImage_Gdiplus(const String& path)
{
	_image = Gdiplus::Image::FromFile(path.c_str());
	_width = _image->GetWidth();
	_height = _image->GetHeight();
}

NAMESPACE_CLOSE