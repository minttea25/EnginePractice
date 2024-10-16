#pragma once
#include "CoreHeader.h"
#include "Behaviour.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Color.h"

NAMESPACE_OPEN(tEngine)

using namespace tEngine::Types;

class Camera final : public Behaviour
{
public:
	T_ENGINE_CORE_API Camera(GameObject* gameObject);
	T_ENGINE_CORE_API ~Camera();

	T_ENGINE_CORE_API void Init() override;
	T_ENGINE_CORE_API void Update() override;
	T_ENGINE_CORE_API void LateUpdate() override;
	T_ENGINE_CORE_API void Render(HDC hdc) override;

	T_ENGINE_CORE_API void set_resolution(const Vector3& resolution)
	{
		_resolution.x = resolution.x;
		_resolution.y = resolution.y;
	}

	T_ENGINE_CORE_API void set_lookPosition(const Vector3& position)
	{
		_lookPosition.x = position.x;
		_lookPosition.y = position.y;
	}

private:
	// TODO : all fields are not implemented for its functions of camera.
	Color _backgroundColor;
	Vector3 _distance;
	Vector3 _resolution;
	Vector3 _lookPosition;
};

NAMESPACE_CLOSE

