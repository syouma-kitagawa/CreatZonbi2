#include "Room.h"

Room::Room()
{
}

Room::Room(PlacePoint* placePoint)
{
	m_PlacePoint.Id = placePoint->Id;
	m_PlacePoint.Pos = placePoint->Pos;
	m_PlacePoint.Place = placePoint->Place;
}


Room::~Room()
{
}
