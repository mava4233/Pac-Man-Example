// Pellet.cpp

#include "stdafx.h"
#include "Sprite.h"
#include "Collider.h"
#include "Pellet.h"

Pellet::Pellet(Sprite* sprite, float x, float y)
{
	m_sprite = sprite;

	m_collider = new Collider(x, y);
	m_collider->SetParent(this);
	m_collider->SetWidthHeight(m_sprite->GetRegion()->w,
		m_sprite->GetRegion()->h);

	m_x = x;
	m_y = y;

	m_visible = true;
}

Pellet::~Pellet()
{
	if (m_collider)
		delete m_collider;
}

void Pellet::Update(float deltatime)
{
	
}

Sprite* Pellet::GetSprite()
{
	return m_sprite;
}

float Pellet::GetX()
{
	return m_x;
}

float Pellet::GetY()
{
	return m_y;
}

void Pellet::Reset()
{
	m_visible = true;
}

void Pellet::SetInvisible()
{
	m_visible = false;
}

bool Pellet::IsVisible()
{
	return m_visible;
}

EEntityType Pellet::GetType()
{
	return ENTITY_PELLET;
}

Collider* Pellet::GetCollider()
{
	return m_collider;
}


