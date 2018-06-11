#ifndef ZOMBIEPARAMETER_H
#define ZOMBIEPARAMETER_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include <vector>
#include<d3dx9.h>

class ZombieParameter
{
public:
	struct ZombieData {
		static int zombieNum;
		float speed;
		int width;
		int height;
	};

	static ZombieParameter& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new ZombieParameter();
		}
		return *m_pInstance;
	}

	~ZombieParameter();

	ZombieData* GetZombieParam() { return m_pZombiePram; }

	void LoadZombie();
private:
	static ZombieParameter* m_pInstance;
	ZombieData* m_pZombiePram;

	ZombieParameter();
};

#endif