#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"


NAMESPACE_OPEN(tEngine)

SceneManager::SCENE_INDEX SceneManager::s_sceneIndex = 0;
Map<SceneManager::SCENE_INDEX, Scene*> SceneManager::s_scenes = {};
Map<String, SceneManager::SCENE_INDEX> SceneManager::s_names = {};
Scene* SceneManager::s_activeScene = nullptr;

bool SceneManager::LoadScene(const String name)
{
	auto it = s_names.find(name);
	if (it == s_names.end())
	{
		// error : no such scene
		return false;
	}

	return LoadScene(it->second);
}

bool SceneManager::LoadScene(const SCENE_INDEX sceneIndex)
{
	if (s_scenes.contains(sceneIndex) == false)
	{
		// error : logic error
		return false;
	}

	if (s_activeScene) s_activeScene->OnExit();

	auto iter = s_scenes.find(sceneIndex);
#ifdef _DEBUG
	if (iter == s_scenes.end())
	{
		// error: no such scene
		return false;
	}
#endif // _DEBUG	

	s_activeScene = iter->second;
	s_activeScene->OnEnter();

	return true;
}

void SceneManager::Init()
{
}

void SceneManager::Update()
{
	if (s_activeScene)
		s_activeScene->internal_Update();
}

void SceneManager::LateUpdate()
{
	if (s_activeScene)
		s_activeScene->internal_LateUpdate();
}

void SceneManager::Render(HDC hdc)
{
	if (s_activeScene)
		s_activeScene->internal_Render(hdc);
}

SceneManager::SCENE_INDEX SceneManager::_create_scene(Scene*& scene, const String& name, bool setActiveScene)
{
	SCENE_INDEX index = s_sceneIndex++;

	scene->SetSceneName(name);
	if (setActiveScene) s_activeScene = scene;
	scene->Init();

	s_names.insert(std::make_pair(name, index));
	s_scenes.insert(std::make_pair(index, scene));

	return index;
}


NAMESPACE_CLOSE
