#ifndef WAYPOINTMANAGER_H
#define WAYPOINTMANAGER_H

//シングルトンクラス

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include<d3dx9.h>
#include<vector>

#include"WayPointBase.h"
//-----------------------------------------------------------------------------------------
//クラス
//-----------------------------------------------------------------------------------------
class Room;
class Corridor;

class WayPointManager
{
public:
	static WayPointManager* GetpInstance()
	{
		static WayPointManager* m_pInstance;
		if (m_pInstance == nullptr) {
			m_pInstance = new WayPointManager();
		}
		return m_pInstance;
	}
	~WayPointManager();
	//座標がどのWayPointに入っているか
	//第一引数ルートサーチをしたい座標
	int CurrentWayPoint(D3DXVECTOR2* pos);
	//座標が部屋のどこかに入っているか
	//入っていれば部屋ID　入っていなければ-1
	//第一引数部屋に入っているかを見たい座標
	int CurrentRoom(D3DXVECTOR2* pos);
	/*void RouteSearch(int id, int destinationId);*/
	void SearchRoot(std::vector<std::vector<WayPointBase*>> &root, int rootId, WayPointBase* goalId, bool *isEnd);
	//WayPointBase* Recursion(std::vector<WayPointBase*>& firstPoint, std::vector<WayPointBase*>& tmp);
	//void RouteFill(WayPointBase* tmp);
	std::vector<WayPointBase*> GetRoutes() { return m_Route; }
	WayPointBase* GetWayPoint(int num) { return m_WayPoints[num]; }
private:
	WayPointManager();
	std::vector<WayPointBase*> m_WayPoints;
	std::vector<Room*> m_Room;
	std::vector<Corridor*> m_Corridor;
	std::vector<WayPointBase*> m_Route;
};

#endif