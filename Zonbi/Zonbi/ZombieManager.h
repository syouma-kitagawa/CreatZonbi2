#ifndef ZOMBIEMANAGER_H
#define ZOMBIEMANAGER_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include <vector>

#include"ObjectBase.h"
#include"Zombie.h"
#include"PlayerZombie.h"

class ZombieManager : public ObjectBase
{
public:
	ZombieManager();
	virtual ~ZombieManager();
	virtual void Draw();
	virtual void Update();

	void ZombieAdd(D3DXVECTOR2* pos, float speed, int width, int height);
private:
	std::vector<Zombie*> m_pZombie;
	PlayerZombie* m_pPlayerZombie;
};

#endif