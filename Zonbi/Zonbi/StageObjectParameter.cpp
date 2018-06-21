#include<string>

#include"StageObjectParameter.h"


StageObjectParameter* StageObjectParameter::m_pInstance = nullptr;

StageObjectParameter::StageObjectParameter()
{
	LoadStageObject();
}

StageObjectParameter::~StageObjectParameter()
{
}

void StageObjectParameter::LoadStageObject()
{
	m_StageObjectNum =
		static_cast<int>(GetPrivateProfileInt("�Ǎ��v", "ObjectNum", 70, "Property/ObjectData.ini"));

	m_pStageObjectPram = new StageObjectData[m_StageObjectNum];
	for (int i = 0; i < m_StageObjectNum; i++) {
		std::string name = "��";
		name += std::to_string(i);
			m_pStageObjectPram[i].Rect.left =
				static_cast<int>(GetPrivateProfileInt(name.c_str(), "�����X", 1, "Property/ObjectData.ini"));
			m_pStageObjectPram[i].Rect.top =
				static_cast<int>(GetPrivateProfileInt(name.c_str(), "�����Y", 1, "Property/ObjectData.ini"));
			m_pStageObjectPram[i].Rect.right =
				static_cast<int>(GetPrivateProfileInt(name.c_str(), "�E����X", 1, "Property/ObjectData.ini"));
			m_pStageObjectPram[i].Rect.bottom =
				static_cast<int>(GetPrivateProfileInt(name.c_str(), "�E����Y", 1, "Property/ObjectData.ini"));
	}

}