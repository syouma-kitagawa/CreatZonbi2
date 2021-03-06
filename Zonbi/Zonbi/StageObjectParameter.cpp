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
		static_cast<int>(GetPrivateProfileInt("壁合計", "ObjectNum", 70, "Property/ObjectData.ini"));

	m_pStageObjectPram = new StageObjectData[m_StageObjectNum];
	for (int i = 0; i < m_StageObjectNum; i++) {
		std::string name = "壁";
		name += std::to_string(i);
			m_pStageObjectPram[i].Rect.left =
				static_cast<int>(GetPrivateProfileInt(name.c_str(), "左上のX", 1, "Property/ObjectData.ini"));
			m_pStageObjectPram[i].Rect.top =
				static_cast<int>(GetPrivateProfileInt(name.c_str(), "左上のY", 1, "Property/ObjectData.ini"));
			m_pStageObjectPram[i].Rect.right =
				static_cast<int>(GetPrivateProfileInt(name.c_str(), "右下のX", 1, "Property/ObjectData.ini"));
			m_pStageObjectPram[i].Rect.bottom =
				static_cast<int>(GetPrivateProfileInt(name.c_str(), "右下のY", 1, "Property/ObjectData.ini"));
	}

}