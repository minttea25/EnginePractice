#pragma once

#include "CoreHeader.h"
#include "Renderer.h"
#include "Component.h"
#include "TextureResource.h"
#include "Vector3.h"

NAMESPACE_OPEN(tEngine)

using namespace Types;

class GameObject;

class SpriteRenderer final : public Renderer
{
public:
	T_ENGINE_CORE_API SpriteRenderer(GameObject* gameObject);
	T_ENGINE_CORE_API ~SpriteRenderer();

	T_ENGINE_CORE_API void Init() override;
	T_ENGINE_CORE_API void Update() override;
	T_ENGINE_CORE_API void LateUpdate() override;
	T_ENGINE_CORE_API void Render(HDC hdc) override;

	// TODO : think about shared_pointer.
	// Is textureResource controlled outside of this class?
	// What if the set_texture_resource called although _textureResource is already existing?

	T_ENGINE_CORE_API void set_texture_resource(graphics::TextureResource* textureResource) { _textureResource = textureResource; }
	T_ENGINE_CORE_API graphics::TextureResource* texture_resource() { return _textureResource; }

	T_ENGINE_CORE_API Vector3 scale() const { return _scale; }
	T_ENGINE_CORE_API void set_scale(const Vector3& scale)
	{
		_scale = { scale.x, scale.y, scale.z };
	}
private:
	graphics::TextureResource* _textureResource;
	Vector3 _scale;

};

NAMESPACE_CLOSE
