#include "pch.h"
#include "MonoBehaviour.h"

NAMESPACE_OPEN(tEngine)

MonoBehaviour::MonoBehaviour(GameObject* gameObject)
	: Behaviour(gameObject)
{
}

MonoBehaviour::~MonoBehaviour()
{
}

NAMESPACE_CLOSE