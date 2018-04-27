#ifndef HUMANMANAGER_H
#define HUMANMANAGER_H

#include <vector>

#include"Human.h"

class ZonbiManager;

class HumanManager
{
public:
	HumanManager(ZonbiManager* manager);
	~HumanManager();
	void Draw();
	void Update();
private:
	std::vector<Human*> m_pHuman;
	ZonbiManager* m_pZonbiManager;
};

#endif