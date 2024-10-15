#pragma once

#include "CoreHeader.h"
#include "Resource.h"

NAMESPACE_OPEN(tEngine::graphics)

class TextureResource final : public Resource
{
public:
	enum class eTextureType
	{
		None,
		Png,
		Bmp,
	};

	T_ENGINE_CORE_API explicit TextureResource(const String& path);
	T_ENGINE_CORE_API ~TextureResource();

	T_ENGINE_CORE_API HRESULT Load() override;

	T_ENGINE_CORE_API unsigned int width() const { return _width; }
	T_ENGINE_CORE_API unsigned int height() const { return _height; }
	T_ENGINE_CORE_API eTextureType texture_type() const { return _type; }
	T_ENGINE_CORE_API Gdiplus::Image* image() { return _image; }

private:
	eTextureType _type;
	Gdiplus::Image* _image;

	// meta
	unsigned int _width;
	unsigned int _height;
};

NAMESPACE_CLOSE