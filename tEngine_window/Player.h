#pragma once

#include "../tEngine_core/MonoBehaviour.h"

using namespace tEngine;

class Player : public MonoBehaviour
{
public:
	Player(GameObject* go);
	~Player();

	void Init() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

private:
	float _speed;
};

