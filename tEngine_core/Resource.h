#pragma once

#include "CoreHeader.h"
#include "Enums.h"

NAMESPACE_OPEN(tEngine)

class Resource abstract : public Object
{
public:
	explicit Resource(const enums::eResourceType type);
	virtual ~Resource();

	virtual HRESULT Load() = 0;

	void set_path(const String& path) { _path = path; }

	const String& path() const { return _path; }
	const enums::eResourceType Type() const { return _resourceType; }

private:
	const enums::eResourceType _resourceType;
	String _path;
};



NAMESPACE_CLOSE

