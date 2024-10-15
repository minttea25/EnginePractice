#include "pch.h"
#include "Object.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Layer.h"
#include "GameObject.h"
#include "Transform.h"

NAMESPACE_OPEN(tEngine)
Object::Object()
	: _name(L""), _instanceID(/*TODO*/0)
{
}

Object::~Object()
{
}

void Object::_instantiate(GameObject*& go, enums::eLayerType type, const Types::Vector3& position)
{
	auto layer = SceneManager::active_scene()->GetLayer(type);
	layer->AddGameObject(go);
	go->transform()->SetPosition(position);
}

NAMESPACE_CLOSE