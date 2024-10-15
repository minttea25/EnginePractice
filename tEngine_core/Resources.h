#pragma once

#include "CoreHeader.h"
#include "Enums.h"

NAMESPACE_OPEN(tEngine)

class Resource;

class Resources
{
public:
	static constexpr auto DefaultResourcePath = L"..//Resources//";

	T_ENGINE_CORE_API static void Init();
	T_ENGINE_CORE_API static Resources* get() { return s_instance; }

	template<_RESOURCE Rsc>
	static Rsc* Load(const String& file);

	T_ENGINE_CORE_API static void UnLoad(const String& file);
private:
	Resources();
	~Resources();

	T_ENGINE_CORE_API static void _init_instance();

	
	
private:
	T_ENGINE_CORE_API static Resources* s_instance;
private:
	// TEMP
	Map<String, Resource*> _cached;
};

template<_RESOURCE Rsc>
inline Rsc* Resources::Load(const String& file)
{
	auto a = s_instance;
	auto b = s_instance->_cached;
	auto it = s_instance->_cached.find(file);
	if (it == s_instance->_cached.end())
	{
		// not found -> load new
		Rsc* rsc = new Rsc(DefaultResourcePath + file);
		if (FAILED(rsc->Load()))
		{
			return nullptr;
		}
		s_instance->_cached.insert(std::make_pair(file, static_cast<Resource*>(rsc)));
		return rsc;
	}
	else
	{
		// found
		auto rsc = static_cast<Rsc*>(it->second);
		if (rsc == nullptr)
		{
			// error : type dismatching
		}
		return rsc;
	}
}



NAMESPACE_CLOSE