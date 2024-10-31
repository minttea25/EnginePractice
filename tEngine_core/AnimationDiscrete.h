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
	T_ENGINE_CORE_API AnimationDiscrete(const std::type_index& _typeIndex);
	T_ENGINE_CORE_API ~AnimationDiscrete();

	T_ENGINE_CORE_API void Build();

	int size() const { return _keys.size(); }
	float length() const { return _length; }
	std::type_index get_value_type() const { return _typeIndex; }

	T_ENGINE_CORE_API void AddKey(const float time, void* value);
	T_ENGINE_CORE_API void* Evaluate(const float time) const;

private:

private:
	Map<float, void*> _keys;
	std::type_index _typeIndex;
	float _length;
	
};

NAMESPACE_CLOSE