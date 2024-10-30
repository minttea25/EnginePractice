#pragma once

#include "CoreHeader.h"

NAMESPACE_OPEN(tEngine)

class AnimationClip;

class AnimatorController
{
public:
	T_ENGINE_CORE_API AnimatorController();
	T_ENGINE_CORE_API ~AnimatorController();

	T_ENGINE_CORE_API void PlayAnimation(const float time);
	T_ENGINE_CORE_API void set_clip(AnimationClip* clip) { _clip = clip; } // TEMP

private:
	AnimationClip* _clip; // TEMP
};

NAMESPACE_CLOSE