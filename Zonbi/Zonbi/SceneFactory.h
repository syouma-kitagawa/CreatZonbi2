#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include"SceneBase.h"

class SceneFactory {
public:
	SceneFactory() {};
	~SceneFactory() {};
	//シーンの切り替えがあった場合ここで行う
	SceneBase* Create(SceneBase::SCENE_ID sceneID);
};
#endif