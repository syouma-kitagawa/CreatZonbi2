#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include"SceneBase.h"

class SceneFactory {
public:
	SceneFactory() {};
	~SceneFactory() {};
	//�V�[���̐؂�ւ����������ꍇ�����ōs��
	SceneBase* Create(SceneBase::SCENE_ID sceneID);
};
#endif