#pragma once

#include "CoreHeader.h"
#include <ranges>
#include <algorithm>
#include <stdexcept>

NAMESPACE_OPEN(tEngine)

enum class AnimationCurveInterpolationMode
{
	Binary,  // Check again
	Discrete,  // Check again
	Lerp, // Ok
	Hermite, // Check again
};

struct T_ENGINE_CORE_API KeyFrame
{
public:
	explicit KeyFrame(const float time, const float value)
		: time(time), value(value), inTangent(0), outTangent(0)
	{
	}

	explicit KeyFrame(const float time, const float value, 
		const float inTangent, const float outTangent)
		: time(time), value(value), inTangent(inTangent), outTangent(outTangent)
	{
	}

public:
	float time;
	float value;
	float inTangent;
	float outTangent;
};


class AnimationCurve
{
public:
	T_ENGINE_CORE_API AnimationCurve(AnimationCurveInterpolationMode mode = AnimationCurveInterpolationMode::Lerp);
	T_ENGINE_CORE_API ~AnimationCurve();

	KeyFrame& operator[](const int index)
	{
		if (index >= _keys.size()) throw std::out_of_range("Invalid KeyFrame index");
	
		return _keys[index];
	}

	int size() const { return _keys.size(); }

	T_ENGINE_CORE_API void AddKey(const KeyFrame& keyFrame);
	T_ENGINE_CORE_API float Evaluate(const float time) const;
private:
	// Note: std::ranges::stable_sort is constexpr expression method
	void _sort_keyframes() { std::ranges::stable_sort(_keys, {}, &KeyFrame::time); }
	
	float Lerp(const float a, const float b, const float t) const;

	float HermiteInterpolate(const KeyFrame& kf1, const KeyFrame& kf2, const float t) const;
	
	// for bool
	bool BinaryBool(const KeyFrame& kf) const;
	
	int DiscreteInt(const KeyFrame& kf1, const KeyFrame& kf2, const float timeDiff) const;

private:
	Vector<KeyFrame> _keys;
	AnimationCurveInterpolationMode _mode; // mode에 따라 다르게 evaluate (int, bool, float)
};

NAMESPACE_CLOSE