#pragma once

#include "CoreHeader.h"
#include "Enums.h"
#include "Vector3.h"

NAMESPACE_OPEN(tEngine)

class GameObject;

class Object
{
public:
	Object();
	virtual ~Object() noexcept;

	void SetName(const String& name) { _name = name; }
	String& name() { return _name; }

	int GetHashCode() const { return _instanceID; }

	template<_GAMEOBJECT GO>
	static GO* Instantiate(enums::eLayerType type)
	{
		GO* go = new GO();
		go->Init();
		auto g = static_cast<GameObject*>(go);
		_instantiate(g, type);
		
		return go;
	}

	template<_GAMEOBJECT GO>
	static GO* Instantiate(enums::eLayerType type, const Types::Vector3& position)
	{
		GO* go = new GO();
		go->Init();
		auto g = static_cast<GameObject*>(go);
		_instantiate(g, type, position);

		return go;
	}
private:
	T_ENGINE_CORE_API static void _instantiate(GameObject*& go, enums::eLayerType type, const Types::Vector3& position = {});
private:
	String _name;
	const int _instanceID;
};



NAMESPACE_CLOSE