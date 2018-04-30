#include"Game.h"
#include"DirectGraphics.h"


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

void Game::Update()
{
	m_Player->Update();
	m_ZombieManager->Update();
	m_HumanManager->Update();
	CollisionManager::GetcollisionManager()->Update();
}

void Game::Draw() 
{
	DirectGraphics::GetpInstance()->StartRender();
	m_ZombieManager->Draw();
	m_HumanManager->Draw();
	DirectGraphics::GetpInstance()->EndRender();
}

void Game::RunGame() 
{
	Update();
	Draw();
}