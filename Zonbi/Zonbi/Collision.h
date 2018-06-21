#ifndef COLLISION_H
#define COLLISION_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include<d3dx9.h>
#include<vector>

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
	std::vector<CollisionId> GetOtherCollisionId() { return m_OtherCollisionId; }
	bool IsSearchOtherCollisionId(std::vector<CollisionId> collisionId, CollisionId SearchId)
	{
		for (auto ite = collisionId.begin(); ite != collisionId.end(); ++ite) {
			if ((*ite) == SearchId) {
				return true;
			}
		}return false;
	}
	void InitializationOtherCoolisionId() 
	{ 
		m_OtherCollisionId.clear();
	}
	void SetCollisionId(CollisionId CoolisionId) { m_CollisionId = CoolisionId; }
	void SetPosition(D3DXVECTOR2* Position) { m_Position = *Position; }
	void SetSize(D3DXVECTOR2* Size) { m_Size = *Size; }
	void AddOtherCoolisionId(CollisionId OtherCoolisionId) { m_OtherCollisionId.push_back(OtherCoolisionId); }
private:
	std::vector<CollisionId> m_OtherCollisionId;
	CollisionId m_CollisionId;
	D3DXVECTOR2 m_Position;
	D3DXVECTOR2 m_Size;
	static int m_CollisionNum;
	int m_Id;
};

#endif