#pragma once

#include "CoreHeader.h"
#include "Motion.h"
#include <stdexcept>
#include <functional>

NAMESPACE_OPEN(tEngine)

class AnimatorContrller;

// TODO : Animation Curve ?...

struct KeyFrame
{
	float time;
	// TODO
};

// Note: Unity에서는 GameObject의 메타데이터를 읽어 호출 가능한 메서드 목록을 불러오고 에디터에서 선택 + 파라미터 값 지정
// Paramter Type: float, string, int, bool
struct AnimationEvent
{
public:
	AnimationEvent(const float time) : time(time) {}
	~AnimationEvent() {}

	template<class Obj, class... Args>
	void SetMethod(Obj* obj, void(Obj::* pfunc)(Args...), Args&&... args)
	{
		_method = [obj, pfunc, args = std::make_tuple(std::forward<Args>(args)...)]()
			mutable
			{
				std::apply
				(
					[obj, pfunc](Ars&&... a)
					{
						(obj->*pfunc)(std::forward<Args>(a)...);
					},
					std::move(args)
				);
			};
	}

	void Invoke()
	{
		if (_method) _method();
	}

private:
	const float time;
	std::function<void()> _method;
};

class AnimationClip : public Motion
{
public:
	AnimationClip();
	~AnimationClip();

	bool IsPlaying() const { return _isPlaying; }
	bool IsLoop() const { return _loop; }

	float GetTriggerTimeKeyFrame(const int index)
	{
		if (index >= _keyFrames.size()) throw std::out_of_range("Invalid index for KeyFrames");
		return _keyFrameTriggerTimes[index];
	}

	float GetTriggerTimeEvent(const int index)
	{
		if (index >= _events.size()) throw std::out_of_range("Invalid index for Events");
		return _eventTriggerTimes[index];
	}

private:
	Map<float, KeyFrame> _keyFrames;
	Map<float, AnimationEvent> _events;
	Vector<float> _keyFrameTriggerTimes;
	Vector<float> _eventTriggerTimes;

	bool _loop;
	bool _isPlaying;
};

NAMESPACE_CLOSE