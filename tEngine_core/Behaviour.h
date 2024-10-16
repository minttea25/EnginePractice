#pragma once
#include "CoreHeader.h"
#include "Component.h"

NAMESPACE_OPEN(tEngine)

class Behaviour abstract : public Component
{
public:
	T_ENGINE_CORE_API Behaviour(GameObject* gameObject);
	T_ENGINE_CORE_API virtual ~Behaviour();
};

NAMESPACE_CLOSE
