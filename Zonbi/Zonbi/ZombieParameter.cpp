#include "ZombieParameter.h"


ZombieParameter* ZombieParameter::m_pInstance = nullptr;

ZombieParameter::ZombieParameter()
{
	LoadZombie();
}

ZombieParameter::~ZombieParameter()
{
}

void ZombieParameter::LoadZombie()
{
	m_pZombiePram = new ZombieData;

		std::string name = "ƒ]ƒ“ƒr";

		m_pZombiePram->pos.x =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "PosX", 1, "Property/ZombieData.ini"));
		m_pZombiePram->pos.y =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "PosY", 1, "Property/ZombieData.ini"));
		m_pZombiePram->speed =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "Speed", 1, "Property/ZombieData.ini"));
}