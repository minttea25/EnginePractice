#pragma once
#include "CoreHeader.h"
#include "Object.h"

NAMESPACE_OPEN(tEngine)

class GameObject;
class Transform;

class Component : public Object
{
public:
	T_ENGINE_CORE_API explicit Component(GameObject* gameObject);
	T_ENGINE_CORE_API virtual ~Component();

	T_ENGINE_CORE_API virtual void Init();
	T_ENGINE_CORE_API virtual void Update();
	T_ENGINE_CORE_API virtual void LateUpdate();
	T_ENGINE_CORE_API virtual void Render(HDC hdc);

	void set_GameObject(GameObject* gameObject) { _gameObject = gameObject; };
	T_ENGINE_CORE_API GameObject* gameObject() { return _gameObject; }

	T_ENGINE_CORE_API Transform* transform();
private:
	GameObject* _gameObject;
};

NAMESPACE_CLOSE