#include "Corridor.h"

Corridor::Corridor(PlacePoint* placePoint)
{
	m_PlacePoint.Id = placePoint->Id;
	m_PlacePoint.Pos = placePoint->Pos;
	m_PlacePoint.Place = placePoint->Place;
}


Corridor::~Corridor()
{
}
