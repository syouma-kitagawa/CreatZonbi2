#include"GameOver.h"
#include"DirectGraphics.h"
#include"GameOverBackground.h"
#include"DirectInput.h"
#include"SoundBufferManager.h"

GameOver::GameOver()
{
	m_pObjectBase.push_back(new GameOverBackground());
	SoundBufferManager::GetInstance().LoadWaveFile("BGM/GameOver.wav");
}


GameOver::~GameOver()
{
	SoundBufferManager::GetInstance().CancelSound("BGM/GameOver.wav");
}

SceneBase::SCENE_ID GameOver::Update()
{
	SCENE_ID retSceneId = SCENE_ID::GAMEOVER;
	SoundBufferManager::GetInstance().PlayBackSound("BGM/GameOver.wav", true);
	DirectInput::GetInstance().UpdateMouse();
	if (DirectInput::GetInstance().GetMouseData()->LeftMouse == Utility::BUTTON_STATE::PUSH) {
		retSceneId = SCENE_ID::TITLE;
	}
	return retSceneId;
}
void GameOver::Draw()
{
	DirectGraphics::GetpInstance()->StartRender();

	for (auto ite = m_pObjectBase.begin(); ite != m_pObjectBase.end(); ++ite) {
		(*ite)->Draw();
	}
	DirectGraphics::GetpInstance()->EndRender();
}