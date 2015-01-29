//Map.cpp

#include "stdafx.h"
#include "Map.h"
#include "Tile.h"
#include "Pellet.h"
#include "DrawManager.h"
#include "SpriteManager.h"
#include "Sprite.h"
#include <iostream>

Map::Map(System& system)
{
	m_systems = system;  
	m_map_height = 19;
	m_map_width = 19;
	m_tile_size = 32;
	
}

Map::~Map()
{
}

bool Map::LoadMap(char* File)
{	
	TileList.clear();       //Rensar gamla tiles f�rst
	PelletList.clear();

	//=======WALLS=========
	FILE* FileHandle;
	fopen_s(&FileHandle, "../assets/pacmap_old.txt", "r"); //�ppnar textfilen med map 

	if (FileHandle == nullptr)
	{
		return false;
	}
	
	for (int Y = 0; Y < m_map_height; Y++) // For-loopar f�r att h�mta varje tile
	{
		for (int X = 0; X < m_map_width; X++)
		{

			Tile* tempTile = new Tile(m_systems.sprite_manager->CreateSprite(
				"../assets/wall.png", 0, 0, 32, 32), 0, 0);


			
			fscanf_s(FileHandle, "%d:%d ", &tempTile->TileID, &tempTile->TypeID); // H�r skapas en tempor�r tile som f�r info fr�n filen...
			
			TileList.push_back(tempTile);	//..som sen pushas in i TileList och "sparar" infon

		}
		fscanf_s(FileHandle, "\n");
	}
	fclose(FileHandle);

	//=======PELLETS=========
	FILE* FileHandleP;
	fopen_s(&FileHandleP, "../assets/pacmap_old.txt", "r");

	for (int Y = 0; Y < m_map_height; Y++) // For-loopar f�r att h�mta varje tile
	{
		for (int X = 0; X < m_map_width; X++)
		{

			Pellet* tempPellet = new Pellet(m_systems.sprite_manager->CreateSprite(
				"../assets/pelletC.png", 0, 0, 32, 32), 0, 0);


			fscanf_s(FileHandleP, "%d:%d ", &tempPellet->PelletID, &tempPellet->TypeID); // H�r skapas en tempor�r tile som f�r info fr�n filen...

			PelletList.push_back(tempPellet);	//..som sen pushas in i TileList och "sparar" infon

		}
		fscanf_s(FileHandleP, "\n");
	}

	fclose(FileHandleP);
	return true;
}


//Funktion f�r att rendera map
void Map::RenderMap(SDL_Surface* Surf_Display, int MapX, int MapY) //MapX och MapY visar var p� sk�rmen den ska renderas.
{

	int ID = 0;

	for (int Y = 0; Y < m_map_height; Y++)  //OBS! Samma loop som innan men g�ller inte pixlar utan antal tiles!
	{
		for (int X = 0; X < m_map_width; X++)
		{
			if (TileList[ID]->TypeID == TILE_TYPE::TILE_TYPE_NONE)	//F�rst kollar vi om en tile ska ritas.
			{				
			}

			// Drawing Walls
			else if (TileList[ID]->TypeID == TILE_TYPE::TILE_TYPE_WALL)
			{
				int tX = (X * m_tile_size);  //H�r konverteras X och Y koordinaterna tillbaka till pixelkoordinater
				int tY = (Y * m_tile_size);	//genom att multiplicera med storleken p� en tile.
				TileList[ID]->GetCollider()->SetPosition(tX, tY);
				Sprite* sprite = TileList[ID]->GetSprite();
				if (sprite)
				{
					m_systems.draw_manager->Draw(sprite, tX, tY);
				}
			}

			//Pellets 
			else if (PelletList[ID]->TypeID == TILE_TYPE::TILE_TYPE_PELLETS)
			{
				int tX = (X * m_tile_size);  //H�r konverteras X och Y koordinaterna tillbaka till pixelkoordinater
				int tY = (Y * m_tile_size);	//genom att multiplicera med storleken p� en tile.
				PelletList[ID]->GetCollider()->SetPosition(tX, tY);
				Sprite* sprite = PelletList[ID]->GetSprite();
				if (sprite)
				{
					if (PelletList[ID]->IsVisible())
	
					m_systems.draw_manager->Draw(sprite, tX, tY);
				}	
			}		
			ID++;
		}
	}
}



