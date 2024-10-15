#include "pch.h"
#include "Scene.h"
#include "GameObject.h"
#include "Layer.h"

NAMESPACE_OPEN(tEngine)

Scene::Scene()
	: _layers{}, _sceneName(L"")
{
	createLayers();
}
Scene::~Scene()
{
	for (Layer*& layer : _layers)
	{
		if (layer != nullptr)
			delete layer;
	}
	_layers.clear();
}
void Scene::Init()
{
	for (Layer*& layer : _layers | std::views::filter(not_null<Layer>))
	{
		layer->Init();
	}
}
void Scene::Update()
{
}

void Scene::LateUpdate()
{
}

void Scene::Render(HDC hdc)
{
}

void Scene::AddGameObject(GameObject* gameObj, const enums::eLayerType type)
{
	_layers[(UINT)type]->AddGameObject(gameObj);
}

void Scene::createLayers()
{
	_layers.resize((UINT)enums::eLayerType::Max);
	for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
	{
		_layers[i] = new Layer();
	}
}

void Scene::internal_Update()
{
	Update();
	for (Layer*& layer : _layers | std::views::filter(not_null<Layer>))
	{
		layer->internal_Update();
	}
}

void Scene::internal_LateUpdate()
{
	LateUpdate();
	for (Layer*& layer : _layers | std::views::filter(not_null<Layer>))
	{
		layer->internal_LateUpdate();
	}
}

void Scene::internal_Render(HDC hdc)
{
	Render(hdc);
	for (Layer*& layer : _layers | std::views::filter(not_null<Layer>))
	{
		layer->internal_Render(hdc);
	}
}

void Scene::OnEnter()
{

}

void Scene::OnExit()
{

}


NAMESPACE_CLOSE