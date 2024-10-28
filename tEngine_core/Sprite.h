#pragma once
#include "CoreHeader.h"
#include "Object.h"
#include "Bounds.h"
#include "Rect.h"
#include "Vector4.h"


NAMESPACE_OPEN(tEngine)
using namespace tEngine::Types;

namespace graphics { class TextureResource; }

class Sprite final : public Object
{
public:
	explicit Sprite(
		graphics::TextureResource* texture,
		const unsigned int index,
		const Rect& rect, 
		const Vector2& pivot = {},
		const Vector4& border = {},
		const Bounds& bounds = {} 
		);
	~Sprite() noexcept;

	unsigned int index() const { return _index; }
	void set_index(const unsigned int index) { _index = index; }

	Bounds bounds() const { return _bounds; }
	Rect rect() const { return _rect; }
	Vector4 border() const { return _border; }
	Vector2 pivot() const { return _pivot; }

	float width() const { return _rect.width; }
	float height() const { return _rect.height; }

	graphics::TextureResource* texture() { return _texture; }
	void set_texture(graphics::TextureResource* texture) { _texture = texture; }
private:
	Rect _rect;
	Vector2 _pivot;
	Vector4 _border;
	Bounds _bounds;
	unsigned int _index;
	graphics::TextureResource* _texture;
};

NAMESPACE_CLOSE
