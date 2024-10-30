#include "pch.h"
#include "AnimationCurve.h"


NAMESPACE_OPEN(tEngine)


AnimationCurve::AnimationCurve(AnimationCurveInterpolationMode mode)
	: _mode(mode)
{
}

AnimationCurve::~AnimationCurve()
{
}

void AnimationCurve::AddKey(const KeyFrame& keyFrame)
{
	_keys.push_back(keyFrame);
	_sort_keyframes();
}

float AnimationCurve::Evaluate(const float time) const
{
	if (_keys.empty()) return 0.0f;

	if (time <= _keys.front().time) return _keys.front().value;

	if (time >= _keys.back().time) return _keys.back().value;

	auto it = std::ranges::lower_bound(_keys, time, {}, &KeyFrame::time);
	if (it == _keys.begin()) return _keys.front().value;
	else if (it >= std::prev(_keys.end())) return _keys.back().value;
	else
	{
		const KeyFrame& kf1 = *it;
		const KeyFrame& kf2 = *std::next(it);
		const float t = (time - kf1.time) / (kf2.time - kf1.time);
		
		if (_mode == AnimationCurveInterpolationMode::Lerp)
			return Lerp(kf1.value, kf2.value, t);
		else return HermiteInterpolate(kf1, kf2, t);
	}

	// error
	return 0.0f;
}

float KeyFrame_float::Evaluate(const float time)
{
	return 0.0f;
}

NAMESPACE_CLOSE


