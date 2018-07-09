#include"TimeLimit.h"
#include"Font.h"
#include"Utility.h"

TimeLimit::TimeLimit(std::function<void(SceneBase::SCENE_ID)> function,int limits)
	: m_Function(function),m_Pos(70,50),m_Limits(limits)
{
	DirectGraphics::GetpInstance()->InitGraphics("Texture/UI.png");
	DirectGraphics::GetpInstance()->InitGraphics("Texture/frame03.png");
}


TimeLimit::~TimeLimit()
{
}

void TimeLimit::Draw() 
{
	CUSTOMVERTEX  LimitBackVertex[4]{
	{                                               18,                                            14, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  0.f },
	{ Font::GetpInstance().GetSize()->m_Width * 3 + 50,                                            14, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.f },
	{ Font::GetpInstance().GetSize()->m_Width * 3 + 50, Font::GetpInstance().GetSize()->m_Height + 26, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{                                               18, Font::GetpInstance().GetSize()->m_Height + 26, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  1.0f }
	};
	CUSTOMVERTEX vertex[] = {
	{ m_Pos.x - Font::GetpInstance().GetSize()->m_Width / 2,m_Pos.y - Font::GetpInstance().GetSize()->m_Height / 2,1.0,1.0,0xffffffff,0.0f,0.0f },
	{ m_Pos.x + Font::GetpInstance().GetSize()->m_Width / 2,m_Pos.y - Font::GetpInstance().GetSize()->m_Height / 2,1.0,1.0,0xffffffff,1.0f,0.0f },
	{ m_Pos.x + Font::GetpInstance().GetSize()->m_Width / 2,m_Pos.y + Font::GetpInstance().GetSize()->m_Height / 2,1.0,1.0,0xffffffff,1.0f,1.0f },
	{ m_Pos.x - Font::GetpInstance().GetSize()->m_Width / 2,m_Pos.y + Font::GetpInstance().GetSize()->m_Height / 2,1.0,1.0,0xffffffff,0.0f,1.0f }
	};
	DirectGraphics::GetpInstance()->Render("Texture/frame03.png", LimitBackVertex);
	if (m_Limits >= 0) {
		////百の位表示
		{
			int hundredsPlace = m_Limits / 100;
			Font::GetpInstance().GetUV(Utility::TransformChar(hundredsPlace), vertex);
			DirectGraphics::GetpInstance()->Render("Texture/UI.png", vertex);
			NextCharPos(vertex);
		}
		//十の位表示
		{
			int tensPlace = (m_Limits / 10) % 10;
			Font::GetpInstance().GetUV(Utility::TransformChar(tensPlace), vertex);
			DirectGraphics::GetpInstance()->Render("Texture/UI.png", vertex);
			NextCharPos(vertex);
		}

		//一の位表示
		{
			int onesPlace = m_Limits % 10;
			Font::GetpInstance().GetUV(Utility::TransformChar(onesPlace), vertex);
			DirectGraphics::GetpInstance()->Render("Texture/UI.png", vertex);
		}
	}
}

void TimeLimit::Update()
{
	++m_FrCnt;
	if (m_FrCnt == 60) {
		m_FrCnt = 0;
		--m_Limits;
	}
	if (m_Limits == 0) {
		m_Function(SceneBase::SCENE_ID::GAMEOVER);
	}

}

void TimeLimit::NextCharPos(CUSTOMVERTEX vertex[])
{
	for (int i = 0; i < 4; ++i) {
		vertex[i].x += Font::GetpInstance().GetSize()->m_Width;
	}
}