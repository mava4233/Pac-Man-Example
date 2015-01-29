// Ghost.h

#pragma once

#include "Entity.h"
class Map;
class Player;

class Ghost : public Entity
{
public:

	Ghost(Sprite* sprite, Player* player, int x, int y);
	~Ghost();

	void Update(float deltatime);
	Sprite* GetSprite();
	float GetX();
	float GetY();

	void Reset();
	void ChangeDir();

	void SetInvisible();
	bool IsVisible();
	void SetPosition(float x, float y);

	EEntityType GetType();
	Collider* GetCollider();

private:
	Player* m_player;
	Sprite* m_sprite;
	Collider* m_collider;
	Map* m_xMap;
	float m_x;
	float m_y;

	float m_velX;
	float m_velY;
	float m_vel;
	bool velR;
	bool velL;
	bool velU;
	bool velD;

	bool m_visible;
};