#include "pch.h"
#include "Component.h"
#include "GameObject.h"
#include "Transform.h"

NAMESPACE_OPEN(tEngine)

Component::Component(GameObject* gameObject)
	:_gameObject(gameObject)
{

}
Component::~Component()
{
	_gameObject = nullptr;
}

void Component::Init()
{

}

void Component::Update()
{

}

void Component::LateUpdate()
{

}

void Component::Render(HDC hdc)
{

}

Transform* Component::transform()
{
	return _gameObject->transform();
}

NAMESPACE_CLOSE
