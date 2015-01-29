// Player.h

#ifndef Player_H_INCLUDED
#define Player_H_INCLUDED

#include "Entity.h"

class Keyboard;

class Player : public Entity
{
public:
	Player(Keyboard* keyboard, Sprite* sprite, int width, int height);
	
	void Update(float deltatime);
	void StopMove();
	Sprite* GetSprite();
	float GetX();
	float GetY();

	void Reset();

	bool IsVisible();
	void SetInvisible();
	EEntityType GetType();
	Collider* GetCollider();

private:
	Keyboard* m_keyboard;
	Sprite* m_sprite;
	Collider* m_collider;

	float m_x;
	float m_y;
	float m_velX;
	float m_velY;
	float m_vel;
	bool velR;
	bool velL;
	bool velU;
	bool velD;

	int m_width;
	int m_height;	
	int m_screen_width;
	int m_screen_height;

	bool m_visible;
};

#endif // Player_H_INCLUDED
