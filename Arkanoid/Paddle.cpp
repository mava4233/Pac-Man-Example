// Paddle.cpp

#include "stdafx.h"
#include "Paddle.h"
#include "Mouse.h"
#include "Sprite.h"

Paddle::Paddle(Mouse* mouse, Sprite* sprite, int width, int height)
{
	m_mouse = mouse;
	m_sprite = sprite;
	m_x = 0.0f;
	m_y = 0.0f;
	m_width = width;
	m_height = height;

	Reset();
}

void Paddle::Update(float deltatime)
{
	float x = m_mouse->GetX();
	if (x < 0.0f)
		x = 0.0f;
	if (x > m_width - 80)
		x = m_width - 80;
	m_x = x;
}

Sprite* Paddle::GetSprite()
{
	return m_sprite;
}

float Paddle::GetX()
{
	return m_x;
}

float Paddle::GetY()
{
	return m_y;
}

void Paddle::Reset()
{
	m_x = m_width / 2 - 40;
	m_y = m_height - 60 - 8;

}