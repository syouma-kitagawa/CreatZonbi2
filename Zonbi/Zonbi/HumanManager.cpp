#include <algorithm>

#include"HumanManager.h"
#include"ZombieManager.h"
#include"HumanParameter.h"
#include"ZombieParameter.h"


HumanManager::HumanManager(ZombieManager* manager) : m_pZombieManager(manager)
{
	int humanNum = HumanParameter::GetInstance().GetHumanNum();
	m_pHuman.resize(humanNum);
	for (int i = 0; i < humanNum; i++) {
		HumanParameter param = HumanParameter::GetInstance();
		D3DXVECTOR2 vec = param.GetHumanParam(i)->pos;
		int width = param.GetHumanParam(i)->width;
		int height = param.GetHumanParam(i)->height;
		m_pHuman[i] = new Human(&vec, width, height);
	}
}


HumanManager::~HumanManager()
{

}


void HumanManager::Update()
{

	int humanCount = 0;
	for (auto ite = m_pHuman.begin(); ite != m_pHuman.end(); ++ite) {
		(*ite)->Update();
		if ((*ite)->IsRevival()){
			//IsDeth‚ªtrue‚ÌHuman‚ğÁ‚µ‚ÄZonbi‚É’Ç‰Á
			ZombieParameter::GetInstance().LoadZombie();
			float speed = ZombieParameter::GetInstance().GetZombieParam()->speed;
			int width = ZombieParameter::GetInstance().GetZombieParam()->width;
			int height = ZombieParameter::GetInstance().GetZombieParam()->height;
			m_pZombieManager->ZombieAdd((m_pHuman[humanCount]->Getpos()), speed, width, height);
			m_Humancnt--;
		}
		humanCount++;
	}
	auto removeIfFunc = [](Human* human)
	{
		if (human->IsRevival() == true) return true;
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