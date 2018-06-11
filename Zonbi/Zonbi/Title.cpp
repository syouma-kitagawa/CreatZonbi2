#include"Title.h"
#include"DirectGraphics.h"
#include"TitleBackgraund.h"
#include"ObjectBase.h"
#include"DirectInput.h"
#include"SoundBufferManager.h"

Title::Title()
{
	m_pObjectBase.push_back(new TitleBackgraund());
	//SoundBufferManager::GetInstance().LoadWaveFile("BGM\\TitleBgm.wav");
}


Title::~Title()
{
	//SoundBufferManager::GetInstance().CancelSound("BGM\\TitleBgm.wav");
	for (auto ite = m_pObjectBase.begin(); ite != m_pObjectBase.end(); ++ite) {
		delete *ite;
	}
}

SceneBase::SCENE_ID Title::Update()
{
	if (!m_IsMusic) {
	//	SoundBufferManager::GetInstance().PlayBackSound("BGM\\TitleBgm.wav", true);
	}
	SCENE_ID retSceneId = SCENE_ID::TITLE;
	DirectInput::GetInstance().UpdateMouse();
	if (DirectInput::GetInstance().GetMouseData()->LeftMouse == Utility::BUTTON_STATE::PUSH) {
		retSceneId = SCENE_ID::MAIN;
	}
	return retSceneId;
}

void Title::Draw()
{
	DirectGraphics::GetpInstance()->StartRender();

	for (auto ite = m_pObjectBase.begin(); ite != m_pObjectBase.end(); ++ite) {
		(*ite)->Draw();
	}
	DirectGraphics::GetpInstance()->EndRender();
}