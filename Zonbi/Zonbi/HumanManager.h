#ifndef HUMANMANAGER_H
#define HUMANMANAGER_H

#include <vector>

#include"Human.h"

class ZombieManager;

class HumanManager
{
public:
	HumanManager(ZombieManager* manager);
	~HumanManager();
	void Draw();
	void Update();
private:
	std::vector<Human*> m_pHuman;
	ZombieManager* m_pZombieManager;
};

#endif