#include "pch.h"
#include "Player.h"
#include "../tEngine_core/Vector2.h"
#include "../tEngine_core/tInput.h"
#include "../tEngine_core/tTime.h"
#include "../tEngine_core/Transform.h"
#include "../tEngine_core/GameObject.h"

Player::Player(GameObject* go)
	: MonoBehaviour(go), _speed(100)
{
}

Player::~Player()
{
}

void Player::Init()
{
}

void Player::Update()
{
}

void Player::LateUpdate()
{
	using namespace tEngine;
	using namespace tEngine::Types;

	Transform* transform = nullptr;
	if (gameObject()->TryGetComponent(transform) == false)
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

	transform->set_position(pos);
}

void Player::Render(HDC hdc)
{
}
