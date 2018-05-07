#include"Game.h"
#include"DirectGraphics.h"
#include"DirectInput.h"


Game::Game()
{
	CollisionManager::GetcollisionManager()->CreateCollisionManager();
	m_ZombieManager = new ZombieManager();
	m_HumanManager = new HumanManager(m_ZombieManager);
	m_Player = new Player();
}


Game::~Game()
{
	delete m_ZombieManager;
	delete m_HumanManager;
	delete m_Player;
}

SceneBase::SCENE_ID Game::Update()
{
	SCENE_ID retSceneId = SCENE_ID::MAIN;
	DirectInput::GetInstance().UpdateMouse();
	m_Player->Update();
	m_ZombieManager->Update();
	m_HumanManager->Update();
	CollisionManager::GetcollisionManager()->Update();
	return retSceneId;
}

void Game::Draw() 
{
	DirectGraphics::GetpInstance()->StartRender();
	m_ZombieManager->Draw();
	m_HumanManager->Draw();
	DirectGraphics::GetpInstance()->EndRender();
}