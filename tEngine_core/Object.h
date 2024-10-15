#pragma once

#include "CoreHeader.h"

NAMESPACE_OPEN(tEngine)

class Object
{
public:
	Object();
	virtual ~Object();

	void SetName(const String& name) { _name = name; }
	String& name() { return _name; }

	int GetHashCode() const { return _instanceID; }

private:
	String _name;
	const int _instanceID;
};



NAMESPACE_CLOSE