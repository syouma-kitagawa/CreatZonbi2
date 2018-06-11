#ifndef TIMELIMIT_H
#define TIMELIMIT_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include<d3dx9.h>
#include<functional>

#include"SceneBase.h"
#include"DirectGraphics.h"
#include"ObjectBase.h"

class TimeLimit : public ObjectBase{
public:
	TimeLimit(std::function<void(SceneBase::SCENE_ID)>,int limits);
	virtual ~TimeLimit();
	virtual void Update();
	virtual void Draw();
	int GetLimits() { return m_Limits; }
private:
	void NextCharPos(CUSTOMVERTEX vertex[]);

	std::function<void(SceneBase::SCENE_ID)> m_Function;
	const D3DXVECTOR2 m_Pos;
	unsigned int m_FrCnt = 0;
	int m_Limits = 0;
};
#endif