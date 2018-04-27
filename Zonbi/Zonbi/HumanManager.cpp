#include <algorithm>

#include"HumanManager.h"
#include"ZonbiManager.h"


HumanManager::HumanManager(ZonbiManager* manager) : m_pZonbiManager(manager)
{
	m_pHuman.push_back(new Human(D3DXVECTOR2(200.f, 200.f)));
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
				m_pZonbiManager->ZonbiAdd(m_pHuman[humanCount]->Getpos());
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