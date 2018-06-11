#ifndef STAGEOBJECT_H
#define STAGEOBJECT_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include<d3dx9.h>

#include"StageObjectBase.h"
#include"CollisionManager.h"

class StageObject : public StageObjectBase{
public:
	StageObject(RECT rect);
	virtual~StageObject();
private:
	RECT m_Rect;
	Collision* m_Collision;
};

#endif 