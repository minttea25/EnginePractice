#include "pch.h"
#include "Player.h"
#include "../tEngine_core/Vector2.h"
#include "../tEngine_core/tInput.h"
#include "../tEngine_core/tTime.h"
#include "../tEngine_core/Transform.h"

Player::Player()
	: GameObject(), _speed(100)
{
}

Player::~Player()
{
}

void Player::Init()
{
	GameObject::Init();
}

void Player::Update()
{
}

void Player::LateUpdate()
{
	using namespace tEngine;
	using namespace tEngine::Types;

	Transform* transform = nullptr;
	if (TryGetComponent(transform) == false)
	{
		// error
		return;
	}

	Vector3 pos = transform->position();
	auto dist = _speed * Time::deltaTime();

	if (Input::GetKey(KeyCode::W))
	{
		pos.y -= dist;
	}
	if (Input::GetKey(KeyCode::S))
	{
		pos.y += dist;
	}
	if (Input::GetKey(KeyCode::A))
	{
		pos.x -= dist;
	}
	if (Input::GetKey(KeyCode::D))
	{
		pos.x += dist;
	}

	transform->SetPosition(pos);
}

void Player::Render(HDC hdc)
{
	auto v = transform()->position();
	Rectangle(hdc, v.x, v.y, 100.0f + v.x, 100.0f + v.y);
}
