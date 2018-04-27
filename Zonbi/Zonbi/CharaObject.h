#ifndef CharaObject_H
#define CharaObject_H

#include<d3dx9.h>

class CharaObject {
public:
	CharaObject() {};
	virtual ~CharaObject() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;
protected:
	D3DXVECTOR2 m_Pos;
};

#endif