#include "ZonbiManager.h"

ZonbiManager::ZonbiManager()
{
	m_pZonbi.push_back(new Zonbi (D3DXVECTOR2(1000.f, 100.f)));
}


ZonbiManager::~ZonbiManager()
{
	for (auto ite = m_pZonbi.begin(); ite != m_pZonbi.end(); ++ite) {
		delete *ite;
	}
}


void ZonbiManager::Update()
{
	for (auto ite = m_pZonbi.begin(); ite != m_pZonbi.end(); ++ite) {
		(*ite)->Update();
	}
}

void ZonbiManager::Draw()
{
	for (auto ite = m_pZonbi.begin(); ite != m_pZonbi.end(); ++ite) {
		(*ite)->Draw();
	}
}

void ZonbiManager::ZonbiAdd(D3DXVECTOR2 pos)
{
	//emplace_back
	m_pZonbi.push_back(new Zonbi(pos));
}