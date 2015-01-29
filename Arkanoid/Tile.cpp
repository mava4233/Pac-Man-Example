//Tile.cpp

#include "stdafx.h"
#include "Tile.h"

Tile::Tile(Sprite* sprite, int x, int y)
{
	m_sprite = sprite;
	m_collider = new Collider(x, y);
	m_collider->SetWidthHeight(m_sprite->GetRegion()->w,
		m_sprite->GetRegion()->h);

	TileID = 0;
	TypeID = TILE_TYPE_NONE;
}

Sprite* Tile::GetSprite()
{
	return m_sprite;
}

