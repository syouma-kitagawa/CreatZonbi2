#include <algorithm>

#include"HumanManager.h"
#include"ZombieManager.h"


HumanManager::HumanManager(ZombieManager* manager) : m_pZombieManager(manager)
{
	m_pHuman.push_back(new Human(D3DXVECTOR2(200.f, 200.f)));
	m_pHuman.push_back(new Human(D3DXVECTOR2(300.f, 200.f)));
	m_pHuman.push_back(new Human(D3DXVECTOR2(400.f, 200.f)));
}


HumanManager::~HumanManager()
{

}


void HumanManager::Update()
{
	int humanCount = 0;
	for (auto ite = m_pHuman.begin(); ite != m_pHuman.end(); ++ite) {
		(*ite)->Update();
		if ((*ite)->IsDeth()){
			//IsDeth‚ªtrue‚ÌHuman‚ðÁ‚µ‚ÄZonbi‚É’Ç‰Á
			{
				m_pZombieManager->ZombieAdd(m_pHuman[humanCount]->Getpos());
			}
		}
		humanCount++;
	}
	auto removeIfFunc = [](Human* human)
	{
		if (human->IsDeth() == true) return true;

		return false;
	};
	m_pHuman.erase(
		std::remove_if(m_pHuman.begin(), m_pHuman.end(),
			removeIfFunc), m_pHuman.end());
}

void HumanManager::Draw()
{
	for (auto ite = m_pHuman.begin(); ite != m_pHuman.end(); ++ite) {
		(*ite)->Draw();
	}
}