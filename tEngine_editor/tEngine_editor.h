#pragma once

#include "resource.h"

#include <mmsystem.h>
#include <dinput.h>
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "winmm.lib")

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

#ifdef _DEBUG
#pragma comment(lib, "Debug\\tEngine_window.lib")
#else
#pragma comment(lib, "Release\\tEngine_window.lib")
#endif // _DEBUG