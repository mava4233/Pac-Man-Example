// EndState.h

#pragma once

#include "State.h"
class Keyboard;
class StateManager;
class MusicClip;

class EndState : public State
{
public:

	EndState(System& system);
	~EndState();

	bool Update(float deltatime);
	void Draw();
	State* NextState();

private:
	System m_systems;
	Keyboard* m_keyboard;
	StateManager* m_state_manager;
	SoundManager* m_sound_manager;
	MusicClip* m_Music;
	
	bool m_active;
};