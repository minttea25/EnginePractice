#pragma once

#include "CoreHeader.h"
#include "Component.h"
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

	void SetPosition(const Vector2& pos) { _position.x = pos.x; _position.y = pos.y; }
	void SetPosition(const Vector3& pos) { _position.x = pos.x; _position.y = pos.y; _position.z = pos.z; }
	Vector3 position() const { return _position; }

private:
	Vector3 _position;
};

NAMESPACE_CLOSE
