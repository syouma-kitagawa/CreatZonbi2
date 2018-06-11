#include "PlayerZombieParameter.h"

PlayerZombieParameter* PlayerZombieParameter::m_pInstance = nullptr;

PlayerZombieParameter::PlayerZombieParameter()
{
	LoadZombie();
}

PlayerZombieParameter::~PlayerZombieParameter()
{
}

void PlayerZombieParameter::LoadZombie()
{
	m_pPlayerZombiePram = new ZombieData;

		std::string name = "ŽålŒöƒ]ƒ“ƒr";

		m_pPlayerZombiePram->pos.x =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "PosX", 1, "Property/PlayerZombieData.ini"));
		m_pPlayerZombiePram->pos.y =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "PosY", 1, "Property/PlayerZombieData.ini"));
		m_pPlayerZombiePram->speed =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "Speed", 1, "Property/PlayerZombieData.ini"));
		m_pPlayerZombiePram->width = 
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "Width", 1, "Property/PlayerZombieData.ini"));
		m_pPlayerZombiePram->height = 
		static_cast<int>(GetPrivateProfileInt(name.c_str(), "Height", 1, "Property/PlayerZombieData.ini"));
}