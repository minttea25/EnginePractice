#pragma once
#include "CoreHeader.h"
#include <filesystem>

NAMESPACE_OPEN(tEngine)
class ResourceUtil
{
public:
	static String GetFileExtension(const String& file)
	{
		return std::filesystem::path(file).extension().wstring();
	}

	static bool Exist(const String& path)
	{
		return std::filesystem::exists(path);
	}
};

NAMESPACE_CLOSE