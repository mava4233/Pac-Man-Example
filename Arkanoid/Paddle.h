// Paddle.h

#pragma once

#include "Entity.h"

class Mouse;

class Paddle : public Entity
{
public:
	Paddle(Mouse* mouse, Sprite* sprite, int width, int height);

	void Update(float deltatime);
	Sprite* GetSprite();
	float GetX();
	float GetY();
	void Reset();

private:

	Mouse* m_mouse;
	Sprite* m_sprite;
	float m_x;
	float m_y;
	int m_width;
	int m_height;
};