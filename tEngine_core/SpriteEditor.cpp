#include "pch.h"
#include "SpriteEditor.h"
#include "SpriteSheet.h"

NAMESPACE_OPEN(tEngine::editor)

SpriteEditor::SpriteEditor(SpriteSheet* spriteSheet)
	:_spriteSheet(spriteSheet)
{
	ASSERT_CRASH(spriteSheet != nullptr);
}

SpriteEditor::~SpriteEditor()
{
}

void SpriteEditor::AddSprite(const Rect& rect, const Vector2& pivot, const Vector4& border)
{
	_spriteSheet->AddSprite(rect, pivot, border);
}

void SpriteEditor::Slice(const int rows, const int columns)
{
	_spriteSheet->Slice(rows, columns);
}





NAMESPACE_CLOSE