#ifndef COLLISION_H
#define COLLISION_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include<d3dx9.h>
#include<vector>

#include"CharaObjectBase.h"

class Collision
{
public:
	enum CollisionId {
		NON = -1,
		HUMAN,
		ZOMBIE,
		ZOMBIEHIT,
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
	//å¸Ç´ÇÇ‡ÇÁÇ§ä÷êî
	CharaObjectBase::Direction GetDirection() { return m_Direction; }
	//à íuÇÇ‡ÇÁÇ§ä÷êî
	D3DXVECTOR2* GetPosition() { return &m_Position; }
	D3DXVECTOR2* GetSize() { return &m_Size; }
	CollisionId GetCollisionId() { return m_CollisionId; }
	std::vector<CollisionId> GetOtherCollisionId() { return m_OtherCollisionId; }
	std::vector<Collision*> GetOtherCollision() {return m_OtherCollision;}
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
	void InitializationOtherCoolision()
	{
		m_OtherCollision.clear();
	}
	void SetCollisionId(CollisionId CoolisionId) { m_CollisionId = CoolisionId; }
	void SetPosition(D3DXVECTOR2* Position) { m_Position = *Position; }
	void SetSize(D3DXVECTOR2* Size) { m_Size = *Size; }
	void SetDirection(CharaObjectBase::Direction direction) { m_Direction = direction; }
	void AddOtherCoolisionId(CollisionId OtherCoolisionId) { m_OtherCollisionId.push_back(OtherCoolisionId); }
	void AddOtherCoolision(Collision* collision) { m_OtherCollision.push_back(collision); }
private:
	std::vector<CollisionId> m_OtherCollisionId;
	std::vector<Collision*> m_OtherCollision;
	CollisionId m_CollisionId;
	D3DXVECTOR2 m_Position;
	D3DXVECTOR2 m_Size;
	CharaObjectBase::Direction m_Direction;
	static int m_CollisionNum;
	int m_Id;
};

#endif