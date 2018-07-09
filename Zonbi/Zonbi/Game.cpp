#include"ZombieManager.h"
#include"HumanManager.h"
#include"PlayerControl.h"
#include"StageManager.h"
#include"GameBackground.h"
#include"Game.h"
#include"DirectGraphics.h"
#include"DirectInput.h"
#include"TimeLimit.h"
#include"SoundBufferManager.h"
#include"Fader.h"

Game::Game()
{
	CollisionManager::GetcollisionManager()->CreateCollisionManager();
	SoundBufferManager::GetInstance().LoadWaveFile("BGM/GamePlay.wav");
	m_Fader = new Fader(240);
	m_ZombieManager = new ZombieManager();
	m_HumanManager = new HumanManager(m_ZombieManager);
	m_PlayerControl = new PlayerControl();
	m_StageObjectManager = new StageManager();
	m_GameBackground = new GameBackground();
	m_TimeLimit = new TimeLimit(std::bind(&Game::SetRetSceneId, this, std::placeholders::_1), 150);
	m_ObjectBase.push_back(m_ZombieManager);
	m_ObjectBase.push_back(m_HumanManager);
	m_ObjectBase.push_back(m_TimeLimit);
}


Game::~Game()
{
	SoundBufferManager::GetInstance().CancelSound("BGM/GamePlay.wav");
	for (auto ite = m_ObjectBase.begin(); ite != m_ObjectBase.end(); ++ite) {
		delete *ite;
	}
	delete m_PlayerControl;
	delete m_StageObjectManager;
}

SceneBase::SCENE_ID Game::Update()
{
	if (m_first) {
		m_Fader->FadeIn();
	}
	if (m_Fader->GetFadeFinish()){
		SCENE_ID retId = SCENE_ID::MAIN;
		DirectInput::GetInstance().UpdateMouse();
		m_PlayerControl->Update();
		SoundBufferManager::GetInstance().PlayBackSound("BGM/GamePlay.wav", true);
		CollisionManager::GetcollisionManager()->Update();
		for (auto ite = m_ObjectBase.begin(); ite != m_ObjectBase.end(); ++ite) {
			(*ite)->Update();
		}
	}
	if (m_TimeLimit->GetLimits() == 0) {
		retId = SCENE_ID::GAMEOVER;
	}
	if (m_HumanManager->GetHumancnt() == 0) {
		retId = SCENE_ID::GAMECLEAR;
	}
	return retId;
}

void Game::Draw() 
{
	DirectGraphics::GetpInstance()->StartRender();
	m_GameBackground->Draw();
	for (auto ite = m_ObjectBase.begin(); ite != m_ObjectBase.end(); ++ite) {
		(*ite)->Draw();
	}
	m_GameBackground->WallDraw();
#ifdef DEBUG_RUN
	DebugDrawHitRect(m_StageObjectManager);
	DebugPlayerHitRect(m_ZombieManager->GetPlayerZombi());
#endif
	if (m_first) {
		m_Fader->Draw();
	}
	DirectGraphics::GetpInstance()->EndRender();
}