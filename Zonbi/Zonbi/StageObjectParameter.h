#ifndef STAGEOBJECTPARAMETER_H
#define STAGEOBJECTPARAMETER_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include<d3dx9.h>

class StageObjectParameter
{
public:
	struct StageObjectData {
		RECT Rect;
	};

	static StageObjectParameter& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new StageObjectParameter();
		}
		return *m_pInstance;
	}

	~StageObjectParameter();

	int GetStageObjectNum() { return m_StageObjectNum; }
	StageObjectData* GetStageObjectParam(int number) { return &m_pStageObjectPram[number]; }

	void LoadStageObject();
private:
	static StageObjectParameter* m_pInstance;

	int m_StageObjectNum = 0;
	StageObjectData* m_pStageObjectPram;

	StageObjectParameter();
};

#endif