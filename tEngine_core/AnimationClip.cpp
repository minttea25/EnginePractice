#include "pch.h"
#include "AnimationClip.h"
#include "GameObject.h"

NAMESPACE_OPEN(tEngine)

AnimationClip::AnimationClip()
{
}

AnimationClip::~AnimationClip()
{
	ClearCurves();
	ClearEvents();
}

void AnimationClip::SetCurve(const std::string& property, AnimationCurve* curve)
{
	// TODO
	// CURRENT
}

void AnimationClip::ClearCurves()
{
	for (auto& ptr : _curves) delete ptr.second.second;
	_curves.clear();
}

void AnimationClip::ClearProperties()
{
	_properties.clear();
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
	// TODO : What if there are more properties?
		
	auto transform = go->transform(); // NOT NULL
	
}


NAMESPACE_CLOSE