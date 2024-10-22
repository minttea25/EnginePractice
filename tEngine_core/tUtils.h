#pragma once

namespace tEngine::utils
{

    template<class T> requires requires(T a, T b) { a < b; }
    const T& max(const T& a, const T& b)
    {
        return (a < b) ? b : a;
    }

    template<class T> requires requires(T a, T b) { a < b; }
    const T& min(const T& a, const T& b)
    {
        return (a < b) ? b : a;
    }

}
