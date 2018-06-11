#ifndef CORRIDOR_H
#define CORRIDOR_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include"WayPointBase.h"

class Corridor : public WayPointBase{
public:
	Corridor(PlacePoint* placePoint);
	virtual ~Corridor();
	PlacePoint GetPlace() { return m_PlacePoint; }
};
#endif