#ifndef HUMAN__H
#define HUMAN__H

#include"CharaObject.h"
#include"CollisionManager.h"

#define HUMAN_W 54
#define HUMAN_H 108

class Human : public CharaObject
{
public:
	Human(D3DXVECTOR2 pos);
	virtual ~Human();
	virtual void Update();
	virtual void Draw();

	D3DXVECTOR2 Getpos() { return m_Pos; }

	bool IsDeth() { return m_IsDeath; }
private:
	Collision* m_Collision;
	D3DXVECTOR2 m_Pos;
	// 
	bool m_IsDeath;
};

#endif