#ifndef PLAYER_H
#define PLAYER_H

#include <windows.h>

class Player{
public:
	Player();
	~Player() {};
	void Update();
	void MouseCursor();
private:
	POINT m_MousePos;
};
#endif