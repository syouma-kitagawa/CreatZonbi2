#include"ZombieManager.h"
#include"ZombieParameter.h"
ZombieManager::ZombieManager()
{
	ZombieParameter param = ZombieParameter::GetInstance();
	D3DXVECTOR2 vec = param.GetInstance().GetZombieParam()->pos;
	float speed = param.GetInstance().GetZombieParam()->speed;
	m_pZombie.push_back(new Zombie(vec, speed));
}



ZombieManager::~ZombieManager()
{
	for (auto ite = m_pZombie.begin(); ite != m_pZombie.end(); ++ite) {
		delete *ite;
	}
}


void ZombieManager::Update()
{
	for (auto ite = m_pZombie.begin(); ite != m_pZombie.end(); ++ite) {
		(*ite)->Update();
	}
}

void ZombieManager::Draw()
{
	for (auto ite = m_pZombie.begin(); ite != m_pZombie.end(); ++ite) {
		(*ite)->Draw();
	}
}

void ZombieManager::ZombieAdd(D3DXVECTOR2 pos)
{
	m_pZombie.push_back(new Zombie(pos,1.0f));
}