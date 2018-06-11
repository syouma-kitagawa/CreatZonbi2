#ifndef ROOM_H
#define ROOM_H

//----------------------------------------------------------------------------------------
//include
//----------------------------------------------------------------------------------------
#include<d3dx9.h>

#include"WayPointBase.h"

class Room : public WayPointBase
{
public:
	Room();
	Room(PlacePoint* placePoint);
	// ,int id, const RECT* rect
	virtual ~Room();
	void SetRoomId(int roomiId) { m_RoomId = roomiId; }
	void SetRect(RECT rect) { m_Rect = rect; }
	int GetRoomId() { return m_RoomId; }
	RECT GetRect() { return m_Rect; }
	PlacePoint GetPlace() { return m_PlacePoint; }
private:
	int m_RoomId;
	RECT m_Rect;
	D3DXVECTOR2 m_Pos;
};

#endif