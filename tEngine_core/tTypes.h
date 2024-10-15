#pragma once

#include <string>
#include <map>
#include <functional>
#include <vector>
#include <concepts>
#include <set>


namespace tEngine
{
	// TODO
	// warning C4251
	// STL container needs to have dll-interface to be used by clients of class ~

	using String = std::wstring;

	template<typename _Kty, typename _Ty>
	using Map = std::map<_Kty, _Ty>;

	template<typename _Ty>
	using Vector = std::vector<_Ty>;

	template<typename _Ty>
	using Set = std::set<_Ty>;

	template<typename T>
	using Delegate = std::function<void(T)>;

	template<typename T0, typename T1>
	using Delegate2 = std::function<void(T0, T1)>;

	class Object;
	class Transform;
	class GameObject;
	class Component;
	class Scene;
	

	template<class T>
	concept _GAMEOBJECT = requires(T go)
	{
		requires std::derived_from<T, Object>;
		{ go.transform() } -> std::same_as<Transform*>;
	};

	template<class T>
	concept _COMPONENT = requires(T component, GameObject* go)
	{
		requires std::derived_from<T, Component>;

		component.Init();
		T(go);
		{ component.gameObject() } -> std::same_as<GameObject*>;
	};

	template<class T>
	concept _SCENE = requires()
	{
		requires std::derived_from<T, Scene>;
	};

	template<typename T>
	auto not_null = [](T* t) { return t != nullptr; };
}
