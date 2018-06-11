#include<string>

#include"ZombieParameter.h"

ZombieParameter* ZombieParameter::m_pInstance = nullptr;

int ZombieParameter::ZombieData::zombieNum = 0;

ZombieParameter::ZombieParameter()
{
	m_pZombiePram = new ZombieData;
}

ZombieParameter::~ZombieParameter()
{
}

void ZombieParameter::LoadZombie()
{
	std::string name = "ƒ]ƒ“ƒr";
	name += std::to_string(m_pZombiePram->zombieNum);
	m_pZombiePram->speed =
		static_cast<int>(GetPrivateProfileInt(name.c_str(), "Speed", 1, "Property/ZombieData.ini"));
	m_pZombiePram->width =
		static_cast<int>(GetPrivateProfileInt(name.c_str(), "Width", 100, "Property/ZombieData.ini"));
	m_pZombiePram->height =
		static_cast<int>(GetPrivateProfileInt(name.c_str(), "Height", 100, "Property/ZombieData.ini"));
	m_pZombiePram->zombieNum++;
}