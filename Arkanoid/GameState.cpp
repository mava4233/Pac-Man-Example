// GameState.cpp

#include "stdafx.h"
#include "Keyboard.h"
#include "InputManager.h"
#include "DrawManager.h"
#include "SpriteManager.h"
#include "Sprite.h"
#include "GameState.h"
#include "EndState.h"
#include <iostream>

#include "Player.h"
#include "Pellet.h"
#include "Map.h"
#include "Ghost.h"
#include "Tile.h"

#include "SoundManager.h"
#include "SoundClip.h"

#include "Collider.h"
#include "CollisionManager.h"

GameState::GameState(System& system)
{
	m_systems = system;
	m_sound_manager = m_systems.sound_manager;

	m_sound_manager->Initialize();
	m_xClip = m_sound_manager->CreateSoundClip("../assets/pacman_chomp.wav");

	// MAP
	m_xMap = new Map(system);
	m_xMap->LoadMap("r");
	
	// PAC MAN 
	Sprite* sprite = m_systems.sprite_manager->CreateSprite(
		"../assets/pacmup.png", 0, 0, 20, 20);

	Player* player = new Player(
		m_systems.input_manager->GetKeyboard(),
		sprite,
		m_systems.width,
		m_systems.height);
	m_entities.push_back(player);
	
	// GHOSTS
	Sprite* ghost = m_systems.sprite_manager->CreateSprite("../assets/red_ghost.png", 0, 0, 29, 29);
	Ghost* Rghost = new Ghost(ghost, player, 288, 288);
	m_entities.push_back(Rghost);

	m_active = false;
}

GameState::~GameState()
{
	int c = 0;
	auto it = m_entities.begin();
	while (it != m_entities.end())
	{
		Sprite* sprite = (*it)->GetSprite();
		if (sprite)
			m_systems.sprite_manager->DestroySprite(sprite);
		delete (*it);
		++it;
		c++;
	}
	m_entities.clear();
}

bool GameState::Update(float deltatime)
{

	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		if (!m_entities[i]->IsVisible())
			continue;

		//update
		m_entities[i]->Update(deltatime);
	}
	
	//Collision check after update
	CollisionChecking();
	
	if (!m_entities[0]->IsVisible())
		return false;

	return true;
}

void GameState::Draw()
{
	m_systems.draw_manager->Draw(m_systems.sprite_manager->CreateSprite(
		"../assets/background.png", 0, 0, 608, 640), 0, 0);

	m_xMap->RenderMap(nullptr,
		608, 608);
	
	for (unsigned int i = 0; i < m_entities.size(); i++)
	{
		if (!m_entities[i]->IsVisible())
			continue;

		Sprite* sprite = m_entities[i]->GetSprite();
		if (sprite)
		{
			m_systems.draw_manager->Draw(sprite,
				m_entities[i]->GetX(),
				m_entities[i]->GetY());
		}
	}
}

State* GameState::NextState()
{
	return new EndState(m_systems);
}

void GameState::CollisionChecking()
{
	std::vector<Tile*> m_tiles = m_xMap->GetTileList();
	std::vector<Pellet*> m_pellets = m_xMap->GetPelletList();

	Player* player = static_cast<Player*>(m_entities[0]);
	Ghost* ghost = static_cast<Ghost*>(m_entities[1]);

	int overlapX = 0, overlapY = 0;

	//kolla collision mellan player line 138 och alla walls i m_xMap

	for (unsigned int i = 0; i < m_tiles.size(); i++)
	{
		Tile* wall = static_cast<Tile*>(m_tiles[i]);
		if (CollisionManager::Check(player->GetCollider(), wall->GetCollider(), overlapX, overlapY))
		{
			player->StopMove();
		}
	}
	// kolla collision mellan player line 138 och alla pellets i m_xMap
	for (int i = m_pellets.size() - 1; i >= 0; --i)
	{
		Pellet* pellet = static_cast<Pellet*>(m_pellets[i]);
		if (CollisionManager::Check(player->GetCollider(), pellet->GetCollider(), overlapX, overlapY))
		{
			if (pellet->IsVisible() == true)
			{
				std::cout << "Score" << std::endl;
				m_xClip->Play();
				pellet->SetInvisible();
			}
		}
	}

	// collision mellan Ghost och walls
	for (unsigned int i = 0; i < m_tiles.size(); i++)
	{
		Tile* wall = static_cast<Tile*>(m_tiles[i]);
		if (CollisionManager::Check(ghost->GetCollider(), wall->GetCollider(), overlapX, overlapY))
		{
			ghost->SetPosition(ghost->GetX() + overlapX, ghost->GetY() + overlapY);
			ghost->ChangeDir();
		}
	}
	if (CollisionManager::Check(ghost->GetCollider(), player->GetCollider(), overlapX, overlapY))
	{
		player->SetInvisible();
	}
}