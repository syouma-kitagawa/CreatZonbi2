#include"GameOver.h"
#include"DirectGraphics.h"
#include"GameOverBackground.h"
#include"DirectInput.h"

GameOver::GameOver()
{
	m_pObjectBase.push_back(new GameOverBackground());
}


GameOver::~GameOver()
{
}

SceneBase::SCENE_ID GameOver::Update()
{
	SCENE_ID retSceneId = SCENE_ID::GAMEOVER;
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