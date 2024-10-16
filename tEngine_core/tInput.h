#pragma once

#include "CoreHeader.h"

NAMESPACE_OPEN(tEngine)

enum class KeyState : char
{
	Down = 0,
	Pressed,
	Up,
	None,
};

enum class KeyCode : uint16_t
{
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,
	Left, Right, Down, Up,
	End,
};

class Input
{
public:
	struct Key
	{
		KeyCode keyCode;
		KeyState state;
		bool pressed;
	};

	T_ENGINE_CORE_API static void Init();
	T_ENGINE_CORE_API static void Update();

	T_ENGINE_CORE_API static bool GetKeyDown(KeyCode key) { return s_keys[(uint32_t)key].state == KeyState::Down; }
	T_ENGINE_CORE_API static bool GetKeyUp(KeyCode key) { return s_keys[(uint32_t)key].state == KeyState::Up; }
	T_ENGINE_CORE_API static bool GetKey(KeyCode key) { return s_keys[(uint32_t)key].state == KeyState::Pressed; }

private:
	static bool isKeyDown(KeyCode key);
	static void updateKeys();
	static void updateKey(Key& key);
	static void updateKeyDown(Key& key);
	static void updateKeyUp(Key& key);

private:
	static Vector<Key> s_keys;
};

NAMESPACE_CLOSE
