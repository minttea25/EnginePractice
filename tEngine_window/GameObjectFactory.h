#pragma once

#include "../tEngine_core/GameObject.h"

using namespace tEngine;

class GameObjectPool
{
public:
	static constexpr int DEFAUALT_POOL_COUNT = 10;

	GameObjectPool(const int poolCount = DEFAUALT_POOL_COUNT);
	~GameObjectPool();

	GameObject* acquire();
	void release(GameObject* go);

	size_t current_pool_size() const { return _pool.size(); }

	const int InitialPoolSize;
private:
	void _init_pool();

private:
	std::vector<GameObject*> _pool;
};

class GameObjectFactory
{
};

