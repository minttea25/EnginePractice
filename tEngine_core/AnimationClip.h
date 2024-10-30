#pragma once

#include "CoreHeader.h"
#include "Motion.h"
#include "AnimationCurve.h"
#include <stdexcept>
#include <functional>
#include <ranges>

NAMESPACE_OPEN(tEngine)

class AnimatorContrller;
class GameObject;

//enum class AnimationProperty
//{
//	Transform,
//	SpriteRenderer
//};


struct UNSAFE AnimationProperty
{
public:
	template<class FieldType>
	void BindRef(FieldType* field)
	{
		_ptr = static_cast<void*>(field);
	}

	template<>
	void BindRef(void* field)
	{
		_ptr = field;
	}

	template<class FieldType>
	void SetValue(FieldType* value)
	{
		_ptr = static_cast<void*>(field);
	}

	template<class FieldType>
	void SetValue(const FieldType value)
	{
		*reinterpret_cast<FieldType*>(_ptr) = value;
	}

	/*template<>
	void SetValue(const float value)
	{
		*reinterpret_cast<float*>(_ptr) = value;
	}*/
private:
	void* _ptr;
};

// Note: Unity에서는 GameObject의 메타데이터를 읽어 호출 가능한 메서드 목록을 불러오고 에디터에서 선택 + 파라미터 값 지정
// Paramter Type: float, string, int, bool
struct AnimationEvent
{
public:
	AnimationEvent(const float time) : _time(time) {}
	~AnimationEvent() {}

	float time() const { return _time; }

	template<class Obj, class... Args>
	void SetMethod(Obj* obj, void(Obj::* pfunc)(Args...), Args&&... args)
	{
		_method = [obj, pfunc, args = std::make_tuple(std::forward<Args>(args)...)]()
			mutable
			{
				std::apply
				(
					[obj, pfunc](Args&&... a)
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
	const float _time;
	std::function<void()> _method;
};

class AnimationClip : public Motion
{
public:
	AnimationClip();
	~AnimationClip();

	// Note: The memory of curve is managed in AnimationClip.
	void SetCurve(const std::string& property, AnimationCurve* curve);

	void ClearCurves();
	void ClearProperties();

	void AddEvent(AnimationEvent& evt);
	void ClearEvents();

	bool IsPlaying() const { return _isPlaying; }
	bool IsLoop() const { return _loop; }

	float GetTriggerTimeEvent(const int index)
	{
		if (index >= _events.size()) throw std::out_of_range("Invalid index for Events");
		return _eventTriggerTimes[index];
	}

	void Play(GameObject* go, const float time);

	bool Bind(GameObject* target);
private:
	void _sort_eventTriggerTimes()
	{
		std::ranges::stable_sort(_eventTriggerTimes);
	}

private:
	Map<std::string, std::pair<AnimationProperty, void*>> _properties;
	Map<std::string, std::pair<AnimationProperty, AnimationCurve*>> _curves;

	MultiMap<float, AnimationEvent> _events;
	Vector<float> _eventTriggerTimes;

	bool _loop;
	bool _isPlaying;
};

NAMESPACE_CLOSE