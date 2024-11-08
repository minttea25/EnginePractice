#pragma once

#include "CoreHeader.h"
#include "Renderer.h"
#include "Component.h"
#include "Vector3.h"

NAMESPACE_OPEN(tEngine)

using namespace Types;

class GameObject;
class Sprite;

class SpriteRenderer final : public Renderer
{
public:
	T_ENGINE_CORE_API SpriteRenderer(GameObject* gameObject);
	T_ENGINE_CORE_API ~SpriteRenderer();

	T_ENGINE_CORE_API void Init() override;
	T_ENGINE_CORE_API void Update() override;
	T_ENGINE_CORE_API void LateUpdate() override;
	T_ENGINE_CORE_API void Render(HDC hdc) override;

	T_ENGINE_CORE_API void set_sprite(Sprite* sprite) { _sprite = sprite; }
	T_ENGINE_CORE_API Sprite* sprite() { return _sprite; }

	T_ENGINE_CORE_API void* get_sprite_ref() { return &_sprite; }
public:
	Sprite* _sprite;

};

NAMESPACE_CLOSE
