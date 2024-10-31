#include "pch.h"
#include "AnimationDiscrete.h"
NAMESPACE_OPEN(tEngine)

AnimationDiscrete::AnimationDiscrete(const std::type_index& _typeIndex)
	: _keys({}), _typeIndex(_typeIndex), _length(-1)
{
}

AnimationDiscrete::~AnimationDiscrete()
{
}

void AnimationDiscrete::Build()
{
	// TODO more
	_length = _keys.crbegin()->first;
}


void AnimationDiscrete::AddKey(const float time, void* value)
{
	// make new one or exchange the value;
	_keys[time] = value;
}

void* AnimationDiscrete::Evaluate(const float time) const
{
	if (time >= _length) return _keys.crbegin()->second;

	// TODO : slow...
	auto it = _keys.upper_bound(time); // It can not be end()
	it = std::prev(it);

	return it->second;
}

NAMESPACE_CLOSE