#pragma once

#include "CoreHeader.h"
#include "Component.h"
#include "Quaternion.h"
#include "Vector2.h"
#include "Vector3.h"

NAMESPACE_OPEN(tEngine)

using namespace tEngine::Types;

class Transform : public Component
{
public:
	explicit Transform(GameObject* gameObject);
	~Transform();

	void Init() override;
	void Update() override;
	void LateUpdate()  override;
	void Render(HDC hdc)  override;

	void set_position(const Vector2& pos) { _position.x = pos.x; _position.y = pos.y; }
	void set_position(const Vector3& pos) { _position.x = pos.x; _position.y = pos.y; _position.z = pos.z; }
	Vector3 position() const { return _position; }
	void set_scale(const Vector3& scale) { _scale = scale; }
	Vector3 scale() const { return _scale; }
	void set_rotation(const Vector3& rotation) { _rotation = Quaternion::FromEuler(rotation); }
	Vector3 rotation() const { return Quaternion::ToEuler(_rotation); }

	// TEMP
	T_ENGINE_CORE_API float RotationZ() const;


private:
	Vector3 _position;
	Vector3 _scale;
	Quaternion _rotation;
};

NAMESPACE_CLOSE
