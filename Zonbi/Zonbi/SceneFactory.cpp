#include"SceneFactory.h"
#include"Game.h"
#include"Title.h"
#include"GameClear.h"
#include"GameOver.h"

SceneBase* SceneFactory::Create(SceneBase::SCENE_ID sceneID)
{
	SceneBase* retScene = nullptr;

	switch (sceneID) {
	case SceneBase::SCENE_ID::TITLE:
		retScene = new Title();
		break;

	case SceneBase::SCENE_ID::MAIN:
		retScene = new Game();
		break;

	case SceneBase::SCENE_ID::GAMECLEAR:
		retScene = new GameClear();
		break;

	case SceneBase::SCENE_ID::GAMEOVER:
		retScene = new GameOver();
		break;
	}

	return retScene;
}