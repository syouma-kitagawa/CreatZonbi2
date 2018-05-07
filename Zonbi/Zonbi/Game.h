#ifndef GAME_H
#define GAME_H

#include"ZombieManager.h"
#include"HumanManager.h"
#include"Player.h"
#include"SceneBase.h"

class Game : public SceneBase{
public:
	Game();
	~Game();
	void Draw();
	SCENE_ID Update();
private:
	ZombieManager* m_ZombieManager;
	HumanManager* m_HumanManager;
	Player* m_Player;
};

#endif