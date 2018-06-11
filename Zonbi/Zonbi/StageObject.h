#ifndef STAGEOBJECT_H
#define STAGEOBJECT_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include<d3dx9.h>

#include"StageObjectBase.h"
#include"CollisionManager.h"
#include"Debag.h"

class StageObject : public StageObjectBase{
public:
	StageObject(RECT rect);
	virtual~StageObject();

#ifdef DEBUG_RUN
	Collision *GetCollision()
	{
		return m_Collision;
	}
#endif
private:
	RECT m_Rect;
	Collision* m_Collision;
};

#endif 