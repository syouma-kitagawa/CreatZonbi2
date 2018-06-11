#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H

//------------------------------------------------------------------------------------------
//include
//------------------------------------------------------------------------------------------
#include <windows.h>

class PlayerControl{
public:
	PlayerControl();
	~PlayerControl() {};
	void Update();
	void MouseCursor();
private:
	POINT m_MousePos;
};
#endif