#ifndef ZOMBIE__H
#define ZOMBIE__H

#include"CharaObject.h"
#include"CollisionManager.h"

//ゾンビのサイズ
#define ZOMBIE_W 54
#define ZOMBIE_H 108

class Zombie : public CharaObject
{
public:
	Zombie(D3DXVECTOR2 pos,float speed);
	virtual ~Zombie();

	virtual void Update();
	virtual void Draw();
private:
	bool m_MoveZombie;

	Collision* m_Collision;
	D3DXVECTOR2 m_Pos;
	float m_Speed;
	D3DXVECTOR2 m_Distance;
	//のちに名前変更
	D3DXVECTOR2 m_NextPos;
};

#endif