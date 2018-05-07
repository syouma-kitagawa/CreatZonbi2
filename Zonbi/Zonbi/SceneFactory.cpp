#include"SceneFactory.h"
#include"Game.h"

SceneBase* SceneFactory::Create(SceneBase::SCENE_ID sceneID)
{
	SceneBase* retScene = nullptr;

	switch (sceneID) {
	case SceneBase::SCENE_ID::TITLE:
	//	retScene = new TitleScene;
		break;

	case SceneBase::SCENE_ID::MAIN:
		retScene = new Game;
		break;

	case SceneBase::SCENE_ID::GAMECLEAR:
	//	retScene = new GameClearScene;
		break;

	case SceneBase::SCENE_ID::GAMEOVER:
		//retScene = new GameOverScene;
		break;
	}

	return retScene;
}