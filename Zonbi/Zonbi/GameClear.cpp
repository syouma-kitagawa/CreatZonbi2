#include"GameClear.h"
#include"DirectGraphics.h"
#include"GameClearBackground.h"
#include"DirectInput.h"

GameClear::GameClear()
{
	m_pObjectBase.push_back(new GameClearBackground());
}


GameClear::~GameClear()
{
	for (auto ite = m_pObjectBase.begin(); ite != m_pObjectBase.end(); ++ite) {
		delete *ite;
	}
}

SceneBase::SCENE_ID GameClear::Update()
{
	SCENE_ID retSceneId = SCENE_ID::GAMECLEAR;
	DirectInput::GetInstance().UpdateMouse();
	if (DirectInput::GetInstance().GetMouseData()->LeftMouse == Utility::BUTTON_STATE::PUSH) {
		retSceneId = SCENE_ID::TITLE;
	}
	return retSceneId;
}
void GameClear::Draw()
{
	DirectGraphics::GetpInstance()->StartRender();

	for (auto ite = m_pObjectBase.begin(); ite != m_pObjectBase.end(); ++ite) {
		(*ite)->Draw();
	}
	DirectGraphics::GetpInstance()->EndRender();
}