#include"Title.h"
#include"DirectGraphics.h"
#include"TitleBackgraund.h"
#include"ObjectBase.h"

Title::Title()
{

}


Title::~Title()
{
}

SceneBase::SCENE_ID Title::Update()
{
	SCENE_ID retSceneId = SCENE_ID::TITLE;

	return retSceneId;
}

void Title::Draw()
{
	DirectGraphics::GetpInstance()->StartRender();

	for (auto ite = m_pObjectBase.begin(); ite != m_pObjectBase.end(); ++ite) {
		(*ite)->Draw();
	}
	DirectGraphics::GetpInstance()->EndRender();
}