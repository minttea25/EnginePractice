#pragma once
#include "CoreHeader.h"
#include "Component.h"

NAMESPACE_OPEN(tEngine)

class GameObject;

class Renderer : public Component
{
public:
	Renderer(GameObject* gameObject);
	virtual ~Renderer();
};

NAMESPACE_CLOSE
