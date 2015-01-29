//IntroState.h


#pragma once

#include "State.h"
class Keyboard;
class StateManager;
class MusicClip;

class IntroState : public State
{
public:

	IntroState(System& system);
	~IntroState();

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