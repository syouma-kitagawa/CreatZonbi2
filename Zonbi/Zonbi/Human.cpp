#include"Human.h"
#include"Utility.h"
#include"DirectGraphics.h"

Human::Human(D3DXVECTOR2 pos): m_Pos(pos),m_IsDeath(false)
{
	m_Collision = new Collision();
	m_Collision->SetPosition(m_Pos);
	m_Collision->SetSize(D3DXVECTOR2(HUMAN_W * 2 - HUMAN_W, HUMAN_H * 2 - HUMAN_H));
	m_Collision->SetCollisionId(Collision::HUMAN);
	CollisionManager::GetcollisionManager()->AddCollision(m_Collision);
	DirectGraphics::GetpInstance()->InitGraphics("Texture/normal.png");
}


Human::~Human()
{
	delete m_Collision;
}

void Human::Draw()
{
	CUSTOMVERTEX HumanDraw[4];
	static CUSTOMVERTEX  HumanVertex[4]{
		{ -HUMAN_W, -HUMAN_H, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  0.f },
		{  HUMAN_W, -HUMAN_H, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.f },
		{  HUMAN_W,  HUMAN_H, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ -HUMAN_W,  HUMAN_H, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  1.0f }
	};
	//à íuÇ∆í∏ì_èÓïÒÇë„ì¸
	for (int i = 0; i < 4; i++) {
		HumanDraw[i] = HumanVertex[i];
		HumanDraw[i].x += m_Pos.x;
		HumanDraw[i].y += m_Pos.y;
	}
	DirectGraphics::GetpInstance()->Render("Texture/normal.png", HumanDraw);
}

void Human::Update()
{
	if (m_Collision->GetOtherCollisionId() == (Collision::ZOMBIE)) {
		m_IsDeath = true;
	}
	m_Collision->SetPosition(m_Pos);
}