#include <algorithm>

#include"HumanManager.h"
#include"ZombieManager.h"
#include"HumanParameter.h"


HumanManager::HumanManager(ZombieManager* manager) : m_pZombieManager(manager)
{
	//int humanNum = HumanParameter::GetInstance().GetHumanNum();
	//m_pHuman.resize(humanNum);
	//for (int i = 0; i < humanNum; i++) {
	//	HumanParameter param = HumanParameter::GetInstance();
	//	D3DXVECTOR2 vec = param.GetHumanParam(i)->pos;
	//	//m_pHuman[i]->Setpos(&(HumanParameter::GetInstance().GetHumanParam(i)->pos));
	//	m_pHuman[i]->Setpos(&(vec));
	//}
	
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
			//IsDeth‚ªtrue‚ÌHuman‚ğÁ‚µ‚ÄZonbi‚É’Ç‰Á
			{
				m_pZombieManager->ZombieAdd(*(m_pHuman[humanCount]->Getpos()));
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