// Map.h

#pragma once

#include "State.h"
#include "Collider.h"

class Tile;
class Pellet;

class Map
{
public:

	Map(System& system);
	~Map();

	Collider* GetWallCol();
	Collider* GetPelletCol();
	std::vector<Tile*> GetTileList(){ return TileList; };
	std::vector<Pellet*> GetPelletList() { return PelletList; };

private:
	std::vector<Tile*> TileList;
	std::vector<Pellet*> PelletList;

public:
	bool LoadMap(char* File);
	void RenderMap(SDL_Surface* Surf_Display, int MapX, int MapY);

private:
	int m_map_width;
	int m_map_height;
	int m_tile_size;
	System m_systems;
	Collider* m_collider;
};
