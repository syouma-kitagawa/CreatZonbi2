#ifndef GAMEOVER_H
#define GAMEOVER_H

//-------------------------------------------------------------------------------------------------------------------
//include
//-------------------------------------------------------------------------------------------------------------------
#include<vector>

#include"SceneBase.h"

class ObjectBase;

class GameOver : public SceneBase
{
public:
	GameOver();
	virtual ~GameOver();
	virtual void Draw();
	virtual SCENE_ID Update();
private:
	std::vector<ObjectBase*> m_pObjectBase;
};
#endif