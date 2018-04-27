#ifndef GAME_H
#define GAME_H

#include"ZonbiManager.h"
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
	ZonbiManager* m_ZonbiManager;
	HumanManager* m_HumanManager;
	Player* m_Player;
};

#endif