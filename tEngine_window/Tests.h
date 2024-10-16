#pragma once

#include "../tEngine_core/SceneManager.h"
#include "../tEngine_core/Scene.h"
#include "../tEngine_window/Player.h"
#include "../tEngine_window/BgObject.h"

using namespace tEngine;

class PlayScene : public Scene
{
public:
	PlayScene() : Scene() {}
	~PlayScene() {  }

	void Init() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc) override;

	void OnEnter() override
	{

	}
	void OnExit()  override
	{

	}

private:
};

static void LoadScenes()
{
	unsigned int index = SceneManager::CreateScene<PlayScene>(L"PlayScene", true);

	if (SceneManager::LoadScene(index) == false)
	{
		// error
		// load failed.
	}
}