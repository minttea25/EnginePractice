#pragma once

#include "CoreHeader.h"
#include "Renderer.h"
#include "Component.h"


NAMESPACE_OPEN(tEngine)

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

	T_ENGINE_CORE_API void LoadImage_Gdiplus(const String& path);

	T_ENGINE_CORE_API unsigned int width() const { return _width; }
	T_ENGINE_CORE_API unsigned int height() const { return _height; }

private:
	Gdiplus::Image* _image;
	unsigned int _width;
	unsigned int _height;
};

NAMESPACE_CLOSE
