#include "pch.h"
#include "Layer.h"
#include "GameObject.h"

NAMESPACE_OPEN(tEngine)
Layer::Layer()
	: _gameObjects{}
{

}
Layer::~Layer()
{

}

void Layer::Init()
{
	for (GameObject* gameObj : _gameObjects)
	{
		if (gameObj != nullptr)
			gameObj->Init();
	}
}

void Layer::Update()
{
	
}
void Layer::LateUpdate()
{
	
}
void Layer::Render(HDC hdc)
{
	
}

void Layer::AddGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr) return;

	auto result = _gameObjects.insert(gameObject).second;
	if (result == false)
	{
		// warning: already exists.
	}
}

void Layer::RemoveGameObject(GameObject* gameObject)
{
	if (gameObject == nullptr) return;

	DISCARD _gameObjects.erase(gameObject);
}

void Layer::internal_Update()
{
	Update();
	for (GameObject* go : _gameObjects | std::views::filter(not_null<GameObject>))
	{
		go->internal_Update();
	}
}

void Layer::internal_LateUpdate()
{
	LateUpdate();
	for (GameObject* go : _gameObjects | std::views::filter(not_null<GameObject>))
	{
		go->internal_LateUpdate();
	}
}

void Layer::internal_Render(HDC hdc)
{
	Render(hdc);
	for (GameObject* go : _gameObjects | std::views::filter(not_null<GameObject>))
	{
		go->internal_Render(hdc);
	}
}

NAMESPACE_CLOSE