#pragma once

#include "CoreHeader.h"

NAMESPACE_OPEN(tEngine)

class AnimationClip;

// TODO : FSM
// Note : 아직 FSM 구현 안되어 있음 (단순히 단일 clip으로 테스트)

// Note : Unity에서는 애니메이션 재생 모드를 일반 Update 말고도 FixedUpdate에서도 할 수 있음
// (그 외 한가지 옵션 더 있음)

class AnimatorController
{
public:
	T_ENGINE_CORE_API AnimatorController();
	T_ENGINE_CORE_API ~AnimatorController();

	T_ENGINE_CORE_API void PlayAnimation(const float time);
	T_ENGINE_CORE_API void set_clip(AnimationClip* clip) { _clip = clip; } // TEMP
	T_ENGINE_CORE_API AnimationClip* get_clip() { return _clip; }

private:
	void PlayClip(const float time);
private:
	AnimationClip* _clip; // TEMP

	// TEMP
	// TODO : 여기는 only 데이터만 저장..
	// 이벤트 실행 위해 임시
	int _eventTriggeredIndex;
};

NAMESPACE_CLOSE