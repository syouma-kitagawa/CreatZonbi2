#include"StageObject.h"

StageObject::StageObject(RECT rect)
{
	m_Rect = rect;
	D3DXVECTOR2 Pos;
	Pos.x = m_Rect.left + (m_Rect.right - m_Rect.left) / 2;
	Pos.y = m_Rect.top + (m_Rect.bottom - m_Rect.top) / 2;
	m_Collision = new Collision();
	m_Collision->SetPosition(&Pos);
	m_Collision->SetSize(&D3DXVECTOR2(m_Rect.right - m_Rect.left, m_Rect.bottom - m_Rect.top));
	m_Collision->SetCollisionId(Collision::OBJECT);
	CollisionManager::GetcollisionManager()->AddCollision(m_Collision);
}

StageObject::~StageObject()
{
	delete m_Collision;
}
