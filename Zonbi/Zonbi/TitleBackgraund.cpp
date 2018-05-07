#include"TitleBackgraund.h"
#include"DirectGraphics.h"
#include"Event.h"

TitleBackgraund::TitleBackgraund()
{
}


TitleBackgraund::~TitleBackgraund()
{
}

void TitleBackgraund::Draw()
{
	CUSTOMVERTEX  TitleDraw[4]{
		{ -DISPLAY_WIDTH / 2, -DISPLAY_HEIGHT / 2, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  0.f },
		{  DISPLAY_WIDTH / 2, -DISPLAY_HEIGHT / 2, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.f },
		{  DISPLAY_WIDTH / 2,  DISPLAY_HEIGHT / 2, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ -DISPLAY_WIDTH / 2,  DISPLAY_HEIGHT / 2, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  1.0f }
	};
	DirectGraphics::GetpInstance()->Render("Texture/normal.png", TitleDraw);
}