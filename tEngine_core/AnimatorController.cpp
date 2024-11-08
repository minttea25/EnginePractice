#include "pch.h"
#include "AnimatorController.h"
#include "AnimationClip.h"

NAMESPACE_OPEN(tEngine)

AnimatorController::AnimatorController()
	:_clip(nullptr), _eventTriggeredIndex(0)
{
}

AnimatorController::~AnimatorController()
{
}

void AnimatorController::PlayAnimation(const float time)
{
	// TEMP
	// Note : GameObject ref is binded outside (in Editor)
	PlayClip(time);
}

void AnimatorController::PlayClip(const float time)
{
	for (auto& kv : _clip->get_discretes())
	{
		void* value = kv.second.second->GetValue(time);
		kv.second.first.SetValue(value);
	}
	
	for (auto& kv : _clip->get_curves())
	{
		float value = kv.second.second->Evaluate(time);
		kv.second.first.SetValue<float>(value);
	}

	// TODO : È¿À²..
	int i = 0;
	for (auto& [t, evt] : _clip->get_events())
	{
		i++;
		if (t <= time && i > _eventTriggeredIndex)
		{
			evt.Invoke();
			_eventTriggeredIndex++;
		}
		else if (t > time) break;
	}

	if (_eventTriggeredIndex == _clip->get_events().size() && _clip->IsLoop()) _eventTriggeredIndex = 0;
}

NAMESPACE_CLOSE
