#pragma once
#include "CoreHeader.h"
#include <ranges>
#include <algorithm>
#include <stdexcept>
#include <typeindex>

NAMESPACE_OPEN(tEngine)

struct KeyFrameDiscrete
{
public:
	float time;
	void* value;
};

class AnimationDiscrete
{
public:
	T_ENGINE_CORE_API AnimationDiscrete(const std::type_index& _typeIndex, void* firstFrameValue, const float lastTime);
	T_ENGINE_CORE_API ~AnimationDiscrete();

	int size() const { return _keys.size(); }
	float LastLength() const;
	std::type_index get_value_type() const { return _typeIndex; }

	T_ENGINE_CORE_API void AddKey(const float time, void* value);
	T_ENGINE_CORE_API void* GetValue(const float time) const;

private:

private:
	Map<float, void*> _keys;
	std::type_index _typeIndex;	
};

NAMESPACE_CLOSE