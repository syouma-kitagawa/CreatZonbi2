#include "CollisionManager.h"


CollisionManager* CollisionManager::m_CollisionManager = NULL;

void CollisionManager::CreateCollisionManager()
{
	if (m_CollisionManager == NULL) {
		m_CollisionManager = new CollisionManager;
	}
}

//‹éŒ`‚Ì‚ ‚½‚è”»’è
void CollisionManager::Update()
{
	D3DXVECTOR2 Pos;
	D3DXVECTOR2 Size;
	D3DXVECTOR2 Pos2;
	D3DXVECTOR2 Size2;
	for (int i = 0; i < m_pCollision.size(); i++) {
		for (int j = i + 1; j < m_pCollision.size(); j++) {
			if (m_pCollision[i]->GetCollisionId() != m_pCollision[j]->GetCollisionId())
			{
				Pos = m_pCollision[i]->GetPosition();
				Size = m_pCollision[i]->GetSize();
				Pos2 = m_pCollision[j]->GetPosition();
				Size2 = m_pCollision[j]->GetSize();
				if (Pos.x - Size.x / 2 < Pos2.x + Size2.x / 2 &&
					Pos.x + Size.x / 2 > Pos2.x - Size2.x / 2) {
					if (Pos.y - Size.y / 2 < Pos2.y + Size2.y / 2 &&
						Pos.y + Size.y / 2 > Pos2.y - Size2.y / 2) {
						m_pCollision[i]->SetOtherCoolisionId(m_pCollision[j]->GetCollisionId());
						m_pCollision[j]->SetOtherCoolisionId(m_pCollision[i]->GetCollisionId());
					}
				}
			}
		}
	}
}