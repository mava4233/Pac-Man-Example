// GameState.h

#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include "State.h"

class Entity;
class Map;
class SoundClip;
class SoundManager; 

class GameState : public State
{
public:
	GameState(System& system);
	~GameState();

	bool Update(float deltatime);
	void Draw();
	State* NextState();
	
private:
	void CollisionChecking();

private:
	Map* m_xMap;
	SoundManager* m_sound_manager;
	SoundClip* m_xClip;
	System m_systems;
	std::vector<Entity*> m_entities;

	bool m_active;
};

#endif // GAMESTATE_H_INCLUDED
