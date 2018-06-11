#ifndef GAME_H
#define GAME_H

//------------------------------------------------------------------------------------------
//include
//------------------------------------------------------------------------------------------
#include<vector>

#include"SceneBase.h"

class ObjectBase;
class ZombieManager;
class HumanManager;
class PlayerControl;
class StageManager;
class GameBackground;
class TimeLimit;

class Game : public SceneBase{
public:
	Game();
	~Game();
	void Draw();
	SCENE_ID Update();
private:
	bool m_IsMusic = false;
	void SetRetSceneId(SceneBase::SCENE_ID sceneId) { retId = sceneId; }
	std::vector<ObjectBase*> m_ObjectBase;
	ZombieManager* m_ZombieManager;
	HumanManager* m_HumanManager;
	PlayerControl* m_PlayerControl;
	StageManager* m_StageObjectManager;
	GameBackground* m_GameBackground;
	TimeLimit* m_TimeLimit;
	SceneBase::SCENE_ID retId = SceneBase::SCENE_ID::MAIN;
};

#endif