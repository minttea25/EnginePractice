#pragma once

#include "CoreHeader.h"
#include "Motion.h"
#include "AnimationCurve.h"
#include "AnimationDiscrete.h"
#include <stdexcept>
#include <functional>
#include <ranges>
#include <algorithm>

NAMESPACE_OPEN(tEngine)

class AnimatorContrller;
class GameObject;


enum class AnimationPropertyType
{
	Discrete,
	Continuous,
};

struct T_ENGINE_CORE_API UNSAFE AnimationProperty
{
public:
	void* get() { return _ptr; }

	template<_COMPONENT Com, class FieldType>
	void BindRef(FieldType Com::* field, Com* component)
	{
		_ptr = &(component->*field);
	}

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

	void SetValue(void* value)
	{
		*reinterpret_cast<void**>(_ptr) = value;
	}

	template<class FieldType>
	void SetValue(const FieldType value)
	{
		*reinterpret_cast<FieldType*>(_ptr) = value;
	}

private:
	void* _ptr;
};

// Note: Unity������ GameObject�� ��Ÿ�����͸� �о� ȣ�� ������ �޼��� ����� �ҷ����� �����Ϳ��� ���� + �Ķ���� �� ����
// Paramter Type: float, string, int, bool
struct T_ENGINE_CORE_API AnimationEvent
{
public:
	AnimationEvent() : _time(0.0f) {}
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

	void SetMethod(std::function<void()>&& method)
	{
		_method = method;
	}

	void Invoke()
	{
		if (_method) _method();
	}

private:
	const float _time;
	std::function<void()> _method;
};

// TODO : AnimationDiscrete �� Curve�� ��� clip�� ���� �����ϵ��� �߰�
// -> add �� length ������Ʈ �ʿ� (���� add �� ���� �����Ӱ� ������ �����ӿ� key �߰�)

// Note: ���� ���� �ð��� ���� �̺�Ʈ ��� x (using Map now (not multimap))
// Change sort -> stable sort when the type of _events changed into multimap.

class AnimationClip : public Motion
{
public:
	T_ENGINE_CORE_API AnimationClip(const float length = 1.0f);
	T_ENGINE_CORE_API ~AnimationClip();

	// Note: The memory of curve is managed in AnimationClip.
	T_ENGINE_CORE_API void SetCurve(const std::string& property, AnimationProperty& animP, AnimationCurve* curve);
	T_ENGINE_CORE_API void SetDiscrete(const std::string& property, AnimationProperty& animP, AnimationDiscrete* discrete);

	T_ENGINE_CORE_API void ClearCurves();
	T_ENGINE_CORE_API void ClearDiscretes();

	T_ENGINE_CORE_API void AddEvent(AnimationEvent& evt);
	T_ENGINE_CORE_API void ClearEvents();

	void SetDirty();

	bool IsLoop() const { return _loop; }
	float length() const { return _length; }

	float GetTriggerTimeEvent(const int index)
	{
		if (index >= _events.size()) throw std::out_of_range("Invalid index for Events");
		return _eventTriggerTimes[index];
	}

	void InvokeEvent(const float key) { _events[key].Invoke(); }

	auto& get_discretes() { return _discretes; }
	auto& get_curves() { return _curves; }
	auto& get_events() { return _events; }

	//T_ENGINE_CORE_API void Play(GameObject* go, const float currentTime);
private:
	void _sort_eventTriggerTimes()
	{
		std::ranges::sort(_eventTriggerTimes);
	}

private:
	Map<std::string, std::pair<AnimationProperty, AnimationDiscrete*>> _discretes;
	Map<std::string, std::pair<AnimationProperty, AnimationCurve*>> _curves;

	Map<float, AnimationEvent> _events;
	Vector<float> _eventTriggerTimes;

	float _length;
	bool _loop;
};

NAMESPACE_CLOSE