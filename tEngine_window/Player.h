#pragma once

#include "../tEngine_core/GameObject.h"

using namespace tEngine;

class Player : public GameObject
{
public:
	Player();
	~Player();

	void Init() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

private:
	float _speed;
};

