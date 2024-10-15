#pragma once

#include "CoreHeader.h"
#include "Object.h"
#include <typeindex>

#include "Component.h"

NAMESPACE_OPEN(tEngine)

class Transform;

class GameObject : public Object
{
	friend class Layer;
public:
	T_ENGINE_CORE_API GameObject();
	T_ENGINE_CORE_API ~GameObject();

	T_ENGINE_CORE_API virtual void Init();
	T_ENGINE_CORE_API virtual void Update();
	T_ENGINE_CORE_API virtual void LateUpdate();
	T_ENGINE_CORE_API virtual void Render(HDC hdc);

	T_ENGINE_CORE_API Transform* transform() { return _transform; }
	T_ENGINE_CORE_API GameObject* gameObject() { return this; }

	template <_COMPONENT Com>
	void AddComponent();

	// TODO : tempalte specification
	/*template<>
	void AddComponent<Transform>();*/
	
	template <_COMPONENT Com>
	Com* GetComponent();

	/*template<>
	Transform* GetComponent() { return _transform; }*/

	template <_COMPONENT Com>
	bool TryGetComponent(OUT Com*& component);

	/*template<>
	bool TryGetComponent(OUT Transform*& component) { component = _transform; return true; }*/
	
private:
	void internal_Update();
	void internal_LateUpdate();
	void internal_Render(HDC hdc);
	void _init_transform();

private:
	Transform* _transform;
	Map<std::type_index, Component*> _components;
};

template<_COMPONENT Com>
inline void GameObject::AddComponent()
{
	auto idx = std::type_index(typeid(Com));
	auto it = _components.find(idx);
	if (it == _components.end())
	{
		Com* com = new Com(this);
		com->Init();
		_components.insert(std::make_pair(idx, com));
	}
	else
	{
		// TODO : warning: already exists
	}
}


template<_COMPONENT Com>
inline Com* GameObject::GetComponent()
{
	auto it = _components.find(std::type_index(typeid(Com)));
	if (it != _components.end())
	{
		Com* com = static_cast<Com*>(it->second);
		if (com) return com;
		else
		{
			// error : casting failed
			return nullptr;
		}
	}
	else return nullptr;
}

template<_COMPONENT Com>
inline bool GameObject::TryGetComponent(OUT Com*& component)
{
	auto it = _components.find(std::type_index(typeid(Com)));
	if (it == _components.end()) return false;
	else
	{
		component = static_cast<Com*>(it->second);
		return component != nullptr;
	}
}

NAMESPACE_CLOSE
