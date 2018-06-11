#ifndef HUMANMANAGER_H
#define HUMANMANAGER_H

//---------------------------------------------------------------------------------------------
//include
//---------------------------------------------------------------------------------------------
#include <vector>

#include"ObjectBase.h"
#include"Human.h"

class ZombieManager;
class Human;

class HumanManager : public ObjectBase
{
public:
	HumanManager(ZombieManager* manager);
	virtual ~HumanManager();
	virtual void Draw();
	virtual void Update();
	int GetHumancnt() { return m_Humancnt; }
private:
	int m_Humancnt = 3;

	std::vector<Human*> m_pHuman;
	ZombieManager* m_pZombieManager;
};

#endif