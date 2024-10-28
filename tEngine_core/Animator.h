#pragma once
#include "CoreHeader.h"
#include "Behaviour.h"
#include "TextureResource.h"
#include <map>

NAMESPACE_OPEN(tEngine)

class Animation;
class GameObject;

class Animator final : public Behaviour
{
public:
	T_ENGINE_CORE_API Animator(GameObject* gameObject);
	T_ENGINE_CORE_API ~Animator();

	T_ENGINE_CORE_API void Init();
	void Update();
	void LateUpdate();
	void Render(HDC hdc);

	T_ENGINE_CORE_API bool CreateAnimation(const String& animation, Vector<Sprite*> spriteSheet, Vector<float> intervals, bool loop = true);

	T_ENGINE_CORE_API Animation* FindAnimation(const String& key);
	T_ENGINE_CORE_API void PlayAnimation(const String& key, bool loop = true);

	
	
private:
	// TEMP
	Map<String, Animation*> _animations;
	Animation* _currentAnimation;

	bool _loop;
	bool _enabled;
};

NAMESPACE_CLOSE