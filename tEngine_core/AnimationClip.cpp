#include "pch.h"
#include "AnimationClip.h"
#include "GameObject.h"

NAMESPACE_OPEN(tEngine)

AnimationClip::AnimationClip()
	: Motion(), _loop(true), _isPlaying(false)
{
}

AnimationClip::~AnimationClip()
{
	ClearCurves();
	ClearDiscretes();
	ClearEvents();
}

void AnimationClip::SetCurve(const std::string& property, AnimationProperty& animP, AnimationCurve* curve)
{
	_curves.insert({ property, { animP, curve } });
}

void AnimationClip::SetDiscrete(const std::string& property, AnimationProperty& animP, AnimationDiscrete* discrete)
{
	_discretes.insert({ property,  {animP, discrete } });
}

void AnimationClip::ClearCurves()
{
	for (auto& ptr : _curves) delete ptr.second.second;
	_curves.clear();
}

void AnimationClip::ClearDiscretes()
{
	for (auto& ptr : _discretes) delete ptr.second.second;
	_discretes.clear();
}

void AnimationClip::AddEvent(AnimationEvent& evt)
{
	_eventTriggerTimes.push_back(evt.time());
	_sort_eventTriggerTimes();

	_events.insert({ evt.time(), evt});
}

void AnimationClip::ClearEvents()
{
	_events.clear();
	_eventTriggerTimes.clear();
}

void AnimationClip::Play(GameObject* go, const float time)
{
	for (auto& kv : _discretes)
	{
		void* value = kv.second.second->Evaluate(time);
		kv.second.first.SetValue(value);
	}

	for (auto& kv : _curves)
	{
		float value = kv.second.second->Evaluate(time);
		kv.second.first.SetValue<float>(value);
	}
}


NAMESPACE_CLOSE