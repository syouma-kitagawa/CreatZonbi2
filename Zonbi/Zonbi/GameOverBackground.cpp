#include"GameOverBackground.h"
#include"DirectGraphics.h"
#include"Event.h"

GameOverBackground::GameOverBackground()
{
	DirectGraphics::GetpInstance()->InitGraphics("Texture/over.png");
}


GameOverBackground::~GameOverBackground()
{
}

void GameOverBackground::Draw()
{
	CUSTOMVERTEX  GameOverDraw[4]{
	{ 0,                           0, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  0.f },
	{ DISPLAY_WIDTH,              0, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.f },
	{ DISPLAY_WIDTH, DISPLAY_HEIGHT, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{ 0             , DISPLAY_HEIGHT, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  1.0f }
	};
	DirectGraphics::GetpInstance()->Render("Texture/over.png", GameOverDraw);
}