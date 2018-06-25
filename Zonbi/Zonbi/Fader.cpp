#include"Fader.h"
#include"DirectGraphics.h"
#include"Event.h"

Fader::Fader(int frmMax) : m_FrmMax(frmMax)
{
	DirectGraphics::GetpInstance()->InitGraphics("Texture/Black.png");
	m_AlphaIncAmount = 1.0f / m_FrmMax;
}

Fader::~Fader()
{
}

void Fader::Draw()
{
	D3DXCOLOR color;
	color.r = 1.0f;
	color.g = 1.0f;
	color.b = 1.0f;
	color.a = m_Alpha;
	CUSTOMVERTEX BlackBoardDraw[4]{
		{ 0,                          0, 0.0f, 1.0f, color, 0.f,  0.f },
		{ DISPLAY_WIDTH,              0, 0.0f, 1.0f, color, 1.0f, 0.f },
		{ DISPLAY_WIDTH, DISPLAY_HEIGHT, 0.0f, 1.0f, color, 1.0f, 1.0f },
		{ 0            , DISPLAY_HEIGHT, 0.0f, 1.0f, color, 0.f,  1.0f }
	};
	DirectGraphics::GetpInstance()->Render("Texture/Black.png", BlackBoardDraw);
}

void Fader::Update()
{
}
void Fader::FadeIn() 
{
	if (!m_FadeFinish) {
		if (m_FrmCnt == m_FrmMax) {
			m_FadeFinish = true;
			m_FrmCnt = 0;
		}
		else {
			m_AlphaIn -= m_AlphaIncAmount;
			m_Alpha = m_AlphaIn;
			m_FrmCnt++;
		}
	}
}
void Fader::FadeOut()
{
	if (!m_FadeFinish) {
		if (m_FrmCnt == m_FrmMax) {
			m_FadeFinish = true;
			m_FrmCnt = 0;
		}
		else {
			m_AlphaOut += m_AlphaIncAmount;
			m_Alpha = m_AlphaOut;
			m_FrmCnt++;
		}
	}
}