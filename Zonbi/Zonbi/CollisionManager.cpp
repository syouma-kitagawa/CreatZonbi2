#include "CollisionManager.h"


CollisionManager* CollisionManager::m_CollisionManager = NULL;

void CollisionManager::CreateCollisionManager()
{
	if (m_CollisionManager == NULL) {
		m_CollisionManager = new CollisionManager;
	}
}

//矩形のあたり判定
void CollisionManager::Update()
{
	for (int i = 0; i < m_pCollision.size(); i++) {
		m_pCollision[i]->InitializationOtherCoolisionId();
		m_pCollision[i]->InitializationOtherCoolision();
	}
	D3DXVECTOR2 Pos;
	D3DXVECTOR2 Size;
	D3DXVECTOR2 Pos2;
	D3DXVECTOR2 Size2;
	for (int i = 0; i < m_pCollision.size(); i++) {
		for (int j = i + 1; j < m_pCollision.size(); j++) {
			if (m_pCollision[i]->GetCollisionId() != m_pCollision[j]->GetCollisionId())
			{
				Pos = *m_pCollision[i]->GetPosition();
				Size = *m_pCollision[i]->GetSize();
				Pos2 = *m_pCollision[j]->GetPosition();
				Size2 = *m_pCollision[j]->GetSize();
				if (Pos.x - Size.x / 2 < Pos2.x + Size2.x / 2 &&
					Pos.x + Size.x / 2 > Pos2.x - Size2.x / 2) {
					if (Pos.y - Size.y / 2 < Pos2.y + Size2.y / 2 &&
						Pos.y + Size.y / 2 > Pos2.y - Size2.y / 2) {
						m_pCollision[i]->AddOtherCoolisionId(m_pCollision[j]->GetCollisionId());
						m_pCollision[j]->AddOtherCoolisionId(m_pCollision[i]->GetCollisionId());
						m_pCollision[i]->AddOtherCoolision(m_pCollision[j]);
						m_pCollision[j]->AddOtherCoolision(m_pCollision[i]);
						if (m_pCollision[i]->GetOtherCollisionId().back() == Collision::NON) {
							m_pCollision[i]->GetOtherCollisionId().pop_back();
						}
						if (m_pCollision[j]->GetOtherCollisionId().back() == Collision::NON) {
							m_pCollision[j]->GetOtherCollisionId().pop_back();
						}
					}
				}
			}
		}
	}

}