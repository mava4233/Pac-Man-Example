//Ghost.cpp

#include "stdafx.h"
#include "Ghost.h"
#include "Sprite.h"
#include "Collider.h"
#include "Map.h"
#include "Tile.h"
#include "Player.h"

Ghost::Ghost(Sprite* sprite, Player* player, int x, int y)
{
	m_sprite = sprite;

	m_collider = new Collider(x, y);
	m_collider->SetParent(this);
	m_collider->SetWidthHeight(m_sprite->GetRegion()->w,
		m_sprite->GetRegion()->h);

	m_x = x;
	m_y = y;

	m_player = player;

	m_visible = true;
}
Ghost::~Ghost()
{
	if (m_collider)
		delete m_collider;
}

void Ghost::Update(float deltatime)
{	
	
	/*if (m_x <= m_player->GetX())
	{
		m_x++;
	}
	if (m_x >= m_player->GetX())
	{
		m_x--;
	}
		
	if (m_y <= m_player->GetY())
	{
		m_y++;
	}
		
	if (m_y >= m_player->GetY())
	{
		m_y--;
	}*/
		
	// For disappearing from and reappearing on the screen. 
	if (m_x > 608)
		m_x = 0;
	if (m_x < (0 - 32))
		m_x = (608 - 32);
	
	m_collider->Refresh();
}

Sprite* Ghost::GetSprite()
{
	return m_sprite;
}

float Ghost::GetX()
{
	return m_x;
}

float Ghost::GetY()
{
	return m_y;
}

void Ghost::Reset()
{
	m_visible = true;
}

void Ghost::SetInvisible()
{
	m_visible = false;
}

bool Ghost::IsVisible()
{
	return m_visible;
}

EEntityType Ghost::GetType()
{
	return ENTITY_GHOST;
}

Collider* Ghost::GetCollider()
{
	return m_collider;
}

void Ghost::ChangeDir()
{
	
}

void Ghost::SetPosition(float x, float y)
{
	m_x = x;
	m_y = y;
	m_collider->Refresh();
}