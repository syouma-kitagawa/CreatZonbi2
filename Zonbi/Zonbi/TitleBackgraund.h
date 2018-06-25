#ifndef TITLEBACKGRAUND_H
#define TITLEBACKGRAUND_H

//------------------------------------------------------------------------------------------
//include
//------------------------------------------------------------------------------------------
#include"ObjectBase.h"

class TitleBackgraund : public ObjectBase{
public:
	TitleBackgraund();
	virtual ~TitleBackgraund();
	virtual void Draw();
	virtual void Update() {};
private:
};
#endif