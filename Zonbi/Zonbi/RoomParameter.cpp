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
		static_cast<int>(GetPrivateProfileInt("部屋", "部屋の合計", 0, "Property/RoomData.ini"));

	m_pRoomPram = new RoomData[m_RoomMax];

	for (int i = 0; i < m_RoomMax; i++) {
		std::string name = "部屋";
		name += std::to_string(i);
		m_pRoomPram[i].Rect.left =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "左上のX", 1, "Property/RoomData.ini"));
		m_pRoomPram[i].Rect.top =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "左上のY", 1, "Property/RoomData.ini"));
		m_pRoomPram[i].Rect.right=
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "右下のX", 1, "Property/RoomData.ini"));
		m_pRoomPram[i].Rect.bottom =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "右下のY", 1, "Property/RoomData.ini"));
		m_pRoomPram[i].Id =
			static_cast<int>(GetPrivateProfileInt(name.c_str(), "部屋番号", 0, "Property/RoomData.ini"));
	}
}