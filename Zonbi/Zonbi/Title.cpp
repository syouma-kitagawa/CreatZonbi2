#include"Title.h"
#include"DirectGraphics.h"
#include"TitleBackgraund.h"
#include"ObjectBase.h"
#include"DirectInput.h"
#include"SoundBufferManager.h"

Title::Title()
{
	m_Fader = new Fader(240);
	m_pObjectBase.push_back(new TitleBackgraund());
	SoundBufferManager::GetInstance().LoadWaveFile("BGM/Title.wav");
}


Title::~Title()
{
	SoundBufferManager::GetInstance().CancelSound("BGM/Title.wav");
	for (auto ite = m_pObjectBase.begin(); ite != m_pObjectBase.end(); ++ite) {
		delete *ite;
	}
}

SceneBase::SCENE_ID Title::Update()
{
		SoundBufferManager::GetInstance().PlayBackSound("BGM/Title.wav", true);
	SCENE_ID retSceneId = SCENE_ID::TITLE;
	DirectInput::GetInstance().UpdateMouse();
	if (DirectInput::GetInstance().GetMouseData()->LeftMouse == Utility::BUTTON_STATE::PUSH) {
		m_FaderStart = true;
	}
	if (m_FaderStart) {
		m_Fader->FadeOut();
		if (m_Fader->GetFadeFinish()) {
			retSceneId = SCENE_ID::MAIN;
		}
	}
	return retSceneId;
}

void Title::Draw()
{
	DirectGraphics::GetpInstance()->StartRender();

	for (auto ite = m_pObjectBase.begin(); ite != m_pObjectBase.end(); ++ite) {
		(*ite)->Draw();
	}
	if (m_FaderStart) {
		m_Fader->Draw();
	}
	DirectGraphics::GetpInstance()->EndRender();
}