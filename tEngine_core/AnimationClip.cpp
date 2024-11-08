#include "pch.h"
#include "AnimationClip.h"
#include "GameObject.h"

NAMESPACE_OPEN(tEngine)


AnimationClip::AnimationClip(const float length)
	: Motion(), _loop(true), _length(length),
	_discretes{}, _curves{}, _events{}, _eventTriggerTimes{}
{
}

AnimationClip::~AnimationClip()
{
	ClearCurves();
	ClearDiscretes();
	ClearEvents();
}

void AnimationClip::SetCurve(const std::string& property, AnimationProperty animP, AnimationCurve* curve)
{
	_curves.insert({ property, { animP, curve } });
}

void AnimationClip::SetDiscrete(const std::string& property, AnimationProperty animP, AnimationDiscrete* discrete)
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

	// TODO : Duplicates?
	if (_events.find(evt.time()) != _events.end()) return;

	_events.insert({ evt.time(), evt});
}

void AnimationClip::ClearEvents()
{
	_events.clear();
	_eventTriggerTimes.clear();
}




NAMESPACE_CLOSE