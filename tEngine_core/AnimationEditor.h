#pragma once


#include "CoreHeader.h"
#include "Animation.h"
#include "AnimationClip.h"
#include "Animator.h"
#include "AnimationCurve.h"
#include "AnimationDiscrete.h"
#include "AnimatorController.h"

namespace tEngine
{
	class GameObject;
}

NAMESPACE_OPEN(tEngine::editor)

class AnimationEditor
{
public:
	enum class AnimationPropertyType
	{
		Discrete,
		Curve
	};

public:
	T_ENGINE_CORE_API AnimationEditor();
	T_ENGINE_CORE_API AnimationEditor(AnimationClip* animationClip);

	T_ENGINE_CORE_API bool AddProperty(const std::string& propertyName, GameObject* go, void* field, const AnimationPropertyType& propertyType, std::type_index valueType, void * discreteValue = nullptr, const float curveValue = 0.0f, const int propertyOption = -1);

	T_ENGINE_CORE_API bool AddKeyDiscrete(const std::string& propertyName, void* value, const float time);
	T_ENGINE_CORE_API bool AddKeysDiscrete(const std::string& propertyName, const Vector<void*>& values, const Vector<float>& times);

	T_ENGINE_CORE_API bool AddKeyCurve(const std::string& propertyName, const float value, const float time);
	T_ENGINE_CORE_API bool AddKeysCurve(const std::string& propertyName, const Vector<float>& values, const Vector<float>& times);

	T_ENGINE_CORE_API bool AddEvent(const float time, std::function<void()>&& method);
	//bool AddEvent(const float time, std::function<float>&& method);
	//bool AddEvent(const float time, std::function<std::string>&& method);
	//bool AddEvent(const float time, std::function<int>&& method);
	//bool AddEvent(const float time, std::function<bool>&& method);

	void Save(const String& filename);

	float length() { return _clip->length(); }
	T_ENGINE_CORE_API AnimationClip* GetClip() { return _clip; }

	void UpdateLength(const float length) { _clip->UpdateLength(length); _length = length; }

private:
	AnimationClip* _clip;
	Map<std::string, AnimationPropertyType> _properties;
	float _length;
};

NAMESPACE_CLOSE

