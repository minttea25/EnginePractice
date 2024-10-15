#pragma once

#include "CoreHeader.h"
#include "Enums.h"

NAMESPACE_OPEN(tEngine);

class Scene;

class SceneManager
{
	using SCENE_INDEX = unsigned int;
public:
	template <_SCENE Scene_>
	static SCENE_INDEX CreateScene(const String name, bool setActiveScene = false);
	
	T_ENGINE_CORE_API static bool LoadScene(const String name);
	T_ENGINE_CORE_API static bool LoadScene(const SCENE_INDEX sceneIndex);
	T_ENGINE_CORE_API static Scene* active_scene() { return s_activeScene; }

	T_ENGINE_CORE_API static void Init();
	T_ENGINE_CORE_API static void Update();
	T_ENGINE_CORE_API static void LateUpdate();
	T_ENGINE_CORE_API static void Render(HDC hdc);

private:
	T_ENGINE_CORE_API static SceneManager::SCENE_INDEX _create_scene(Scene*& scene, const String& name, bool setActiveScene);
private:
	static SCENE_INDEX s_sceneIndex;
	static Map<String, SCENE_INDEX> s_names;
	static Map<SCENE_INDEX, Scene*> s_scenes;
	static Scene* s_activeScene;
};


template<_SCENE Scene_>
inline SceneManager::SCENE_INDEX SceneManager::CreateScene(const String name, bool setActiveScene)
{
	Scene_* scene = new Scene_();
	auto s = static_cast<Scene*>(scene);
	auto index = _create_scene(s, name, setActiveScene);

	return index;
}

NAMESPACE_CLOSE