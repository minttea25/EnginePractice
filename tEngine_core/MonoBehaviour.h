#pragma once
#include "CoreHeader.h"
#include "Behaviour.h"

NAMESPACE_OPEN(tEngine)
class MonoBehaviour abstract : public Behaviour
{
public:
	T_ENGINE_CORE_API MonoBehaviour(GameObject* gameObject);
	T_ENGINE_CORE_API virtual ~MonoBehaviour();
};

NAMESPACE_CLOSE
