#include "pch.h"
#include "Resource.h"

NAMESPACE_OPEN(tEngine)

Resource::Resource(const enums::eResourceType type)
	: Object(), _resourceType(type)
{
}

Resource::~Resource()
{
}


NAMESPACE_CLOSE