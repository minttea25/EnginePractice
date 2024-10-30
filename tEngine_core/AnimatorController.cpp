#include "pch.h"
#include "AnimatorController.h"
#include "AnimationClip.h"

NAMESPACE_OPEN(tEngine)

AnimatorController::AnimatorController()
{
}

AnimatorController::~AnimatorController()
{
}

void AnimatorController::PlayAnimation(const float time)
{
	// TEMP
	// Note : GameObject ref is binded outside (in Editor)
	_clip->Play(nullptr, time);
}

NAMESPACE_CLOSE
