#pragma once

#include "CoreHeader.h"

NAMESPACE_OPEN(tEngine)
class Application
{
public:
	Application();
	~Application();
	void Init(HWND hwnd, unsigned int width, unsigned int height);
	void Run();
	void Update();
	void FixedUpdate();
	void LateUpdate();
	void Render();

	void ShowFps();

private:
	void clearRenterTarget();
	void copyRenderTarget(HDC sourceHdc, HDC dest);

private:
	HWND _hwnd;
	HDC _hdc;

	// For double-buffering
	HDC _backHdc;
	HBITMAP _backBuffer;

	unsigned int _width;
	unsigned int _height;
};

NAMESPACE_CLOSE
