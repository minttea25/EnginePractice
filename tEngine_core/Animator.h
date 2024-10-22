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
	Animator(GameObject* gameObject);
	~Animator();

	void Init();
	void Update();
	void LateUpdate();
	void Render(HDC hdc);

	

	Animation* FindAnimation(const String& key);
	void PlayAnimation(const String& key, bool loop = true);

	
	
private:
	// TEMP
	Map<String, Animation*> _animations;
	Animation* _currentAnimation;

	bool _loop;
	bool _enabled;
};

NAMESPACE_CLOSE