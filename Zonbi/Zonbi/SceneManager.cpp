#include "SceneManager.h"
#include"SceneFactory.h"

SceneManager::SceneManager()
{
	m_pSceneFactory = new SceneFactory;
	//Å‰‚Ì‰æ–Ê‚ÌID‚ð“ü‚ê‚Ä‚¨‚­
	m_pScene = m_pSceneFactory->Create(SceneBase::SCENE_ID::MAIN);
}

SceneManager::~SceneManager()
{
	delete m_pScene;
	delete m_pSceneFactory;
}

void SceneManager::Run()
{
	SceneBase::SCENE_ID nextSceneID = m_pScene->Update();

	m_pScene->Draw();

	if (nextSceneID != m_PrevSceneID) {
		delete m_pScene;
		m_pScene = nullptr;
		m_pScene = m_pSceneFactory->Create(nextSceneID);
		m_PrevSceneID = nextSceneID;
	}
}
