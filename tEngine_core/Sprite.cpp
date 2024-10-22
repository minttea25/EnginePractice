#include "pch.h"
#include "Sprite.h"

NAMESPACE_OPEN(tEngine)


Sprite::Sprite(graphics::TextureResource* texture, const unsigned int index, const Rect& rect, const Vector2& pivot, const Vector4& border, const Bounds& bounds)
	:
	_rect(rect),
	_border(border), 
	_pivot(pivot),
	_bounds(bounds),
	_index(index),
	_texture(texture)
{
}

Sprite::~Sprite()
{
	_texture = nullptr;
}


NAMESPACE_CLOSE