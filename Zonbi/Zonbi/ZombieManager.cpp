#include"ZombieManager.h"
#include"PlayerZombieParameter.h"
#include"WayPointManager.h"
ZombieManager::ZombieManager()
{
	PlayerZombieParameter param = PlayerZombieParameter::GetInstance();
	D3DXVECTOR2 vec = param.GetInstance().GetZombieParam()->pos;
	float speed = param.GetInstance().GetZombieParam()->speed;
	int width = param.GetInstance().GetZombieParam()->width;
	int height = param.GetInstance().GetZombieParam()->height;
	m_pPlayerZombie = new PlayerZombie(&vec, speed, width, height);
}



ZombieManager::~ZombieManager()
{
	delete m_pPlayerZombie;
	for (auto ite = m_pZombie.begin(); ite != m_pZombie.end(); ++ite) {
		delete *ite;
	}
}


void ZombieManager::Update()
{
	m_pPlayerZombie->Update();
	for (auto ite = m_pZombie.begin(); ite != m_pZombie.end(); ++ite) {
		(*ite)->Update();
	}
}

void ZombieManager::Draw()
{
	m_pPlayerZombie->Draw();
	for (auto ite = m_pZombie.begin(); ite != m_pZombie.end(); ++ite) {
		(*ite)->Draw();
	}
}

void ZombieManager::ZombieAdd(D3DXVECTOR2* pos, float speed, int width, int height)
{
	m_pZombie.push_back(new Zombie(pos,speed,width,height));
}
