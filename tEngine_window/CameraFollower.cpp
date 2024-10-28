#include "pch.h"
#include "CameraFollower.h"
#include "../tEngine_core/GameObject.h"
#include "../tEngine_core/Component.h"
#include "../tEngine_core/Transform.h"

CameraFollower::CameraFollower(GameObject* go)
	: MonoBehaviour(go)
{
}

CameraFollower::~CameraFollower()
{
}

void CameraFollower::InitObject()
{
	if (gameObject()->TryGetComponent<Camera>(_camera) == false)
	{
		// error
		return;
	}
}

void CameraFollower::Update()
{
	if (_target != nullptr && _camera != nullptr)
	{
		auto transform = _target->gameObject()->transform();
		_camera->gameObject()->transform()->set_position(transform->position());
	}
}

void CameraFollower::Render(HDC hdc)
{
	auto v = gameObject()->transform()->position();
	Rectangle(hdc, v.x, v.y, 200 + v.x, 200 + v.y);
}
