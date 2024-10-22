#pragma once

#include "CoreHeader.h"
#include "Vector3.h"

NAMESPACE_OPEN(tEngine::Types)

struct Bounds
{
public:
	Vector3 center() const { return _center; }
	void set_center(const Vector3& value) { _center = value; }

	Vector3 extent() const { return _extent; }
	void set_extent(const Vector3& value) { _extent = value; }

	Vector3 size() const { return _extent * 2; }
	void set_size(const Vector3& value) { _extent = value * 0.5f; }

	Vector3 min() const { return _center - _extent; }
	void set_min(const Vector3& value) { _set_min_max(max(), value); }
	Vector3 max() const { return _center + _extent; }
	void set_max(const Vector3& value) { _set_min_max(value, min()); }

	void Expand(const float amount)
	{
		float a = amount * 0.5f;
		_extent = _extent + Vector3(a, a, a);
	}

	void Expand(const Vector3& amount)
	{
		_extent = amount * 0.5f;
	}

	void Encapsulate(const Vector3& point)
	{
		_set_min_max(std::min(min(), point), std::max(max(), point));
	}

	void Encapsulate(const Bounds& bounds)
	{
		Encapsulate(bounds._center - bounds._extent);
		Encapsulate(bounds._center + bounds._extent);
	}

private:
	void _set_min_max(const Vector3& mx, const Vector3& mn)
	{
		_extent = (mx - mn) * 0.5f;
		_center = mn + _extent;
	}
private:
	Vector3 _center;
	Vector3 _extent;
};

NAMESPACE_CLOSE