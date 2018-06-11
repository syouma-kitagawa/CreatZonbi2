#include<string>

#include"RoomParameter.h"


RoomParameter* RoomParameter::m_pInstance = nullptr;

RoomParameter::RoomParameter()
{
	LoadRoom();
}

RoomParameter::~RoomParameter()
{
}

void RoomParameter::LoadRoom()
{
	m_RoomMax =
		static_cast<int>(GetPrivateProfileInt("����", "�����̍��v", 0, "Property/RoomData.ini"));

	m_pRoomPram = new RoomData[m_RoomMax];

	for (int i = 0; i < m_RoomMax; i++) {
		std::string name = "����";
		name += std::to_string(i);
		m_pRoomPram[i].Rect.left =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "�����X", 1, "Property/RoomData.ini"));
		m_pRoomPram[i].Rect.top =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "�����Y", 1, "Property/RoomData.ini"));
		m_pRoomPram[i].Rect.right=
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "�E����X", 1, "Property/RoomData.ini"));
		m_pRoomPram[i].Rect.bottom =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "�E����Y", 1, "Property/RoomData.ini"));
		m_pRoomPram[i].Id =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "�����ԍ�", 0, "Property/RoomData.ini"));
	}
}