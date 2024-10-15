#include "pch.h"
#include "Resources.h"
#include "Resource.h"

NAMESPACE_OPEN(tEngine)

Resources* Resources::s_instance = nullptr;

void Resources::Init()
{
	_init_instance();
}

Resources::Resources()
	: _cached{}
{
}

Resources::~Resources()
{
}

void Resources::_init_instance()
{
	s_instance = new Resources();
}

void Resources::UnLoad(const String& file)
{
	auto it = s_instance->_cached.find(file);
	if (it != s_instance->_cached.end())
	{
		delete it->second;
		DISCARD s_instance->_cached.erase(file);
	}
	
}

NAMESPACE_CLOSE