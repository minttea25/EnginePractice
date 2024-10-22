#pragma once
#include "CoreHeader.h"
#include "Object.h"
#include "Bounds.h"
#include "Rect.h"
#include "Vector4.h"

NAMESPACE_OPEN(tEngine)
namespace graphics { class TextureResource; }

class Sprite final : public Object
{
public:
	Sprite()
		: _bounds({}), _rect({}),
		_border({}), _pivot({ 0.5f, 0.5f }),
		_index(0)
	{

	}
	~Sprite() {}

	unsigned int index() const { return _index; }
	void set_index(const unsigned int index) { _index = index; }

	Bounds bounds() const { return _bounds; }
	Rect rect() const { return _rect; }
	Vector4 border() const { return _border; }
	Vector2 pivot() const { return _pivot; }

	graphics::TextureResource* texture() { return _texture; }
	void set_texture(graphics::TextureResource* texture) { _texture = texture; }
private:
	Bounds _bounds;
	Rect _rect;
	Vector4 _border;
	Vector2 _pivot;
	unsigned int _index;
	graphics::TextureResource* _texture;
};

NAMESPACE_CLOSE
