#include "pch.h"
#include "Camera.h"

NAMESPACE_OPEN(tEngine)
Camera::Camera(GameObject* gameObject)
	: Behaviour(gameObject)
{
}

Camera::~Camera()
{
}

NAMESPACE_CLOSE