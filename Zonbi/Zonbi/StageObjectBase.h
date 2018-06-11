#ifndef STAGEOBJECTBASE_H
#define STAGEOBJECTBASE_H

//--------------------------------------------------------------------------------------------
//include
//--------------------------------------------------------------------------------------------
#include<d3dx9.h>

class StageObjectBase {
public:
	StageObjectBase() {};
	virtual ~StageObjectBase() {};
private:
	D3DXVECTOR2 m_Vertex[2];
};
#endif