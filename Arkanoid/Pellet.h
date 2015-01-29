// Pellet.h

#pragma once

#include "Entity.h"

class Pellet : public Entity
{
public:
	Pellet(Sprite* sprite, float x, float y);
	~Pellet();

	void Update(float deltatime);
	Sprite* GetSprite();
	float GetX();
	float GetY();

	void Reset();

	void SetInvisible();
	bool IsVisible();
	
	int PelletID;
	int TypeID;

	EEntityType GetType();
	Collider* GetCollider();

private:
	Sprite* m_sprite;
	Collider* m_collider;
	float m_x;
	float m_y;
	bool m_visible;

	std::vector<Pellet*> PelletList;
};