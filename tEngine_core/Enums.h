#pragma once
#include "CoreHeader.h"

NAMESPACE_OPEN(tEngine::enums)

enum class eLayerType
{
	None,
	BackGround,
	//Tree 
	//character
	Player,
	Max = 16,
};

enum class eResourceType
{
	None,
	Texture,
	Audio,
	Prefab,
	Shader,
	Material,

};

NAMESPACE_CLOSE