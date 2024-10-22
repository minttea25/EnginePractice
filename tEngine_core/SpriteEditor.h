#pragma once
#include "CoreHeader.h"
#include "Rect.h"
#include "Vector2.h"
#include "Vector4.h"

namespace tEngine { class SpriteSheet; }

NAMESPACE_OPEN(tEngine::editor)

using namespace tEngine::Types;

class SpriteEditor
{
public:
	T_ENGINE_CORE_API SpriteEditor(SpriteSheet* spriteSheet);
	T_ENGINE_CORE_API ~SpriteEditor();

	T_ENGINE_CORE_API void AddSprite(const Rect& rect, const Vector2& pivot = { 0, 0 }, const Vector4& border = { 0, 0, 0, 0 });
	T_ENGINE_CORE_API void Slice(const int rows, const int columns);

private:
	SpriteSheet* _spriteSheet;
};

NAMESPACE_CLOSE