#pragma once
#include "../tEngine_core/GameObject.h"

using namespace tEngine;

class BgObject : public GameObject
{
public:
	BgObject();
	~BgObject();

	void Init() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;
};

