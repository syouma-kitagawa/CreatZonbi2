#include"Zombie.h"
#include"Player.h"
#include"DirectGraphics.h"
#include"DirectInput.h"
#include"Event.h"


Zombie::Zombie(D3DXVECTOR2 pos) : m_Pos(pos)
{
	m_Collision = new Collision();
	m_Collision->SetPosition(m_Pos);
	m_Collision->SetSize(D3DXVECTOR2(ZOMBIE_W * 2 - ZOMBIE_W, ZOMBIE_H * 2 - ZOMBIE_H));
	m_Collision->SetCollisionId(Collision::ZOMBIE);
	CollisionManager::GetcollisionManager()->AddCollision(m_Collision);
	DirectGraphics::GetpInstance()->InitGraphics("Texture/player.png");
}


Zombie::~Zombie()
{
	delete m_Collision;
}

void Zombie::Draw() {
	CUSTOMVERTEX ZombieDraw[4];
	static CUSTOMVERTEX  ZombieVertex[4]{
		{ -ZOMBIE_W / 2, -ZOMBIE_H / 2, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  0.f },
		{  ZOMBIE_W / 2, -ZOMBIE_H / 2, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.f },
		{  ZOMBIE_W / 2,  ZOMBIE_H / 2, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
		{ -ZOMBIE_W / 2,  ZOMBIE_H / 2, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  1.0f }
	};
	//à íuÇ∆í∏ì_èÓïÒÇë„ì¸
	for (int i = 0; i < 4; i++) {
		ZombieDraw[i] = ZombieVertex[i];
		ZombieDraw[i].x += m_Pos.x;
		ZombieDraw[i].y += m_Pos.y;
	}
	DirectGraphics::GetpInstance()->Render("Texture/player.png", ZombieDraw);
}
void Zombie::Update()
{
	double radian;
	if (DirectInput::GetInstance().GetMouseData()->LeftMouse == Utility::BUTTON_STATE::PUSH){
		m_MoveZombie = true;
		m_NextPos = Event::GetInstance()->GetMousePosPointToVector2();
	}
	if (m_MoveZombie == true) {
		radian = atan2(m_NextPos.y - m_Pos.y, m_NextPos.x - m_Pos.x);

		m_Pos.x += cos(radian) * ZOMBIE_SPEED;
		m_Pos.y += sin(radian) * ZOMBIE_SPEED;
		if (m_Pos.x < m_NextPos.x + 10.f
			&&m_Pos.x > m_NextPos.x - 10.f
			&&m_Pos.y < m_NextPos.y + 10.f
			&&m_Pos.y > m_NextPos.y - 10.f) {
			m_MoveZombie = false;
		}
	}
	m_Collision->SetPosition(m_Pos);
}