#include"GameBackground.h"
#include"DirectGraphics.h"
#include"Event.h"

GameBackground::GameBackground()
{
	DirectGraphics::GetpInstance()->InitGraphics("Texture/BackGround.png");
	DirectGraphics::GetpInstance()->InitGraphics("Texture/wall.png");
}


GameBackground::~GameBackground()
{
}

void GameBackground::Draw()
{
	CUSTOMVERTEX GameBackgroundVertex[4]{
	{ 0             ,0             , 1.0f, 1.0f, 0xFFFFFFFF, 0.f , 0.f },
	{ DISPLAY_WIDTH ,0             , 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.f },
	{ DISPLAY_WIDTH ,DISPLAY_HEIGHT, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f,1.0f },
	{ 0             ,DISPLAY_HEIGHT, 1.0f, 1.0f, 0xFFFFFFFF, 0.f ,1.0f }
	};
	DirectGraphics::GetpInstance()->Render("Texture/BackGround.png", GameBackgroundVertex);
}

void GameBackground::WallDraw() 
{
	CUSTOMVERTEX WallVertex[4]{
	{ 0             ,0             , 1.0f, 1.0f, 0xFFFFFFFF, 0.f , 0.f },
	{ DISPLAY_WIDTH ,0             , 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.f },
	{ DISPLAY_WIDTH ,DISPLAY_HEIGHT, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f,1.0f },
	{ 0             ,DISPLAY_HEIGHT, 1.0f, 1.0f, 0xFFFFFFFF, 0.f ,1.0f }
	};
	DirectGraphics::GetpInstance()->Render("Texture/wall.png", WallVertex);
}