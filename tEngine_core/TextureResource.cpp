#include "pch.h"
#include "TextureResource.h"
#include "ResourceUtil.h"


NAMESPACE_OPEN(tEngine::graphics)


TextureResource::TextureResource(const String& path)
    : Resource(enums::eResourceType::Texture), _type(eTextureType::None),
    _width(0), _height(0), _image(nullptr)
{
    Resource::set_path(path);
}

TextureResource::~TextureResource()
{
    if (_image != nullptr) delete _image;
}

HRESULT TextureResource::Load()
{
    if (ResourceUtil::Exist(Resource::path()) == false)
    {
        // error : no file on that path
        return S_FALSE;
    }
    auto ext = ResourceUtil::GetFileExtension(Resource::path());

    // TEMP
    if (ext == L".png") _type = eTextureType::Png;
    else if (ext == L".bmp") _type = eTextureType::Bmp;
    else
    {
        // warning : this file is not supported
        return S_FALSE;
    }

    _image = Gdiplus::Image::FromFile(Resource::path().c_str());

    if (_image == nullptr) return S_FALSE;

    _width = _image->GetWidth();
    _height = _image->GetHeight();

    return S_OK;
}

NAMESPACE_CLOSE