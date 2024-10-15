#pragma once
#include "CoreHeader.h"
#include "Object.h"

NAMESPACE_OPEN(tEngine)

class GameObject;

class Component : public Object
{
public:
	explicit Component(GameObject* gameObject);
	virtual ~Component();

	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	void set_GameObject(GameObject* gameObject) { _gameObject = gameObject; };
	GameObject* gameObject() { return _gameObject; }
private:
	GameObject* _gameObject;
};

NAMESPACE_CLOSE