#include<string>

#include "HumanParameter.h"


HumanParameter* HumanParameter::m_pInstance = nullptr;

HumanParameter::HumanParameter()
{
	LoadHuman();
}

HumanParameter::~HumanParameter()
{
}

void HumanParameter::LoadHuman() 
{
	m_HumanNum = 
		static_cast<int>(GetPrivateProfileInt("ヘッダー", "HumanNum", 0, "Property/HumanData.ini"));

	m_pHumanPram = new HumanData[m_HumanNum];

	for (int i = 0; i < m_HumanNum; i++) {
		std::string name = "一般人";
		name += std::to_string(i);

		m_pHumanPram[i].pos.x =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "PosX", 1, "Property/HumanData.ini"));
		m_pHumanPram[i].pos.y =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "PosY", 1, "Property/HumanData.ini"));
		m_pHumanPram[i].width =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "Width", 1, "Property/HumanData.ini"));
		m_pHumanPram[i].height =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "Height", 1, "Property/HumanData.ini"));
		m_pHumanPram[i].speed =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "Speed", 1, "Property/HumanData.ini"));
		m_pHumanPram[i].atkWidth =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "AtkWidth", 1, "Property/HumanData.ini"));
		m_pHumanPram[i].atkHeight =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "AtkHeight", 1, "Property/HumanData.ini"));
	}
}