#ifndef CHARAOBJECTBASE_H
#define CHARAOBJECTBASE_H
//---------------------------------------------------------------------------------------
// include
//---------------------------------------------------------------------------------------
#include<d3dx9.h>


class CharaObjectBase {
public:
	enum Direction {
		UP,
		RIGHT,
		DOWN,
		LEFT,
		NON
	};
	CharaObjectBase() {};
	virtual ~CharaObjectBase() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;
protected:
	D3DXVECTOR2 m_Pos;
	D3DXVECTOR2 m_BeforePos;
};

#endif