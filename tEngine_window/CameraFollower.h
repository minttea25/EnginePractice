#pragma once
#include "../tEngine_core/MonoBehaviour.h"
#include "../tEngine_core/GameObject.h"
#include "../tEngine_core/Camera.h"

using namespace tEngine;

class CameraFollower : public MonoBehaviour
{
public:
	CameraFollower(GameObject* go);
	~CameraFollower();

	void InitObject();
	void set_Target(GameObject*& target)
	{
		_target = target;
	}

	void Update() override;
	void Render(HDC hdc) override;

private:
	Camera* _camera;
	GameObject* _target;
};

