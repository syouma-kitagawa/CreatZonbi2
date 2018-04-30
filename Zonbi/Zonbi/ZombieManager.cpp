#include "ZombieManager.h"

ZombieManager::ZombieManager()
{
	m_pZombie.push_back(new Zombie(D3DXVECTOR2(1000.f, 100.f)));
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
	m_pZombie.push_back(new Zombie(pos));
}