#pragma once
#include "CoreHeader.h"
#include "Behaviour.h"
#include "TextureResource.h"
#include "Sprite.h"

NAMESPACE_OPEN(tEngine)

class Animator;

class Animation : public Behaviour
{
public:
	Animation(GameObject* gameObject);
	~Animation();

	void CreateAnimation(const String& animation,
		graphics::TextureResource* spriteSheet,
		Vector2 leftTop,
		Vector2 size,
		Vector2 offset,
		unsigned int spriteLength,
		float duration);

	void Init();
	void Update();
	void LateUpdate();
	void Render(HDC hdc);

	void Reset();

	bool IsComplete() const { return _complete; }
	void set_animator(Animator* animator) { _animator = animator; }
private:
	Animator* _animator;
	Vector<Sprite*> _sprites;
	Vector<float> _intervals; // the size must be _sprites.size()-1
	bool _isPlaying;
	int _index;
	float _time;
	bool _complete;
};

NAMESPACE_CLOSE