// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#define NOMINMAX

#define T_ENGINE_CORE_EXPORTS

// add headers that you want to pre-compile here
#include "framework.h"

#include <cmath>
#include <iostream>
#include <vector>
#include <winnt.h>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <typeindex>
#include <filesystem>
#include <ranges>



#include "CoreMacro.h"
#include "tTypes.h"
#include "tUtils.h"

#include "Vector2.h"
#include "Vector2Int.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Color.h"
#include "Rect.h"
#include "Bounds.h"
#include "Quaternion.h"


#include "Object.h"
#include "tTime.h"
#include "tInput.h"


#endif //PCH_H
