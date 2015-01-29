//Tile.h
#pragma once

#include "Map.h"
#include "Sprite.h"
#include "Collider.h"

class collider;
enum TILE_TYPE
{
	TILE_TYPE_NONE = 0,

	TILE_TYPE_WALL,
	TILE_TYPE_PELLETS
};

class Tile
{
public:
	Tile(Sprite* sprite, int x, int y);
	~Tile();

	Sprite* GetSprite();
	Collider* GetCollider(){ return m_collider; };

	int TileID;
	int TypeID;

private:
	Sprite* m_sprite;
	Tile* m_xTile;
	Collider* m_collider;
};