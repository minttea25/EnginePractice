#include "pch.h"
#include "GameObjectFactory.h"
#include "../tEngine_core/Transform.h"

using namespace tEngine;

GameObjectPool::GameObjectPool(const int poolCount)
	: InitialPoolSize(poolCount)
{
	_init_pool();
}

GameObjectPool::~GameObjectPool()
{
	if (_pool.size() != InitialPoolSize)
	{
		// crash
		return;
	}

	for (int i = 0; i < _pool.size(); ++i)
	{
		delete _pool[i];
	}
	_pool.clear();
}

GameObject* GameObjectPool::acquire()
{
	if (_pool.empty())
	{
		// Note : according to policy
		return nullptr;
	}
	else
	{
		auto go = _pool.back();
		_pool.pop_back();
		go->AddComponent<Transform>();
		return go;
	}
}

void GameObjectPool::release(GameObject* go)
{
	go->~GameObject();
	_pool.push_back(go);
}

void GameObjectPool::_init_pool()
{
	_pool.resize(InitialPoolSize);
	for (int i = 0; i < InitialPoolSize; ++i)
	{
		_pool[i] = new GameObject();
	}
}



