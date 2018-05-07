#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include"SceneBase.h"

class SceneFactory {
public:
	SceneFactory() {};
	~SceneFactory() {};
	//ƒV[ƒ“‚ÌØ‚è‘Ö‚¦‚ª‚ ‚Á‚½ê‡‚±‚±‚Ås‚¤
	SceneBase* Create(SceneBase::SCENE_ID sceneID);
};
#endif