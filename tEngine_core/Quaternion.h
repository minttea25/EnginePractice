#pragma once
#include "CoreHeader.h"
#include "Vector3.h"
#include <limits>

#define DEG2RAD 0.0174533f // 각도에서 라디안으로 변환 상수 = PI / 180
#define RAD2DEG 57.2958f   // 라디안에서 각도로 변환 상수

NAMESPACE_OPEN(tEngine::Types)

struct Quaternion
{
public:
	static constexpr float kEpsilon = 1e-06f;
	
	static Quaternion identity() { return { 0, 0, 0, 1 }; }

	Quaternion() : x(0), y(0), z(0), w(0) {}
	Quaternion(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w)
	{
	}

	void Normalize() 
	{ 
		// TODO : Optimize without temp var.
		auto t = Normalize(*this);
		x = t.x;
		y = t.y;
		z = t.z;
		w = t.w;
	}

	float& operator[](const int index)
	{
		switch (index)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			throw std::out_of_range("Invalid Quaternion index!");
		}
	}

	float x;
	float y;
	float z;
	float w;

	// WARNING:  double definition ?
	// TODO
	static float Angle(const Quaternion& a, const Quaternion& b);

	static Quaternion Normalize(const Quaternion& q);
	

	static Quaternion FromEuler(const Vector3& eulerRotation)
	{
		const float cx = cos(eulerRotation.x * DEG2RAD * 0.5f);
		const float cy = cos(eulerRotation.y * DEG2RAD * 0.5f);
		const float cz = cos(eulerRotation.z * DEG2RAD * 0.5f);
		const float sx = sin(eulerRotation.x * DEG2RAD * 0.5f);
		const float sy = sin(eulerRotation.y * DEG2RAD * 0.5f);
		const float sz = sin(eulerRotation.z * DEG2RAD * 0.5f);

		return Quaternion{
			sx * cy * cz - cx * sy * sz,
			cx * sy * cz + sx * cy * sz,
			cx * cy * sz - sx * sy * cz,
			cx * cy * cz + sx * sy * sz
		};
	}

	static Vector3 ToEuler(const Quaternion& quaternion)
	{
		Vector3 euler;

		// Yaw (Y axis rotation)
		float sinr_cosp = 2 * (quaternion.w * quaternion.x + quaternion.y * quaternion.z);
		float cosr_cosp = 1 - 2 * (quaternion.x * quaternion.x + quaternion.y * quaternion.y);
		euler.x = atan2(sinr_cosp, cosr_cosp) * RAD2DEG;

		// Pitch (X axis rotation)
		float sinp = 2 * (quaternion.w * quaternion.y - quaternion.z * quaternion.x);
		if (fabs(sinp) >= 1)
			euler.y = copysign(90.0f, sinp); // use 90 degrees if out of range
		else
			euler.y = asin(sinp) * RAD2DEG;

		// Roll (Z axis rotation)
		float siny_cosp = 2 * (quaternion.w * quaternion.z + quaternion.x * quaternion.y);
		float cosy_cosp = 1 - 2 * (quaternion.y * quaternion.y + quaternion.z * quaternion.z);
		euler.z = atan2(siny_cosp, cosy_cosp) * RAD2DEG;

		return euler;
	}

public:
	static bool is_equal_using_dot(const float dot)
	{
		return dot > 0.999999f;
	}
};

static Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs)
{
	return Quaternion{ lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y, lhs.w * rhs.y + lhs.y * rhs.w + lhs.z * rhs.x - lhs.x * rhs.z, lhs.w * rhs.z + lhs.z * rhs.w + lhs.x * rhs.y - lhs.y * rhs.x, lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z };
}

static float Dot(const Quaternion& a, const Quaternion& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}


static bool operator==(const Quaternion& lhs, const Quaternion& rhs)
{
	return Quaternion::is_equal_using_dot(Dot(lhs, rhs));
}

static bool operator!=(const Quaternion& lhs, const Quaternion& rhs)
{
	return !Quaternion::is_equal_using_dot(Dot(lhs, rhs));
}

inline float Quaternion::Angle(const Quaternion & a, const Quaternion & b)
{
	const float num = tEngine::utils::min(abs(Dot(a, b)), 1.0f);
	return is_equal_using_dot(num) ? 0.0f : (acosf(num) * 2 * 57.29578f);
}

inline Quaternion Quaternion::Normalize(const Quaternion& q)
{
	const float num = sqrt(Dot(q, q));
	if (num < std::numeric_limits<float>::epsilon())
	{
		return identity();
	}

	return Quaternion{ q.x / num, q.y / num, q.z / num, q.w / num };
}

NAMESPACE_CLOSE

