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


Game::Game()
{
	CollisionManager::GetcollisionManager()->CreateCollisionManager();
	//SoundBufferManager::GetInstance().LoadWaveFile("BGM\\TitleBgm.wav");
	m_ZombieManager = new ZombieManager();
	m_HumanManager = new HumanManager(m_ZombieManager);
	m_PlayerControl = new PlayerControl();
	m_StageObjectManager = new StageManager();
	m_GameBackground = new GameBackground();
	m_TimeLimit = new TimeLimit(std::bind(&Game::SetRetSceneId, this, std::placeholders::_1), 100);
	m_ObjectBase.push_back(m_ZombieManager);
	m_ObjectBase.push_back(m_HumanManager);
	m_ObjectBase.push_back(m_TimeLimit);
}


Game::~Game()
{
	//SoundBufferManager::GetInstance().CancelSound("BGM\\TitleBgm.wav");
	for (auto ite = m_ObjectBase.begin(); ite != m_ObjectBase.end(); ++ite) {
		delete *ite;
	}
	delete m_PlayerControl;
	delete m_StageObjectManager;
}

SceneBase::SCENE_ID Game::Update()
{
	SCENE_ID retId = SCENE_ID::MAIN;
	DirectInput::GetInstance().UpdateMouse();
	m_PlayerControl->Update();
	if (!m_IsMusic) {
	//	SoundBufferManager::GetInstance().PlayBackSound("BGM\\TitleBgm.wav", true);
	}
	for (auto ite = m_ObjectBase.begin(); ite != m_ObjectBase.end(); ++ite) {
		(*ite)->Update();
	}
	if (m_TimeLimit->GetLimits() == 0) {
		retId = SCENE_ID::GAMEOVER;
	}
	if (m_HumanManager->GetHumancnt() == 0) {
		retId = SCENE_ID::GAMECLEAR;
	}
	CollisionManager::GetcollisionManager()->Update();
	return retId;
}

void Game::Draw() 
{
	DirectGraphics::GetpInstance()->StartRender();
	m_GameBackground->Draw();
	for (auto ite = m_ObjectBase.begin(); ite != m_ObjectBase.end(); ++ite) {
		(*ite)->Draw();
	}
	DirectGraphics::GetpInstance()->EndRender();
}