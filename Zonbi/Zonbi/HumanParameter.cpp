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
		m_pHumanPram[i].tmpPos[0].x =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "Pos0x", 1, "Property/HumanData.ini"));
		m_pHumanPram[i].tmpPos[0].y =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "Pos0y", 1, "Property/HumanData.ini"));
		m_pHumanPram[i].tmpPos[1].x =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "Pos1x", 1, "Property/HumanData.ini"));
		m_pHumanPram[i].tmpPos[1].y =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "Pos1y", 1, "Property/HumanData.ini"));
		m_pHumanPram[i].tmpPos[2].x =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "Pos2x", 1, "Property/HumanData.ini"));
		m_pHumanPram[i].tmpPos[2].y =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "Pos2y", 1, "Property/HumanData.ini"));
		m_pHumanPram[i].tmpPos[3].x =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "Pos3x", 1, "Property/HumanData.ini"));
		m_pHumanPram[i].tmpPos[3].y =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "Pos3y", 1, "Property/HumanData.ini"));
	}
}