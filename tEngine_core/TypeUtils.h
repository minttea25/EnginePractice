#pragma once
#include "Rect.h"
#include "Vector3.h"

namespace tEngine::utils
{
    using namespace tEngine::Types;

    inline static Gdiplus::RectF ToRectF(const tEngine::Types::Rect& rect)
    {
        return Gdiplus::RectF(rect.x, rect.y, rect.width, rect.height);
    }

    inline static Gdiplus::RectF ToRectFDrawDest(const Rect& rect, const Vector3& pos, const Vector3& scale)
    {
        return Gdiplus::RectF(pos.x, pos.y, rect.width * scale.x, rect.height * scale.y);
    }
}

