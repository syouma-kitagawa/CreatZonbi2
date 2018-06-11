#ifndef WAYPOINTBASE_H
#define WAYPOINTBASE_H
//---------------------------------------------------------------------------------------------
//include
//---------------------------------------------------------------------------------------------
#include<d3dx9.h>
#include<vector>

class WayPointBase {
public:
	enum PLACE {
		CORRIDOR,
		ROOMSIDEDOOR
	};
	enum ROUTE {
		NON,
		FIRST,
		END
	};
	struct PlacePoint {
		ROUTE Route;
		int Id;
		PLACE Place;
		D3DXVECTOR2 Pos;
		RECT Rect;
	};

	WayPointBase() {};
	virtual ~WayPointBase() {};
	virtual PlacePoint GetPlace() = 0;
	virtual std::vector<WayPointBase*>& GetNearPoints(){ return m_NearPoint; }
	virtual ROUTE GetRoute() { return m_PlacePoint.Route; }
	virtual WayPointBase* GetOneBeforePoint() { return m_OneBeforePoint; }
	virtual void SetRoute(ROUTE route) { m_PlacePoint.Route = route; }
	virtual void ChangePlacePoint(D3DXVECTOR2 pos) {
		m_PlacePoint.Rect.left = m_PlacePoint.Rect.left - pos.x;
		m_PlacePoint.Rect.top = m_PlacePoint.Rect.top - pos.y;
		m_PlacePoint.Rect.right = m_PlacePoint.Rect.right + pos.x;
		m_PlacePoint.Rect.bottom = m_PlacePoint.Rect.bottom + pos.y;
	}
	virtual void SetOneBeforePoint(WayPointBase* beforePoint) { m_OneBeforePoint = beforePoint; }
	virtual void AddNearPoint(WayPointBase* placePoint) { m_NearPoint.push_back(placePoint); }
protected:
	PlacePoint m_PlacePoint;
	WayPointBase* m_OneBeforePoint;
	std::vector<WayPointBase*> m_NearPoint;
};

#endif