#ifndef COLLISION_H
#define COLLISION_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include<d3dx9.h>

class Collision
{
public:
	enum CollisionId {
		NON = -1,
		HUMAN,
		ZOMBIE,
		OBJECT,
		BOX
	};

	Collision()
	{
		m_Id = m_CollisionNum;
		m_CollisionNum++;
	};
	~Collision() {};
	int GetId() { return m_Id; }
	D3DXVECTOR2* GetPosition() { return &m_Position; }
	D3DXVECTOR2* GetSize() { return &m_Size; }
	CollisionId GetCollisionId() { return m_CollisionId; }
	CollisionId GetOtherCollisionId() { return m_OtherCollisionId; }


	void InitializationOtherCoolisionI() { m_OtherCollisionId = NON; }
	void SetCollisionId(CollisionId CoolisionId) { m_CollisionId = CoolisionId; }
	void SetPosition(D3DXVECTOR2* Position) { m_Position = *Position; }
	void SetSize(D3DXVECTOR2* Size) { m_Size = *Size; }
	void SetOtherCoolisionId(CollisionId OtherCoolisionId) { m_OtherCollisionId = OtherCoolisionId; }
private:
	CollisionId m_OtherCollisionId;
	CollisionId m_CollisionId;
	D3DXVECTOR2 m_Position;
	D3DXVECTOR2 m_Size;
	static int m_CollisionNum;
	int m_Id;
};

#endif