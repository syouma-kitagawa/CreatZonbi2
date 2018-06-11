#include"PlayerZombie.h"
#include"PlayerControl.h"
#include"DirectGraphics.h"
#include"DirectInput.h"
#include"Event.h"
#include"WayPointManager.h"



PlayerZombie::PlayerZombie(D3DXVECTOR2* pos,float speed,int width,int height)
	: m_Pos(*pos), m_Speed(speed), m_Width(width),m_Height(height), m_NextPos(*pos),m_BeforePos(*pos)
{
	m_pCollision = new Collision();
	m_pCollision->SetPosition(&m_Pos);
	m_pCollision->SetSize(&D3DXVECTOR2(m_Width * 2 - m_Width, m_Height * 2 - m_Height));
	m_pCollision->SetCollisionId(Collision::ZOMBIE);
	CollisionManager::GetcollisionManager()->AddCollision(m_pCollision);
	DirectGraphics::GetpInstance()->InitGraphics("Texture/combine.png");


	for (int i = 0; i < 4; i++) {
		m_pTmpCollision[i] = new Collision();
		m_pTmpCollision[i]->SetPosition(&m_CollisionPos[i]);
		m_pTmpCollision[i]->SetSize(&D3DXVECTOR2(1,1));
		m_pTmpCollision[i]->SetCollisionId(Collision::ZOMBIE);
		CollisionManager::GetcollisionManager()->AddCollision(m_pTmpCollision[i]);
	}
}


PlayerZombie::~PlayerZombie()
{
	delete m_pCollision;
}

void PlayerZombie::Draw() 
{
	CUSTOMVERTEX ZombieDraw[4];
	CUSTOMVERTEX  ZombieVertex[4]{
		{ -m_Width / 2, -m_Height / 2, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  0.f },
		{  m_Width / 2, -m_Height / 2, 1.0f, 1.0f, 0xFFFFFFFF, m_Tu, 0.f },
		{  m_Width / 2,  m_Height / 2, 1.0f, 1.0f, 0xFFFFFFFF, m_Tu, m_Tv },
		{ -m_Width / 2,  m_Height / 2, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  m_Tv }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++) {
		ZombieDraw[i] = ZombieVertex[i];
		ZombieDraw[i].x += m_Pos.x;
		ZombieDraw[i].y += m_Pos.y;
	}
	int remainder = m_Fcnt % 60;

	if (m_IsAttack) {

		//位置と頂点情報を代入
		for (int i = 0; i < 4; i++) {
			ZombieDraw[i].tu = 0.0f;
			ZombieDraw[i].tv = 0.0f;
		}
		switch (m_Direction)
		{
		case Direction::UP:
			if (remainder <= 29) {
				DirectGraphics::GetpInstance()->TrimingVertex(ZombieDraw, 108, 228, 54, 108, 2048, 2048);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			else if (remainder >= 30 && remainder <= 59) {
				DirectGraphics::GetpInstance()->TrimingVertex(ZombieDraw, 162, 228, 54, 108, 2048, 2048);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			m_IsAttack = false;
			break;
		case Direction::DOWN:
			if (remainder <= 29) {
				DirectGraphics::GetpInstance()->TrimingVertex(ZombieDraw, 0, 228, 54, 108, 2048, 2048);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			else if (remainder >= 30 && remainder <= 59) {
				DirectGraphics::GetpInstance()->TrimingVertex(ZombieDraw, 54, 228, 54, 108, 2048, 2048);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			m_IsAttack = false;
			break;
		case Direction::RIGHT:
			if (remainder <= 29) {
				DirectGraphics::GetpInstance()->TrimingVertex(ZombieDraw, 324, 228, 54, 108, 2048, 2048);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			else if (remainder >= 30 && remainder <= 59) {
				DirectGraphics::GetpInstance()->TrimingVertex(ZombieDraw, 378, 228, 54, 108, 2048, 2048);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			m_IsAttack = false;
			break;
		case Direction::LEFT:
			if (remainder <= 29) {
				DirectGraphics::GetpInstance()->TrimingVertex(ZombieDraw, 216, 228, 54, 108, 2048, 2048);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
			}
			else if (remainder >= 30 && remainder <= 59) {
				DirectGraphics::GetpInstance()->TrimingVertex(ZombieDraw, 270, 228, 54, 108, 2048, 2048);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
				m_IsAttack = false;
			}
			break;
		}
	}
	else {
		if (m_BeforePos == m_Pos) {
			switch (m_Direction)
			{
			case Direction::UP:
				DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 3, m_Tv, 0);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
				break;
			case Direction::DOWN:
				DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 0, m_Tv, 0);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
				break;
			case Direction::RIGHT:
				DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 9, m_Tv, 0);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
				break;
			case Direction::LEFT:
				DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 6, m_Tv, 0);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
				break;
			}
		}
		else {
			switch (m_Direction)
			{
			case Direction::UP:
				if (remainder <= 29) {
					DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 4, m_Tv, 0);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
				}
				else if (remainder >= 30 && remainder <= 59) {
					DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 5, m_Tv, 0);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
				}
				break;
			case Direction::DOWN:
				if (remainder <= 29) {
					DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 1, m_Tv, 0);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
				}
				else if (remainder >= 30 && remainder <= 59) {
					DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 2, m_Tv, 0);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
				}
				break;
			case Direction::RIGHT:
				if (remainder <= 29) {
					DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 10, m_Tv, 0);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
				}
				else if (remainder >= 30 && remainder <= 59) {
					DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 11, m_Tv, 0);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
				}
				break;
			case Direction::LEFT:
				if (remainder <= 29) {
					DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 7, m_Tv, 0);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
				}
				else if (remainder >= 30 && remainder <= 59) {
					DirectGraphics::GetpInstance()->Animation(ZombieDraw, m_Tu, 8, m_Tv, 0);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", ZombieDraw);
				}
				break;
			}
		}
	}
	if (m_Fcnt != 60) {
		m_Fcnt++;
	}
	else {
		m_Fcnt = 0;
	}
}

void PlayerZombie::Update()
{
	m_BeforePos = m_Pos;
	m_CollisionPos[0].x = m_Pos.x;
	m_CollisionPos[0].y = m_Pos.y - m_Speed;
	m_CollisionPos[1].x = m_Pos.x;
	m_CollisionPos[1].y = m_Pos.y + m_Speed;
	m_CollisionPos[2].x = m_Pos.x + m_Speed;
	m_CollisionPos[2].y = m_Pos.y;
	m_CollisionPos[3].x = m_Pos.x - m_Speed;
	m_CollisionPos[3].y = m_Pos.y;

	if (m_pCollision->GetOtherCollisionId() == Collision::HUMAN) {
		m_IsAttack = true;
	}

	if (DirectInput::GetInstance().GetMouseData()->LeftMouse == Utility::BUTTON_STATE::PUSH) {
		m_Fcnt = 0;
		*Event::GetInstance()->GetMousePosPointToVector2(&m_NextPos);
		m_Difference.x = m_NextPos.x - m_Pos.x;
		m_Difference.y = m_NextPos.y - m_Pos.y;
		/*m_ClickRoomId = WayPointManager::GetpInstance()->CurrentRoom(&m_NextPos);
		m_RoomId = WayPointManager::GetpInstance()->CurrentRoom(&m_Pos);
		if (m_ClickRoomId != m_RoomId || m_ClickRoomId == -1 && m_RoomId == -1) {
			m_ClickRoomId = WayPointManager::GetpInstance()->CurrentWayPoint(&m_NextPos);
			m_RoomId = WayPointManager::GetpInstance()->CurrentWayPoint(&m_Pos);
			WayPointManager::GetpInstance()->RouteSearch(m_RoomId, m_ClickRoomId);
		}
		else {
			m_SameRoom = true;
		}
		m_RoutePointNum = 0;*/
		//m_IsClick = true;
	}

	if (m_Difference.x > 0) {
		if (m_Pos.y + m_Speed <= m_NextPos.y && m_pTmpCollision[1]->GetOtherCollisionId() != Collision::OBJECT) {
			m_Pos.y += m_Speed;
			m_Direction = DOWN;
		}
		else if (m_Pos.x + m_Speed < m_NextPos.x && m_pTmpCollision[2]->GetOtherCollisionId() != Collision::OBJECT) {
			m_Pos.x += m_Speed;
			m_Direction = RIGHT;
		}
		else if (m_Pos.x - m_Speed > m_NextPos.x && m_pTmpCollision[3]->GetOtherCollisionId() != Collision::OBJECT) {
			m_Pos.x -= m_Speed;
			m_Direction = LEFT;
		}
	}
	else if (m_Difference.y < 0) {
		if (m_Pos.y - m_Speed > m_NextPos.y && m_pTmpCollision[0]->GetOtherCollisionId() != Collision::OBJECT) {
			m_Pos.y -= m_Speed;
			m_Direction = UP;
		}
		else if (m_Pos.x - m_Speed > m_NextPos.x && m_pTmpCollision[3]->GetOtherCollisionId() != Collision::OBJECT) {
			m_Pos.x -= m_Speed;
			m_Direction = LEFT;
		}
		else if (m_Pos.x + m_Speed < m_NextPos.x && m_pTmpCollision[2]->GetOtherCollisionId() != Collision::OBJECT) {
			m_Pos.x += m_Speed;
			m_Direction = RIGHT;
		}
	}
	/*if (m_Difference.y > 0) {
		if (m_Pos.y < m_NextPos.y - kMargin && m_pTmpCollision[0]->GetOtherCollisionId() != Collision::OBJECT) {
			m_Pos.y += m_Speed;
			m_Direction = DOWN;
		}else if (m_Pos.x < m_NextPos.x - kMargin && m_pTmpCollision[2]->GetOtherCollisionId() != Collision::OBJECT) {
			m_Pos.x += m_Speed;
			m_Direction = RIGHT;
		}
		else if (m_Pos.x > m_NextPos.x + kMargin && m_pTmpCollision[3]->GetOtherCollisionId() != Collision::OBJECT) {
			m_Pos.x += -m_Speed;
			m_Direction = LEFT;
		}
	}
	else if (m_Difference.y < 0) {
		if (m_Pos.y > m_NextPos.y + kMargin && m_pTmpCollision[1]->GetOtherCollisionId() != Collision::OBJECT) {
			m_Pos.y += - m_Speed;
			m_Direction = UP;
		}
		else if (m_Pos.x > m_NextPos.x + kMargin && m_pTmpCollision[3]->GetOtherCollisionId() != Collision::OBJECT) {
			m_Pos.x += -m_Speed;
			m_Direction = LEFT;
		}
		else if (m_Pos.x < m_NextPos.x - kMargin && m_pTmpCollision[2]->GetOtherCollisionId() != Collision::OBJECT) {
			m_Pos.x += m_Speed;
			m_Direction = RIGHT;
		}
	}*/
	//if (m_IsClick) {
	//	if (m_SameRoom) {
	//			if (m_Pos.y <
	//				m_NextPos.y - kMargin && !DirectionCheck(UP)) {
	//				m_Pos.y += m_Speed;
	//				m_Direction = UP;
	//				collisionDircnt = 0;
	//				ResetArray();
	//			}
	//			else if (m_Pos.y >
	//				m_NextPos.y - kMargin && !DirectionCheck(DOWN)) {
	//				m_Pos.y -= m_Speed;
	//				m_Direction = DOWN;
	//				collisionDircnt = 0;
	//				ResetArray();
	//			}
	//			else if (m_Pos.x <
	//				m_NextPos.x - kMargin && !DirectionCheck(RIGHT)) {
	//				m_Pos.x += m_Speed;
	//				m_Direction = RIGHT;
	//				collisionDircnt = 0;
	//				ResetArray();
	//			}
	//			else if (m_Pos.x >
	//				m_NextPos.x + kMargin && !DirectionCheck(LEFT)) {
	//				m_Pos.x -= m_Speed;
	//				m_Direction = LEFT;
	//				collisionDircnt = 0;
	//				ResetArray();
	//			}

	//	}else if (WayPointManager::GetpInstance()->GetRoutes()[m_RoutePointNum]->GetRoute() != WayPointBase::END) {
	//		//どこに移動する判定とこれから向く向き
	//		D3DXVECTOR2 pos;
	//		pos.x = WayPointManager::GetpInstance()->GetRoutes()[m_RoutePointNum]->GetPlace().Pos.x;
	//		pos.y = WayPointManager::GetpInstance()->GetRoutes()[m_RoutePointNum]->GetPlace().Pos.y;
	//		if (m_Pos.y <
	//			WayPointManager::GetpInstance()->GetRoutes()[m_RoutePointNum]->GetPlace().Pos.y - kMargin
	//			&& m_pCollision->GetOtherCollisionId() != (Collision::ZOMBIE) && !DirectionCheck(UP)) {
	//			m_Pos.y += m_Speed;
	//			m_Direction = UP;
	//			ResetArray();
	//		}
	//		else if (m_Pos.y >
	//			WayPointManager::GetpInstance()->GetRoutes()[m_RoutePointNum]->GetPlace().Pos.y - kMargin
	//			&& m_pCollision->GetOtherCollisionId() != (Collision::ZOMBIE) && DirectionCheck(DOWN)) {
	//			m_Pos.y -= m_Speed;
	//			m_Direction = DOWN;
	//			ResetArray();
	//		}
	//		else if (m_Pos.x <
	//			WayPointManager::GetpInstance()->GetRoutes()[m_RoutePointNum]->GetPlace().Pos.x - kMargin
	//			&& m_pCollision->GetOtherCollisionId() != (Collision::ZOMBIE) && DirectionCheck(RIGHT)) {
	//			m_Pos.x += m_Speed;
	//			m_Direction = RIGHT;
	//			ResetArray();
	//		}
	//		else if (m_Pos.x >
	//			WayPointManager::GetpInstance()->GetRoutes()[m_RoutePointNum]->GetPlace().Pos.x + kMargin
	//			&& m_pCollision->GetOtherCollisionId() != (Collision::ZOMBIE) && DirectionCheck(LEFT)) {
	//			m_Pos.x -= m_Speed;
	//			m_Direction = LEFT;
	//			ResetArray();
	//		}
	//		if (m_Pos.x <
	//			WayPointManager::GetpInstance()->GetRoutes()[m_RoutePointNum]->GetPlace().Pos.x - kMargin
	//			&& m_Pos.x >
	//			WayPointManager::GetpInstance()->GetRoutes()[m_RoutePointNum]->GetPlace().Pos.x + kMargin
	//			&& m_Pos.y <
	//			WayPointManager::GetpInstance()->GetRoutes()[m_RoutePointNum]->GetPlace().Pos.y - kMargin
	//			&& m_Pos.y >
	//			WayPointManager::GetpInstance()->GetRoutes()[m_RoutePointNum]->GetPlace().Pos.y - kMargin) {
	//			m_RoutePointNum++;
	//		}
	//	}
	//}
	//if (m_pCollision->GetOtherCollisionId() == Collision::OBJECT) {
	//	switch (m_Direction)
	//	{
	//	case UP:
	//		m_Pos.y += -m_Speed;
	//		m_Direction = UP;
	//		m_CollisionDir[collisionDircnt] = UP;
	//		collisionDircnt++;
	//		break;
	//	case DOWN:
	//		m_Pos.y += m_Speed;
	//		m_Direction = DOWN;
	//		m_CollisionDir[collisionDircnt] = DOWN;
	//		collisionDircnt++;
	//		break;
	//	case RIGHT:
	//		m_Pos.x += -m_Speed;
	//		m_Direction = RIGHT;
	//		m_CollisionDir[collisionDircnt] = RIGHT;
	//		collisionDircnt++;
	//		break;
	//	case LEFT:
	//		m_Pos.x += m_Speed;
	//		m_Direction = LEFT;
	//		m_CollisionDir[collisionDircnt] = LEFT;
	//		collisionDircnt++;
	//		break;
	//	}
	//}
	for (int i = 0; i < 4; i++) {
		m_pTmpCollision[i]->SetPosition(&m_CollisionPos[i]);
	}
	m_pCollision->SetPosition(&m_Pos);
}

bool PlayerZombie::DirectionCheck(Direction direction)
{
	for (int i = 0; i < 4; i++) {
		m_CollisionDir[i] = direction;
		return true;
	}
	return false;
}

void PlayerZombie::ResetArray()
{
	for (int i = 0; i < 4; i++) {
		m_CollisionDir[i] = Direction::NON;
	}
}