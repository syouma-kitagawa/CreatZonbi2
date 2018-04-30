#ifndef GAME_H
#define GAME_H

#include"ZombieManager.h"
#include"HumanManager.h"
#include"Player.h"

class Game
{
public:
	Game();
	~Game();
	void Draw();
	void Update();
	void RunGame();
private:
	ZombieManager* m_ZombieManager;
	HumanManager* m_HumanManager;
	Player* m_Player;
};

#endif