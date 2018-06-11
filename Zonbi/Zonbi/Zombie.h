#ifndef ZOMBIE__H
#define ZOMBIE__H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include"CharaObjectBase.h"
#include"CollisionManager.h"

class Zombie : public CharaObjectBase
{
public:
	Zombie(D3DXVECTOR2* pos,float speed, int width, int height);
	virtual ~Zombie();

	virtual void Update();
	virtual void Draw();
private:
	bool DirectionCheack(Direction direction);
	void ResetArray();
	const float kMargin = 10.0f;
	const float m_Tu = 0.0536f;
	const float m_Tv = 0.0536f;

	Collision* m_pTmpCollision[4];
	D3DXVECTOR2 m_CollisionPos[4];
	D3DXVECTOR2 m_Difference;

	Collision* m_pCollision;
	Direction m_Direction;
	Direction m_CollisionDir[4];
	D3DXVECTOR2 m_Pos;
	D3DXVECTOR2 m_BeforePos;
	float m_Speed;
	int m_Width;
	int m_Height;
	D3DXVECTOR2 m_Distance;
	//ÇÃÇøÇ…ñºëOïœçX
	D3DXVECTOR2 m_NextPos;
	int m_Fcnt = 0;
};

#endif