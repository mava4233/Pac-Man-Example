//EndState.cpp

#include "stdafx.h"
#include "EndState.h"
#include "stdafx.h"
#include "InputManager.h"
#include "Keyboard.h"
#include "DrawManager.h"
#include "SpriteManager.h"
#include "Sprite.h"
#include "StateManager.h"
#include "State.h"
#include "GameState.h"
#include "SoundManager.h"
#include "MusicClip.h"

EndState::EndState(System& system)
{
	m_systems = system;
	m_state_manager = nullptr;
	m_active = false;
	m_keyboard = false;
	m_sound_manager = m_systems.sound_manager;

	m_sound_manager->Initialize();

	m_Music = m_sound_manager->CreateMusicClip("../assets/pacman_beginning.wav");
	m_Music->Play();
}

EndState::~EndState()
{

}

bool EndState::Update(float deltatime)
{
	m_keyboard = m_systems.input_manager->GetKeyboard();
	bool space = m_keyboard->IsKeyDown(SDL_SCANCODE_SPACE);
	if (space == true)
	{
		m_sound_manager->Shutdown();
		return false;
	}
	return true;
}
void EndState::Draw()
{
	m_systems.draw_manager->Draw(m_systems.sprite_manager->CreateSprite(
		"../assets/gameover.png", 0, 0, 608, 640), 0, 0);
}
State* EndState::NextState()
{
	return nullptr;
}