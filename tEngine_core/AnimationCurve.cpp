#include "pch.h"
#include "AnimationCurve.h"


NAMESPACE_OPEN(tEngine)


AnimationCurve::AnimationCurve(const float initValue, const float lastTime, const AnimationCurveInterpolationMode mode)
	: _mode(mode), _keys{}
{
	_keys.push_back(KeyFrame(0.0f, initValue));
	_keys.push_back(KeyFrame(lastTime, initValue));
}

AnimationCurve::~AnimationCurve()
{
	_keys.clear();
}


float AnimationCurve::LastLength() const
{
	// Note : the size is at least 1. (start frame state)
	ASSERT_CRASH(_keys.size() != 0);
	return _keys.crbegin()->time;
}

void AnimationCurve::AddKey(const KeyFrame& keyFrame)
{
	auto it = std::ranges::find(_keys, keyFrame.time, &KeyFrame::time);
	if (it != _keys.end())
	{
		*it = keyFrame;
	}
	else
	{
		_keys.push_back(keyFrame);
		_sort_keyframes();
	}
}

void AnimationCurve::AddKey(const float time, const float value)
{
	auto it = std::ranges::find(_keys, time, &KeyFrame::time);
	if (it != _keys.end())
	{
		*it = KeyFrame(time, value);
	}
	else
	{
		_keys.push_back(KeyFrame(time, value));
		_sort_keyframes();
	}
}

float AnimationCurve::Evaluate(const float time) const
{
	if (_keys.empty()) return 0.0f;

	if (time <= _keys.front().time) return _keys.front().value;

	if (time >= _keys.back().time) return _keys.back().value;

	auto it = std::ranges::upper_bound(_keys, time, {}, &KeyFrame::time);

	const KeyFrame& kf1 = *std::prev(it);
	const KeyFrame& kf2 = *it;
	const float t = (time - kf1.time) / (kf2.time - kf1.time); // 기울기
	switch (_mode)
	{
	case tEngine::AnimationCurveInterpolationMode::Binary:
		return BinaryBool(kf1) ? 1.0f : 0.0f;
	case tEngine::AnimationCurveInterpolationMode::Discrete:
		return DiscreteInt(kf1, kf2, t);
	case tEngine::AnimationCurveInterpolationMode::Lerp:
		return Lerp(kf1.value, kf2.value, t);
	case tEngine::AnimationCurveInterpolationMode::Hermite:
		return HermiteInterpolate(kf1, kf2, t);
	default:
		// error undefined
		return 0.0f;
	}
}

float AnimationCurve::Lerp(const float a, const float b, const float t) const
{
	float tt = a + (b - a) * t;
	//OutputDebugStringW(std::to_wstring(tt).c_str());
	//OutputDebugStringW(L"\n");
	return a + (b - a) * t;
}

float AnimationCurve::HermiteInterpolate(const KeyFrame& kf1, const KeyFrame& kf2, const float t) const
{
	float t2 = t * t;
	float t3 = t2 * t;

	float h1 = 2.0f * t3 - 3.0f * t2 + 1.0f;
	float h2 = -2.0f * t3 + 3.0f * t2;
	float h3 = t3 - 2.0f * t2 + t;
	float h4 = t3 - t2;

	return h1 * kf1.value + h2 * kf2.value + h3 * kf1.outTangent + h4 * kf2.inTangent;
}

bool AnimationCurve::BinaryBool(const KeyFrame& kf) const
{
	return kf.value;
}

int AnimationCurve::DiscreteInt(const KeyFrame& kf1, const KeyFrame& kf2, const float timeDiff) const
{
	// 보간된 값을 int로 변환 (only Lerp)
	return static_cast<int>(Lerp(kf1.value, kf2.value, timeDiff));
}

NAMESPACE_CLOSE


