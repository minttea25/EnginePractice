#include "pch.h"
#include "Behaviour.h"

NAMESPACE_OPEN(tEngine)

Behaviour::Behaviour(GameObject* gameObject)
	: Component(gameObject)
{
}

Behaviour::~Behaviour()
{
}

NAMESPACE_CLOSE