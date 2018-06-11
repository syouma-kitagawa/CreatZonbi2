#ifndef GAMECLEAR_H
#define GAMECLEAR_H

//-------------------------------------------------------------------------------------------------------------------
//include
//-------------------------------------------------------------------------------------------------------------------
#include<vector>

#include"SceneBase.h"

class ObjectBase;

class GameClear : public SceneBase
{
public:
	GameClear();
	virtual ~GameClear();
	virtual void Draw();
	virtual SCENE_ID Update();
private:
	std::vector<ObjectBase*> m_pObjectBase;
};

#endif