#include"Zonbi.h"
#include"Player.h"
#include"DirectGraphics.h"
#include"DirectInput.h"
#include"Event.h"


Zonbi::Zonbi(D3DXVECTOR2 pos) : m_Pos(pos)
{
	m_Collision = new Collision();
	m_Collision->SetPosition(m_Pos);
	m_Collision->SetSize(D3DXVECTOR2(ZONBI_W * 2 - ZONBI_W, ZONBI_H * 2 - ZONBI_H));
	m_Collision->SetCollisionId(Collision::ZONBI);
	CollisionManager::GetcollisionManager()->AddCollision(m_Collision);
	DirectGraphics::GetpInstance()->InitGraphics("Texture/player.png", &m_ZonbiTexture);
}


Zonbi::~Zonbi()
{
	delete m_Collision;
}

void Zonbi::Draw() {
	CUSTOMVERTEX ZonbiDraw[4];
	static CUSTOMVERTEX  ZonbiVertex[4]{
		{ -ZONBI_W, -ZONBI_H, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  0.f },
		{  ZONBI_W, -ZONBI_H, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.f },
		{  ZONBI_W,  ZONBI_H, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ -ZONBI_W,  ZONBI_H, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  1.0f }
	};
	//à íuÇ∆í∏ì_èÓïÒÇë„ì¸
	for (int i = 0; i < 4; i++) {
		ZonbiDraw[i] = ZonbiVertex[i];
		ZonbiDraw[i].x += m_Pos.x;
		ZonbiDraw[i].y += m_Pos.y;
	}
	DirectGraphics::GetpInstance()->Render(&m_ZonbiTexture, ZonbiDraw);
}
void Zonbi::Update()
{
	double radian;
	DirectInput::GetInstance().UpdateMouse();
	if (DirectInput::GetInstance().GetMouseData()->LeftMouse == Utility::BUTTON_STATE::PUSH){
		m_MoveZonbi = true;
		m_NextPos = Event::GetInstance()->GetMousePosPointToVector2();
	}
	if (m_MoveZonbi == true) {
		radian = atan2(m_NextPos.y - m_Pos.y, m_NextPos.x - m_Pos.x);

		m_Pos.x += cos(radian) * ZONBI_SPEED;
		m_Pos.y += sin(radian) * ZONBI_SPEED;
		if (m_Pos.x < m_NextPos.x + 10.f
			&&m_Pos.x > m_NextPos.x - 10.f
			&&m_Pos.y < m_NextPos.y + 10.f
			&&m_Pos.y > m_NextPos.y - 10.f) {
			m_MoveZonbi = false;
		}
	}
	m_Collision->SetPosition(m_Pos);
}