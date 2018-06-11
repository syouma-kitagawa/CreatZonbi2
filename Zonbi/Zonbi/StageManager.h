#ifndef STAGEMANAGER_H
#define STAGEMANAGER_H

//------------------------------------------------------------------------------------------
//include
//------------------------------------------------------------------------------------------
#include <vector>

#include"StageObject.h"
#include"Room.h"

class StageManager
{
public:
	StageManager();
	~StageManager();

#ifdef DEBUG_RUN
	std::vector<StageObject*> GetStageObject()
	{
		return m_pStageObject;
	}
#endif

private:
	std::vector<StageObject*> m_pStageObject;
	std::vector<Room*> m_pRoom;
};

#endif