#include "pch.h"
#include "Transform.h"


NAMESPACE_OPEN(tEngine)

Transform::Transform(GameObject* gameObject)
	: Component(gameObject), _position({}),
	_rotation({}), _scale({1, 1, 1})
{
}
Transform::~Transform()
{
}
void Transform::Init()
{
	// leave empty
}
void Transform::Update()
{
}
void Transform::LateUpdate()
{
}
void Transform::Render(HDC hdc)
{
}

float Transform::RotationZ() const
{
	return fmod(rotation().z, 360.0f);
}

NAMESPACE_CLOSE
