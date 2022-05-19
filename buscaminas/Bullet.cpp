#include "Bullet.h"
#include "Window.h"

void Bullet::Init(int _x, int _y)
{
	x = _x;
	y = _y;
	img.Load("bullet.png");
}

void Bullet::Draw()
{
	Window* window = Window::GetPtr();

	window->RenderTexture(&img, x, y);
}