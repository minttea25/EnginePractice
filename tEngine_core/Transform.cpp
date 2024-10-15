#include "pch.h"
#include "Transform.h"


NAMESPACE_OPEN(tEngine)

Transform::Transform(GameObject* gameObject)
	: Component(gameObject), _position({})
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

NAMESPACE_CLOSE
