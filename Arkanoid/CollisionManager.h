// CollisionManager.h

#pragma once

class Collider;

class CollisionManager
{
public:
	
	static bool Check(Collider* lhs, Collider* rhs, int& overlapX, int& overlapY);
};