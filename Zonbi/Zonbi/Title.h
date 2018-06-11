#ifndef TITLE_H
#define TITLE_H

//------------------------------------------------------------------------------------------
//include
//------------------------------------------------------------------------------------------
#include <vector>

#include"SceneBase.h"
class ObjectBase;

class Title : public SceneBase{
public:
	Title();
	virtual ~Title();
	virtual void Draw();
	virtual SCENE_ID Update();
private:
	bool m_IsMusic = false;
	std::vector<ObjectBase*> m_pObjectBase;
};

#endif