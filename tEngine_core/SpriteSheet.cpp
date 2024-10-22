#include "pch.h"
#include "SpriteSheet.h"
#include "TextureResource.h"
#include "Sprite.h"

NAMESPACE_OPEN(tEngine)

using namespace tEngine::Types;

SpriteSheet::SpriteSheet(graphics::TextureResource* texture)
	:_originalTexture(texture)
{
	ASSERT_CRASH(texture != nullptr);
	ASSERT_CRASH(texture->IsLoaded());
}

SpriteSheet::~SpriteSheet()
{
	_originalTexture = nullptr;
	for (auto s : _sprites) delete s;
	_sprites.clear();
}

void SpriteSheet::AddSprite(const Rect& rect, const Vector2& pivot, const Vector4& border)
{
	int index = _sprites.size();
	Sprite* sprite
		= new Sprite(_originalTexture, index, rect, pivot,
			border);

	_setName(sprite, index);
	_sprites.push_back(sprite);
}

void SpriteSheet::Init()
{
	ASSERT_CRASH(_sprites.size() == 0);
	_createSpriteDefault();
}

void SpriteSheet::Reset()
{
	_clearSprites();
	_createSpriteDefault();
}

void SpriteSheet::Slice(const int rows, const int columns)
{
	ASSERT_CRASH(rows != 0 && columns != 0)

	_clearSprites();

	int width = _originalTexture->width();
	int height = _originalTexture->height();

	int unit_width = width / rows;
	int unit_height = height / columns;

	if (unit_width == 0 || unit_height == 0)
	{
		_createSpriteDefault();
		return;
	}

	int idx = 0;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			int x = i * unit_width;
			int y = j * unit_height;
			Sprite* sprite = new Sprite(
				_originalTexture,
				idx,
				Rect(x, y, unit_width, unit_height));
			_setName(sprite, idx);
			_sprites.push_back(sprite);
			idx++;
		}
	}
}

void SpriteSheet::_setName(Sprite*& sprite, const int index)
{
	sprite->SetName(_originalTexture->name() + L"_" + std::to_wstring(index));
}

void SpriteSheet::_createSpriteDefault()
{
	Sprite* sprite
		= new Sprite(_originalTexture, 0, Rect(0, 0, _originalTexture->width(), _originalTexture->height()));

	_setName(sprite, 0);
	_sprites.push_back(sprite);
}

void SpriteSheet::_clearSprites()
{
	for (auto s : _sprites) delete s;
	_sprites.clear();
}


NAMESPACE_CLOSE
