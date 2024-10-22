#pragma once
#include "CoreHeader.h"
#include "Object.h"

namespace tEngine::graphics { class TextureResource; }

NAMESPACE_OPEN(tEngine)
using namespace tEngine::Types;
class Sprite;

class SpriteSheet : public Object
{
public:
	explicit SpriteSheet(graphics::TextureResource* texture);
	~SpriteSheet();

	unsigned int size() const { return _sprites.size(); }
	Sprite* operator[] (const int index) { ASSERT_CRASH(index < _sprites.size()); return _sprites[index]; }

	// API
	void AddSprite(const Rect& rect, const Vector2& pivot = {0, 0}, const Vector4& border = {0, 0, 0, 0});
	void Init();
	void Reset();
	void Slice(const int rows, const int columns);

	void _setName(Sprite*& sprite, const int index);
private:
	void _createSpriteDefault();
	void _clearSprites();
private:
	graphics::TextureResource* _originalTexture;
	Vector<Sprite*> _sprites;
};

NAMESPACE_CLOSE
