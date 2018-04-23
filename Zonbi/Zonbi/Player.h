#ifndef PLAYER_H
#define PLAYER_H

#include <windows.h>

class Player {
public:
	Player() {};
	~Player() {};
private:
	POINT m_MousePos;
};
#endif