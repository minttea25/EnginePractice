#include "pch.h"
#include "AnimationEditor.h"

NAMESPACE_OPEN(tEngine::editor)

using namespace tEngine;

AnimationEditor::AnimationEditor()
	:  _clip(new AnimationClip()), _length(1.0f)
{
}

AnimationEditor::AnimationEditor(AnimationClip* animationClip)
	: _clip(animationClip), _length(1.0f)
{
}

bool AnimationEditor::AddProperty(const std::string& propertyName, GameObject* go, void* field, const AnimationPropertyType& propertyType, std::type_index valueType, void * discreteValue, const float curveValue, const int propertyOption)
{
	if (_properties.contains(propertyName) == true)
	{
		// already exists
		return true;
	}

	if (propertyType == AnimationPropertyType::Curve)
	{
		AnimationCurve* curve = new AnimationCurve(curveValue, _length, (AnimationCurveInterpolationMode)propertyOption);
		AnimationProperty p{};
		p.BindRef(field);

		_clip->SetCurve(propertyName, p, curve);

		_properties.insert({ propertyName, propertyType });

		return true;
	}
	else if (propertyType == AnimationPropertyType::Discrete)
	{
		AnimationDiscrete* discrete = new AnimationDiscrete(valueType, discreteValue, _length);
		AnimationProperty p{};
		p.BindRef(field);

		_clip->SetDiscrete(propertyName, p, discrete);

		_properties.insert({ propertyName, propertyType });

		return true;
	}
	else
	{
		// Error : error
		return false;
	}
}

bool AnimationEditor::AddKeyDiscrete(const std::string& propertyName, void* value, const float time)
{
	auto it = _properties.find(propertyName);

	// Error : Logic Error
	if (it == _properties.end()) throw std::exception("");

	if (it->second == AnimationPropertyType::Discrete)
	{
		auto it2 = _clip->get_discretes().find(propertyName);
		// Error : Logic Error
		if (it2 == _clip->get_discretes().end()) throw std::exception("");

		auto discrete = it2->second.second;
		discrete->AddKey(time, value);

		UpdateLength(utils::max(_length, time));

		return true;
	}
	else
	{
		// Error
	}

	return false;
}


bool AnimationEditor::AddKeysDiscrete(const std::string& propertyName, const Vector<void*>& values, const Vector<float>& times)
{
	// Error
	if (values.size() != times.size()) throw std::exception("");

	auto it = _properties.find(propertyName);

	// Error : Logic Error
	if (it == _properties.end()) throw std::exception("");
	
	if (it->second == AnimationPropertyType::Discrete)
	{
		auto it2 = _clip->get_discretes().find(propertyName);
		// Error : Logic Error
		if (it2 == _clip->get_discretes().end()) throw std::exception("");

		auto discrete = it2->second.second;
		for (int i = 0; i < values.size(); ++i)
		{
			discrete->AddKey(times[i], values[i]);
			UpdateLength(utils::max(_length, times[i]));
		}

		return true;
	}
	else
	{
		// Error
	}

	return false;
}

bool AnimationEditor::AddKeyCurve(const std::string& propertyName, const float value, const float time)
{
	auto it = _properties.find(propertyName);

	// Error : Logic Error
	if (it == _properties.end()) throw std::exception("");

	if (it->second == AnimationPropertyType::Curve)
	{
		auto it2 = _clip->get_curves().find(propertyName);
		// Error : Logic Error
		if (it2 == _clip->get_curves().end()) throw std::exception("");

		auto curve = it2->second.second;
		curve->AddKey(time, value);

		UpdateLength(utils::max(_length, time));

		return true;
	}
	else
	{
		// Error
	}

	return false;
}

bool AnimationEditor::AddKeysCurve(const std::string& propertyName, const Vector<float>& values, const Vector<float>& times)
{
	// Error
	if (values.size() != times.size()) throw std::exception("");

	auto it = _properties.find(propertyName);

	// Error : Logic Error
	if (it == _properties.end()) throw std::exception("");

	if (it->second == AnimationPropertyType::Curve)
	{
		auto it2 = _clip->get_curves().find(propertyName);
		// Error : Logic Error
		if (it2 == _clip->get_curves().end()) throw std::exception("");

		auto curve = it2->second.second;
		for (int i = 0; i < values.size(); ++i)
		{
			curve->AddKey(times[i], values[i]);
			UpdateLength(utils::max(_length, times[i]));
		}

		return true;
	}
	else
	{
		// Error
	}

	return false;
}

bool AnimationEditor::AddEvent(const float time, std::function<void()>&& method)
{
	AnimationEvent evt(time);
	evt.SetMethod(std::move(method));

	_clip->AddEvent(evt);

	return true;
}

void AnimationEditor::Save(const String& filename)
{
	throw std::exception("Not implemented.");
}

NAMESPACE_CLOSE