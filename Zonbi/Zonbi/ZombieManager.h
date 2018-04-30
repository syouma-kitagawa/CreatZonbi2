#ifndef ZOMBIEMANAGER_H
#define ZOMBIEMANAGER_H

#include <vector>

#include"Zombie.h"

class ZombieManager
{
public:
	ZombieManager();
	~ZombieManager();
	void Draw();
	void Update();

	void ZombieAdd(D3DXVECTOR2 pos);
private:
	std::vector<Zombie*> m_pZombie;
};

#endif