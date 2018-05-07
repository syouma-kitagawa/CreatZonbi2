#ifndef TITLEBACKGRAUND_H
#define TITLEBACKGRAUND_H

#include"ObjectBase.h"

class TitleBackgraund : public ObjectBase{
public:
	TitleBackgraund();
	virtual ~TitleBackgraund();
	virtual void Update(){};
	virtual void Draw();
};
#endif