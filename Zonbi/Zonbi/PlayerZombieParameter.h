#ifndef PLAYERZOMBIEPARAMETER_H
#define PLAYERZOMBIEPARAMETER_H

//----------------------------------------------------------------------------------------
//include
//----------------------------------------------------------------------------------------
#include <vector>
#include<d3dx9.h>

class PlayerZombieParameter
{
public:
	struct ZombieData {
		D3DXVECTOR2 pos;
		float speed;
		int width;
		int height;
	};


	static PlayerZombieParameter& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new PlayerZombieParameter();
		}
		return *m_pInstance;
	}

	~PlayerZombieParameter();

	ZombieData* GetZombieParam() { return m_pPlayerZombiePram; }

	void LoadZombie();
private:
	static PlayerZombieParameter* m_pInstance;

	ZombieData* m_pPlayerZombiePram;

	PlayerZombieParameter();
};

#endif