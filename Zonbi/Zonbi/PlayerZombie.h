#ifndef PLAYERZOMBIE_H
#define PLAYERZOMBIE_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include"CharaObjectBase.h"
#include"CollisionManager.h"
#include"Debag.h"

class WayPointManager;

class PlayerZombie : public CharaObjectBase
{
public:
	PlayerZombie(D3DXVECTOR2* pos, float speed, int width, int height);
	~PlayerZombie();

	virtual void Update();
	virtual void Draw();
#ifdef DEBUG_RUN
	Collision *GetCollision()
	{
		return m_pCollision;
	}

	Collision *GetTmpCollision(int idx)
	{
		return m_pTmpCollision[idx];
	}
#endif
private:
	bool DirectionCheck(Direction direction);
	void ResetArray();

	const float kMargin = 10.0f;
	const float m_Tu = 0.02625f;
	const float m_Tv = 0.0527f;
	const float m_AtkTv = 0.0556f;

	Collision* m_pTmpCollision[4];
	D3DXVECTOR2 m_CollisionPos[4];
	Collision* m_pUpDownCollision[2];
	D3DXVECTOR2 m_Difference;
	Collision* m_pCollision;
	Direction m_Direction;
	D3DXVECTOR2 m_BeforePos;
	D3DXVECTOR2 m_Pos;
	float m_Speed;
	int m_Width;
	int m_Height;
	Direction m_CollisionDir[4];
	D3DXVECTOR2 m_Distance;
	//ÇÃÇøÇ…ñºëOïœçX
	D3DXVECTOR2 m_NextPos;
	int collisionDircnt = 0;
	int m_Fcnt = 0;
	int m_RoomId = 0;
	int m_ClickRoomId = 0;
	int m_RoutePointNum;
	bool m_IsClick = false;
	bool m_SameRoom = false;
	bool m_IsAttack = false;
};
#endif
