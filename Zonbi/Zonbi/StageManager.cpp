#include"StageManager.h"
#include"StageObjectParameter.h"
#include"RoomParameter.h"
#include"WayPointBase.h"


StageManager::StageManager()
{
	////当たり判定付きのオブジェクト生成
	int StageObjectNum = StageObjectParameter::GetInstance().GetStageObjectNum();
	m_pStageObject.resize(StageObjectNum);
	for (int i = 0; i < StageObjectNum; i++) {
		RECT rect;
		StageObjectParameter param = StageObjectParameter::GetInstance();
		rect = param.GetStageObjectParam(i)->Rect;
		m_pStageObject[i] = new StageObject(rect);
	}
}


StageManager::~StageManager()
{
	for (auto ite = m_pStageObject.begin(); ite != m_pStageObject.end(); ++ite) {
		delete *ite;
	}
}
