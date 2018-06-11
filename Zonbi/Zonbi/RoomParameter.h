#ifndef ROOMPARAMETER_H
#define ROOMPARAMETER_H

//------------------------------------------------------------------------------------------
//include
//------------------------------------------------------------------------------------------
#include<d3dx9.h>

#include"WayPointManager.h"

class RoomParameter
{
public:
	struct RoomData
	{
		int Id;
		RECT Rect;
	};
	static RoomParameter& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new RoomParameter();
		}
		return *m_pInstance;
	}
	~RoomParameter();

	RoomData* GetRoomParam(int number) { 
		return &m_pRoomPram[number]; 
	}
	int GetRoomMax() { return m_RoomMax; }

	void LoadRoom();
private:
	static RoomParameter* m_pInstance;

	RoomData* m_pRoomPram;

	int m_RoomMax;

	RoomParameter();
};

#endif