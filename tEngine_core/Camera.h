#pragma once
#include "CoreHeader.h"
#include "Behaviour.h"

NAMESPACE_OPEN(tEngine)

class Camera final : public Behaviour
{
public:
	Camera(GameObject* gameObject);
	~Camera();
};

NAMESPACE_CLOSE

