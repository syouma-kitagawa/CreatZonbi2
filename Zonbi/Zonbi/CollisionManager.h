#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <vector>

#include"Collision.h"

class CollisionManager
{
public:
	~CollisionManager() {};
	void CreateCollisionManager();
	void AddCollision(Collision* pCollision) { m_pCollision.push_back(pCollision); }

	void RemoveCollision(Collision* pCollision)
	{
		for (int i = 0; i < m_pCollision.size(); i++) {
			if (pCollision->GetId() == m_pCollision[i]->GetId()) {
				m_pCollision.erase(m_pCollision.begin() + i);
				break;
			}
		}
	}
	void Update();
	static CollisionManager* GetcollisionManager() { return m_CollisionManager; };
private:
	CollisionManager() {};
	static CollisionManager* m_CollisionManager;
	std::vector<Collision*> m_pCollision;
};

#endif