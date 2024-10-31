#pragma once

#include "CoreHeader.h"

NAMESPACE_OPEN(tEngine)

class AnimationClip;

// TODO : FSM
// Note : ���� FSM ���� �ȵǾ� ���� (�ܼ��� ���� clip���� �׽�Ʈ)

// Note : Unity������ �ִϸ��̼� ��� ��带 �Ϲ� Update ���� FixedUpdate������ �� �� ����
// (�� �� �Ѱ��� �ɼ� �� ����)

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
	// TODO : ����� only �����͸� ����..
	// �̺�Ʈ ���� ���� �ӽ�
	int _eventTriggeredIndex;
};

NAMESPACE_CLOSE