#include"Game.h"
#include"DirectGraphics.h"


Game::Game()
{
	CollisionManager::GetcollisionManager()->CreateCollisionManager();
	m_ZonbiManager = new ZonbiManager();
	m_HumanManager = new HumanManager(m_ZonbiManager);
	m_Player = new Player();
}


Game::~Game()
{
	delete m_ZonbiManager;
	delete m_HumanManager;
	delete m_Player;
}

void Game::Update()
{
	m_Player->Update();
	m_ZonbiManager->Update();
	m_HumanManager->Update();
	CollisionManager::GetcollisionManager()->Update();
}

void Game::Draw() 
{
	DirectGraphics::GetpInstance()->StartRender();
	m_ZonbiManager->Draw();
	m_HumanManager->Draw();
	DirectGraphics::GetpInstance()->EndRender();
}

void Game::RunGame() 
{
	Update();
	Draw();
}