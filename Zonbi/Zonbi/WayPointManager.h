#ifndef WAYPOINTMANAGER_H
#define WAYPOINTMANAGER_H

//�V���O���g���N���X

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include<d3dx9.h>
#include<vector>

#include"WayPointBase.h"
//-----------------------------------------------------------------------------------------
//�N���X
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
	//���W���ǂ�WayPoint�ɓ����Ă��邩
	//���������[�g�T�[�`�����������W
	int CurrentWayPoint(D3DXVECTOR2* pos);
	//���W�������̂ǂ����ɓ����Ă��邩
	//�����Ă���Ε���ID�@�����Ă��Ȃ����-1
	//�����������ɓ����Ă��邩�����������W
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