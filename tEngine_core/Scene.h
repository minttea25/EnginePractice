#pragma once

#include "CoreHeader.h"
#include "Enums.h"
#include "Object.h"

NAMESPACE_OPEN(tEngine)

class GameObject;
class Layer;

class Scene : public Object
{
	friend class SceneManager;
public:
	T_ENGINE_CORE_API Scene();
	T_ENGINE_CORE_API virtual ~Scene();

	T_ENGINE_CORE_API virtual void Init();
	T_ENGINE_CORE_API virtual void Update();
	T_ENGINE_CORE_API virtual void LateUpdate();
	T_ENGINE_CORE_API virtual void Render(HDC hdc);

	T_ENGINE_CORE_API virtual void OnEnter();
	T_ENGINE_CORE_API virtual void OnExit();

	void SetSceneName(String name) { _sceneName = name; }
	const String& scene_name() { return _sceneName; }

	T_ENGINE_CORE_API void AddGameObject(GameObject* gameObj, const enums::eLayerType type);
	Layer* GetLayer(const enums::eLayerType type) { return _layers[(unsigned int)type]; }

private:
	void createLayers();

	void internal_Update();
	void internal_LateUpdate();
	void internal_Render(HDC hdc);

private:
	Vector<Layer*> _layers;
	String _sceneName;
};

NAMESPACE_CLOSE