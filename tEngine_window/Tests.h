#pragma once

#include "../tEngine_core/SceneManager.h"
#include "../tEngine_core/Scene.h"
#include "../tEngine_window/Player.h"

using namespace tEngine;

class PlayScene : public Scene
{
public:
	PlayScene() : Scene(), _player(nullptr) {}
	~PlayScene() { if (_player != nullptr) delete _player; }

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
	Player* _player;
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