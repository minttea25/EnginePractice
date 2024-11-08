#include "pch.h"
#include "AnimationDiscrete.h"
NAMESPACE_OPEN(tEngine)

AnimationDiscrete::AnimationDiscrete(const std::type_index& _typeIndex, void* firstFrameValue, const float lastTime)
	: _keys{ { 0.0f, firstFrameValue }, {lastTime, firstFrameValue } }, _typeIndex(_typeIndex)
{
}

AnimationDiscrete::~AnimationDiscrete()
{
	_keys.clear();
}

float AnimationDiscrete::LastLength() const
{
	// Note : the size is at least 2. (start and last frame state)
	ASSERT_CRASH(_keys.size() != 0);
	auto a = _keys.crbegin()->first;
	return _keys.crbegin()->first;
}

void AnimationDiscrete::AddKey(const float time, void* value)
{
	// make new one or exchange the value;
	_keys[time] = value;
}

void* AnimationDiscrete::GetValue(const float time) const
{
	// TODO : slow...
	auto it = _keys.upper_bound(time);
	if (it == _keys.end() || it->first == _keys.crbegin()->first) return _keys.crbegin()->second;
	else return std::prev(it)->second;
}

NAMESPACE_CLOSE