#include "pch.h"
#include "GameObject.h"
#include "Transform.h"

NAMESPACE_OPEN(tEngine)

GameObject::GameObject()
	:_transform(nullptr)
{
	_init_transform();
}

GameObject::~GameObject()
{
	for (auto& kv : _components)
	{
		delete kv.second;
		kv.second = nullptr;
	}
	_transform = nullptr;
	_components.clear();
}

void GameObject::Init()
{
	for (auto& kv : _components)
	{
		kv.second->Init();
	}
}

void GameObject::Update()
{
}

void GameObject::LateUpdate()
{
}

void GameObject::Render(HDC hdc)
{
}

void GameObject::internal_Update()
{
	Update();
	for (auto& kv : _components)
	{
		kv.second->Update();
	}
}

void GameObject::internal_LateUpdate()
{
	LateUpdate();
	for (auto& kv : _components)
	{
		kv.second->LateUpdate();
	}
}

void GameObject::internal_Render(HDC hdc)
{
	Render(hdc);
	for (auto& kv : _components)
	{
		kv.second->Render(hdc);
	}
}


void GameObject::_init_transform()
{
	_transform = new Transform(this);
	_transform->Init();
	//AddComponent<Transform>();
	//_transform = GetComponent<Transform>();
}

NAMESPACE_CLOSE

