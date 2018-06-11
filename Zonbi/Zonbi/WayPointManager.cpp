#include"WayPointManager.h"
#include"Room.h"
#include"Corridor.h"
#include"RoomParameter.h"
#include "WayPointBase.h"

WayPointManager::WayPointManager()
{
	FILE *fp = NULL;
	fopen_s(&fp, "Property/ZombiRootData.csv", "r");
	//仮置き場を作る
	static int roomCnt = 0;
	WayPointBase::PlacePoint tmpPlacePoint;
	//一行のデータを引っ張ってきて、Placeを見てRoomかCorridorを分けてそれをWayPointに入れる
	while(fscanf_s(fp, "%d,%d,%d,%d,%d,%d,%d,%d",
			&tmpPlacePoint.Id, &tmpPlacePoint.Place,
			&tmpPlacePoint.Pos.x, &tmpPlacePoint.Pos.y,
			&tmpPlacePoint.Rect.left,&tmpPlacePoint.Rect.top,
			&tmpPlacePoint.Rect.right,&tmpPlacePoint.Rect.bottom) != EOF) {
		if (tmpPlacePoint.Place == WayPointBase::ROOMSIDEDOOR) {
			Room* tmpRoom = new Room(&tmpPlacePoint);
			m_WayPoints.push_back(tmpRoom);
			m_Room.push_back(tmpRoom);
			m_WayPoints.back()->ChangePlacePoint(tmpRoom->GetPlace().Pos);
			m_Room[roomCnt]->SetRoomId(RoomParameter::GetInstance().GetRoomParam(roomCnt)->Id);
			m_Room[roomCnt]->SetRect(RoomParameter::GetInstance().GetRoomParam(roomCnt)->Rect);
			roomCnt++;
		}
		else {
			Corridor* tmpCorridor = new Corridor(&tmpPlacePoint);
			m_WayPoints.push_back(tmpCorridor);
			m_WayPoints.back()->ChangePlacePoint(tmpCorridor->GetPlace().Pos);
			m_Corridor.push_back(tmpCorridor);
		}
	}
	fclose(fp);
	FILE *fp2 = NULL;
	fopen_s(&fp, "Property/ZombiRootLink.csv", "r");
	int tmpId;
	int tmpList[4];
	WayPointBase *point = NULL;
	//tmpIdはリンク元になる座標ポイント番号,tmpListはリンク先になる座標ポイント番号
	while (fscanf_s(fp, "%d,%d,%d,%d,%d,", &tmpId, &tmpList[0], &tmpList[1], &tmpList[2], &tmpList[3]) != EOF) {
		//IDは連番として入ってる前提とする
		point = m_WayPoints[tmpId - 1];
		//-1は無効なIdとする
		for (int i = 0; i < 4; i++) {
			if (tmpList[i] == -1) {
				break;
			}
			point->AddNearPoint(m_WayPoints[tmpList[i] - 1]);
		}
	}
	fclose(fp);
}


WayPointManager::~WayPointManager()
{
	for (int i = 0; i < m_WayPoints.size(); i++) {
		delete m_WayPoints[i];
	}
	//配列のサイズを0にする
	m_WayPoints.clear();
}

int WayPointManager::CurrentWayPoint(D3DXVECTOR2* pos)
{
	for (int i = 0; i < m_WayPoints.size(); i++) {
		if (m_WayPoints[i]->GetPlace().Rect.left <= pos->x && pos->x <= m_WayPoints[i]->GetPlace().Rect.right
			&& m_WayPoints[i]->GetPlace().Rect.top <= pos->y && pos->y <= m_WayPoints[i]->GetPlace().Rect.bottom) {
			return i;
		}
	}
}

int WayPointManager::CurrentRoom(D3DXVECTOR2* pos) 
{
	for (int i = 0; i < m_Room.size(); i++) {
		if (m_Room[i]->GetRect().left <= pos->x &&pos->x <= m_Room[i]->GetRect().top
			&& m_Room[i]->GetRect().top <= pos->y && pos->y <= m_Room[i]->GetRect().bottom) {
			return m_Room[i]->GetRoomId();
		}
	}
	return -1;
}
void WayPointManager::RouteSearch(int id, int destinationId)
{
	bool isEnd = false;
	std::vector<std::vector<WayPointBase*>> routes;
	std::vector<WayPointBase*> route;

	for (int i = 0; i < m_Room.size(); i++){
		if (m_Room[i]->GetRoomId() == id) {
			m_Room[i]->SetRoute(WayPointBase::FIRST);
		}
		else if (m_Room[i]->GetRoomId() == destinationId) {
			m_Room[i]->SetRoute(WayPointBase::END);
		}
	}
	for (int i = 0; i < m_WayPoints.size(); i++) {
		for (int j = 0; j < m_WayPoints.size(); j++) {
			if (m_WayPoints[i]->GetRoute() == WayPointBase::FIRST) {
				if (m_WayPoints[j]->GetRoute() == WayPointBase::END) {
					route.push_back(m_WayPoints[i]);
					routes.push_back(route);
					SearchRoot(routes, 0, m_WayPoints[j], &isEnd);
					//m_Route.push_back(Recursion(m_WayPoints[j]->GetNearPoints(), tmpChoices));
					break;
				}
			}
		}
	}
		int cnt = 0;
		for (cnt = 0; cnt < routes.size(); cnt++) {
			if (routes[cnt].back()->GetRoute() == WayPointBase::END) {
				break;
			}
		}
		m_Route = routes[cnt];
		/*WayPointBase* tmp;
		for (int i = 0; i < m_WayPoints.size(); i++)
		{
			if (m_WayPoints[i]->GetRoute() == WayPointBase::END)
			{
				tmp = m_WayPoints[i]->GetOneBeforePoint();
			}
		}

		std::reverse(m_Route.begin(), m_Route.end());*/
}
// 再帰
//		ROOT_LIST ルート分岐数すべてを保存するリスト
//		root_id 分岐ルートのID
//		ゴールのID
//		終了フラグ
void WayPointManager::SearchRoot(std::vector<std::vector<WayPointBase*>> &root, int root_id, WayPointBase* goalId, bool *isEnd)
{
	int currentId = root[root_id].back()->GetPlace().Id;
	int list[4] = { -1, -1, -1, -1 };
	int cnt = 0;
	bool use = false;
	int newRootId[4] = { root_id, -1, -1, -1 };

	// イテレータで検索ルートの最後のリンクリストを調べる

	for (auto itr = m_WayPoints[currentId - 1]->GetNearPoints().begin(); itr != m_WayPoints[currentId - 1]->GetNearPoints().end(); itr++)
	{
		use = false;
		for (auto itr2 = root[root_id].begin(); itr2 != root[root_id].end(); itr2++)
		{
			// 既に検索済みのIDはしかと
			if ((*itr)->GetPlace().Id == (*itr2)->GetPlace().Id) {
				use = true;
			}
		}

		if (use == false) {
			// 未検索のIDは検索リスト候補
			list[cnt] = (*itr)->GetPlace().Id;
			if (goalId->GetPlace().Id == list[cnt]) {
				*isEnd = true;
			}
			cnt++;
		}
	}

	for (int i = 0; i < 4; i++) {
		std::vector<WayPointBase*> new_root;
		std::copy(root[root_id].begin(), root[root_id].end(), std::back_inserter(new_root));
		root.push_back(new_root);
		newRootId[i] = root.size() - 1;
	}
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < m_WayPoints.size(); j++) {

			if (list[i] == m_WayPoints[j]->GetPlace().Id) {
				// 検索ルートにIDを追加
				root[newRootId[i]].push_back(m_WayPoints[j]);
			}
		}
		// 終了してなかったら再帰
		if (*isEnd == false) {
			SearchRoot(root, newRootId[i], goalId, isEnd);
		}
	}
	//// 経路候補をチェック
	//for (int i = 3; i >= 0; i--)
	//{
	//	if (list[i] == -1) {
	//		continue;
	//	}

	//	// 0以外は分岐ルートとして新しく配列をコピーして作る
	//	if (list[i] != 0) {
	//		std::vector<WayPointBase*> new_root;
	//		std::copy(root[root_id].begin(), root[root_id].end(), std::back_inserter(new_root));
	//		root.push_back(new_root);
	//	}

	//	for (int j = 0; j < m_WayPoints.size(); j++) {
	//		
	//		if (list[i] == m_WayPoints[j]->GetPlace().Id) {
	//			// 検索ルートにIDを追加
	//			root[root_id + i].push_back(m_WayPoints[j]);
	//		}
	//	}
	//	// 終了してなかったら再帰
	//	if (*isEnd == false) {
	//		SearchRoot(root, root_id + i, goalId, isEnd);
	//	}
	//}
}

//WayPointBase* WayPointManager::Recursion(std::vector<WayPointBase*>& firstPoint, std::vector<WayPointBase*>& tmp)
//{
//	for (int i = 0; i < firstPoint.size(); i++)
//	{
//		for (int j = 0; j < firstPoint[i]->GetNearPoints().size(); j++)
//		{
//			if (firstPoint[i]->GetOneBeforePoint() != firstPoint[i]->GetNearPoints()[j]) {
//				tmp.push_back(firstPoint[i]->GetNearPoints()[j]);
//				tmp[i]->SetOneBeforePoint(firstPoint[i]);
//			}
//		}
//		if (tmp[i]->GetRoute() == WayPointBase::END)
//		{
//			return tmp[i];
//		}
//		return Recursion(tmp);
//	}
//}
//
//void WayPointManager::RouteFill(WayPointBase* tmp)
//{
//	while (tmp->GetRoute() == WayPointBase::FIRST)
//	{
//		for (int i = 0; i < m_WayPoints.size(); i++) 
//		{
//			if (tmp->GetPlace().Id == m_WayPoints[i]->GetPlace().Id)
//			{
//				tmp = m_WayPoints[i]->GetOneBeforePoint();
//				if (tmp->GetRoute() != WayPointBase::END) 
//				{
//					m_Route.push_back(tmp);
//				}
//				break;
//			}
//		}
//	}
//}