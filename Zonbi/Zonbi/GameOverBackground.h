#ifndef GAMEOVERBACKGROUND_H
#define GAMEOVERBACKGROUND_H

//------------------------------------------------------------------------------------------
//include
//------------------------------------------------------------------------------------------
#include"ObjectBase.h"

class GameOverBackground : public ObjectBase
{
public:
	GameOverBackground();
	virtual ~GameOverBackground();
	virtual void Update() {};
	virtual void Draw();
};

#endif