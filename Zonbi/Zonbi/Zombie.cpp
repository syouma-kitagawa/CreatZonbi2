#include"Zombie.h"
#include"PlayerControl.h"
#include"DirectGraphics.h"
#include"DirectInput.h"
#include"Event.h"


Zombie::Zombie(D3DXVECTOR2* pos,float speed, int width, int height) 
	: m_Pos(*pos), m_Speed(speed),m_Width(width),m_Height(height),m_NextPos(*pos),m_BeforePos(*pos)
{
	m_pCollision = new Collision();
	m_pCollision->SetPosition(&m_Pos);
	m_pCollision->SetSize(&D3DXVECTOR2(m_Width * 2 - m_Width, m_Height * 2 - m_Height));
	m_pCollision->SetCollisionId(Collision::ZOMBIE);
	CollisionManager::GetcollisionManager()->AddCollision(m_pCollision);

	for (int i = 0; i < 4; i++) {
		m_pTmpCollision[i] = new Collision();
		m_pTmpCollision[i]->SetPosition(&m_CollisionPos[i]);
		m_pTmpCollision[i]->SetSize(&D3DXVECTOR2(1, 1));
		m_pTmpCollision[i]->SetCollisionId(Collision::ZOMBIE);
		CollisionManager::GetcollisionManager()->AddCollision(m_pTmpCollision[i]);
		DirectGraphics::GetpInstance()->InitGraphics("Texture/combine.png");
	}
}

Zombie::~Zombie()
{
	delete m_pCollision;
}

void Zombie::Draw() 
{
	CUSTOMVERTEX ZombieDraw[4];
	CUSTOMVERTEX  ZombieVertex[4]{
		{ -m_Width / 2.0f, -m_Height / 2.0f, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  0.f },
		{  m_Width / 2.0f, -m_Height / 2.0f, 1.0f, 1.0f, 0xFFFFFFFF, m_Tu, 0.f },
		{  m_Width / 2.0f,  m_Height / 2.0f, 1.0f, 1.0f, 0xFFFFFFFF, m_Tu, m_Tv },
		{ -m_Width / 2.0f,  m_Height / 2.0f, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  m_Tv }
	};
	//à íuÇ∆í∏ì_èÓïÒÇë„ì¸
	for (int i = 0; i < 4; i++) {
		ZombieDraw[i] = ZombieVertex[i];
		ZombieDraw[i].x += m_Pos.x;
		ZombieDraw[i].y += m_Pos.y;
	}
	int remainder = m_Fcnt % 60;

	if (m_BeforePos == m_Pos) {
		switch (m_Direction)
		{
		case Direction::UP:
			DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 1, m_Tv, 4);
			DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			break;
		case Direction::DOWN:
			DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 0, m_Tv, 4);
			DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			break;
		case Direction::RIGHT:
			DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 3, m_Tv, 4);
			DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			break;
		case Direction::LEFT:
			DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 2, m_Tv, 4);
			DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			break;
		}
	}
	else {
		switch (m_Direction)
		{
		case Direction::UP:

			if (remainder <= 29) {
				DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 2, m_Tv, 4);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			else if (remainder >= 30 && remainder <= 59) {
				DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 3, m_Tv, 4);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			break;
		case Direction::DOWN:
			if (remainder <= 29) {
				DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 0, m_Tv, 4);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			else if (remainder >= 30 && remainder <= 59) {
				DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 1, m_Tv, 4);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			break;
		case Direction::RIGHT:
			if (remainder <= 29) {
				DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 6, m_Tv, 4);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			else if (remainder >= 30 && remainder <= 59) {
				DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 7, m_Tv, 4);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			break;
		case Direction::LEFT:
			if (remainder <= 29) {
				DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 4, m_Tv, 4);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			else if (remainder >= 30 && remainder <= 59) {
				DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 5, m_Tv, 4);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			break;
		}
	}
	if (m_Fcnt != 60) {
		m_Fcnt++;
	}
	else {
		m_Fcnt = 0;
	}
}
void Zombie::Update()
{
	m_CollisionPos[0].x = m_Pos.x;
	m_CollisionPos[0].y = m_Pos.y - m_Speed;
	m_CollisionPos[1].x = m_Pos.x;
	m_CollisionPos[1].y = m_Pos.y + m_Speed;
	m_CollisionPos[2].x = m_Pos.x + m_Speed;
	m_CollisionPos[2].y = m_Pos.y;
	m_CollisionPos[3].x = m_Pos.x - m_Speed;
	m_CollisionPos[3].y = m_Pos.y;

	if (DirectInput::GetInstance().GetMouseData()->RightMouse == Utility::BUTTON_STATE::PUSH){
		m_Fcnt = 0;
		Event::GetInstance()->GetMousePosPointToVector2(&m_NextPos);
		m_Difference.x = m_NextPos.x - m_Pos.x;
		m_Difference.y = m_NextPos.y - m_Pos.y;
	}
	if (m_Difference.y > 0) {
		if (m_Pos.y + m_Speed < m_NextPos.y
			&& !m_pTmpCollision[1]->IsSearchOtherCollisionId(m_pTmpCollision[1]->GetOtherCollisionId(), Collision::OBJECT)) {
			m_Pos.y += m_Speed;
			m_Direction = DOWN;
		}
		else if (m_Pos.x + m_Speed < m_NextPos.x
			&& !m_pTmpCollision[1]->IsSearchOtherCollisionId(m_pTmpCollision[2]->GetOtherCollisionId(), Collision::OBJECT)) {
			m_Pos.x += m_Speed;
			m_Direction = RIGHT;
		}

		else if (m_Pos.x - m_Speed > m_NextPos.x
			&& !m_pTmpCollision[1]->IsSearchOtherCollisionId(m_pTmpCollision[3]->GetOtherCollisionId(), Collision::OBJECT)) {
			m_Pos.x -= m_Speed;
			m_Direction = LEFT;
		}
	}
	else if (m_Difference.y < 0) {
		if (m_Pos.y - m_Speed > m_NextPos.y
			&& !m_pTmpCollision[1]->IsSearchOtherCollisionId(m_pTmpCollision[0]->GetOtherCollisionId(), Collision::OBJECT)) {
			m_Pos.y -= m_Speed;
			m_Direction = UP;
		}
		else if (m_Pos.x - m_Speed > m_NextPos.x
			&& !m_pTmpCollision[1]->IsSearchOtherCollisionId(m_pTmpCollision[3]->GetOtherCollisionId(), Collision::OBJECT)) {
			m_Pos.x -= m_Speed;
			m_Direction = LEFT;
		}
		else if (m_Pos.x + m_Speed < m_NextPos.x
			&& !m_pTmpCollision[1]->IsSearchOtherCollisionId(m_pTmpCollision[2]->GetOtherCollisionId(), Collision::OBJECT)) {
			m_Pos.x += m_Speed;
			m_Direction = RIGHT;
		}
	}
	//Ç«Ç±Ç…à⁄ìÆÇ∑ÇÈîªíËÇ∆Ç±ÇÍÇ©ÇÁå¸Ç≠å¸Ç´
	/*if (m_pCollision->GetOtherCollisionId() != (Collision::ZOMBIE)) {

		if (m_Pos.y < m_NextPos.y - kMargin && !DirectionCheack(UP)) {
			m_Pos.y += m_Speed;
			m_Direction = UP;
			ResetArray();
		}
		else if (m_Pos.y > m_NextPos.y - kMargin && !DirectionCheack(DOWN)) {
			m_Pos.y -= m_Speed;
			m_Direction = DOWN;
			ResetArray();
		}
		else if (m_Pos.x < m_NextPos.x - kMargin && !DirectionCheack(RIGHT)) {
			m_Pos.x += m_Speed;
			m_Direction = RIGHT;
			ResetArray();
		}
		else if (m_Pos.x > m_NextPos.x + kMargin && !DirectionCheack(LEFT)) {
			m_Pos.x -= m_Speed;
			m_Direction = LEFT;
			ResetArray();
		}
	}
	if (m_pCollision->GetOtherCollisionId() == Collision::OBJECT) {
		switch (m_Direction)
		{
		case UP:
			m_Pos.y += -m_Speed;
			m_Direction = UP;
			break;
		case DOWN:
			m_Pos.y += m_Speed;
			m_Direction = DOWN;
			break;
		case RIGHT:
			m_Pos.x += -m_Speed;
			m_Direction = RIGHT;
			break;
		case LEFT:
			m_Pos.x += m_Speed;
			m_Direction = LEFT;
			break;
		}
	}*/
	for (int i = 0; i < 4; i++) {
	m_pTmpCollision[i]->SetPosition(&m_CollisionPos[i]);
	}
	m_pCollision->SetPosition(&m_Pos);
}

bool Zombie::DirectionCheack(Direction direction)
{
	for (int i = 0; i < 4; i++) {
		m_CollisionDir[i] = direction;
		return true;
	}
	return false;
}

void Zombie::ResetArray()
{
	for (int i = 0; i < 4; i++) {
		m_CollisionDir[i] = Direction::NON;
	}
}