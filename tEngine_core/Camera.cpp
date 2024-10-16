#include "pch.h"
#include "Camera.h"
#include "GameObject.h"
#include "Component.h"
#include "Transform.h"

NAMESPACE_OPEN(tEngine)
Camera::Camera(GameObject* gameObject)
	: Behaviour(gameObject),
	_backgroundColor(Color::gray()),
	_resolution(),
	_distance(),
	_lookPosition()

{
}

Camera::~Camera()
{
}

void Camera::Init()
{
}

void Camera::Update()
{
	_lookPosition = gameObject()->transform()->position();
	_distance = _lookPosition - (_resolution / 2.0f);
}

void Camera::LateUpdate()
{
}

void Camera::Render(HDC hdc)
{
}

NAMESPACE_CLOSE