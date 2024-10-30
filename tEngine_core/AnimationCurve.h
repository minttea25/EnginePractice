#pragma once

#include "CoreHeader.h"
#include <ranges>
#include <stdexcept>

NAMESPACE_OPEN(tEngine)

enum class AnimationCurveInterpolationMode
{
	Binary,
	Discrete,
	Lerp,
	Hermite,
};

struct KeyFrame
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
	AnimationCurve(AnimationCurveInterpolationMode mode = AnimationCurveInterpolationMode::Lerp);
	~AnimationCurve();

	KeyFrame& operator[](const int index)
	{
		if (index >= _keys.size()) throw std::out_of_range("Invalid KeyFrame index");
	
		return _keys[index];
	}

	int length() const { return _keys.size(); }

	void AddKey(const KeyFrame& keyFrame);
	float Evaluate(const float time) const;
private:
	// Note: std::ranges::stable_sort is constexpr expression method
	void _sort_keyframes() { std::ranges::stable_sort(_keys, {}, &KeyFrame::time); }
	float Lerp(const float a, const float b, const float t) const
	{
		return a + (b - a) * t;
	}

	float HermiteInterpolate(const KeyFrame& kf1, const KeyFrame& kf2, const float t) const {
		float t2 = t * t;
		float t3 = t2 * t;

		float h1 = 2.0f * t3 - 3.0f * t2 + 1.0f;
		float h2 = -2.0f * t3 + 3.0f * t2;
		float h3 = t3 - 2.0f * t2 + t;
		float h4 = t3 - t2;

		return h1 * kf1.value + h2 * kf2.value + h3 * kf1.outTangent + h4 * kf2.inTangent;
	}

	// for bool
	bool Binary (const KeyFrame& kf1, const KeyFrame& kf2)
	{
		// time < next key time -> return current
		return false;
	}

	int Discrete(const KeyFrame& kf1, const KeyFrame& kf2, const float )
	{
		// 보간된 값을 int로 변환 (가능하다면 interval 값으로 세밀하게 조정)
		return 0;
	}

private:
	Vector<KeyFrame> _keys;
	AnimationCurveInterpolationMode _mode; // mode에 따라 다르게 evaluate (int, bool, float)
};

NAMESPACE_CLOSE