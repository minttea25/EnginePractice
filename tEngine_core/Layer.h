#pragma once

#include "CoreHeader.h"
#include "Object.h"
NAMESPACE_OPEN(tEngine)

class GameObject;

class Layer : public Object
{
	friend class Scene;
public:
	Layer();
	~Layer();

	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);

	void AddGameObject(GameObject* gameObject);
	void RemoveGameObject(GameObject* gameObject);

private:
	void internal_Update();
	void internal_LateUpdate();
	void internal_Render(HDC hdc);

private:
	Set<GameObject*> _gameObjects;
};

NAMESPACE_CLOSE