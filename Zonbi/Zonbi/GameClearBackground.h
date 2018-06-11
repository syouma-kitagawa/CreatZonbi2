#ifndef GAMECLEARBACKGROUND_H
#define GAMECLEARBACKGROUND_H

//------------------------------------------------------------------------------------------
//include
//------------------------------------------------------------------------------------------
#include"ObjectBase.h"

class GameClearBackground : public ObjectBase
{
public:
	GameClearBackground();
	virtual ~GameClearBackground();
	virtual void Update() {};
	virtual void Draw();
};

#endif