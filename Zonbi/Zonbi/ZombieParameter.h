#ifndef ZOMBIEPARAMETER_H
#define ZOMBIEPARAMETER_H

#include <vector>
#include<d3dx9.h>

class ZombieParameter
{
public:
	struct ZombieData {
		D3DXVECTOR2 pos;
		float speed;
	};

	static ZombieParameter& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new ZombieParameter;
		}
		return *m_pInstance;
	}

	~ZombieParameter();

	ZombieData* GetZombieParam() { return m_pZombiePram; }

	void LoadZombie();
private:
	static ZombieParameter* m_pInstance;

	float m_ZombieSpeed = 0.0f;
	ZombieData* m_pZombiePram;

	ZombieParameter();
};

#endif