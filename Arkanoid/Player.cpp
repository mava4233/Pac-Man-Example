// Player.cpp

#include "stdafx.h"
#include "Keyboard.h"
#include "Sprite.h"
#include "Player.h"
#include "Collider.h"
#include <iostream>
#include "Map.h"
#include "Tile.h"

Player::Player(Keyboard* keyboard, Sprite* sprite, int width, int height)
{
	m_keyboard = keyboard;
	m_sprite = sprite;
	m_x = 0.0f;
	m_y = 0.0f;
	m_width = width;
	m_height = height;
	
	m_collider = new Collider(width, height);
	m_collider->SetParent(this);
	m_collider->SetWidthHeight(m_sprite->GetRegion()->w,
		m_sprite->GetRegion()->h);

	m_visible = true;
	
	Reset();
}

void Player::Update(float deltatime)
{	
	// Speed
	m_vel = 1.5f;

	bool xp = m_keyboard->IsKeyDown(SDL_SCANCODE_RIGHT);  // Going Right
	bool xn = m_keyboard->IsKeyDown(SDL_SCANCODE_LEFT);  // Going Left
	bool yn = m_keyboard->IsKeyDown(SDL_SCANCODE_UP);  // Going Up
	bool yp = m_keyboard->IsKeyDown(SDL_SCANCODE_DOWN);  // Going Down

	if (xp == true)
	{
		velR = true;
		velL = false;
		velU = false;
		velD = false;

		m_velY = 0.0f;
		m_velX = m_vel;
	}

	if (xn == true)
	{
		velL = true;
		velR = false;
		velU = false;
		velD = false;

		m_velY = 0.0f;
		m_velX = -m_vel;
	}

	if (yp == true)
	{
		velD = true;
		velL = false;
		velR = false;
		velU = false;

		m_velX = 0.0f;
		m_velY = m_vel;
	}

	if (yn == true)
	{
		velU = true;
		velL = false;
		velD = false;
		velR = false;

		m_velX = 0.0f;
		m_velY = -m_vel;
	}

	m_x += m_velX;
	m_y += m_velY;

	// For disappearing from and reappearing on the screen. 
	if (m_x > 608)
		m_x = 0;
	if (m_x < (0 - 32))
		m_x = (608 - 32);


	m_collider->Refresh();
}

Sprite* Player::GetSprite()
{
	return m_sprite;
}

float Player::GetX()
{
	return m_x;
}

float Player::GetY()
{
	return m_y;
}

void Player::Reset()
{
	m_x = 288;
	m_y = 480;
}

EEntityType Player::GetType()
{
	return ENTITY_PLAYER;
}

Collider* Player::GetCollider()
{
	return m_collider;
}

bool Player::IsVisible()
{
	return m_visible;
}

void Player::SetInvisible()
{
	m_visible = false;
}

void Player::StopMove()
{
	m_x -= m_velX;
	m_y -= m_velY;
}
