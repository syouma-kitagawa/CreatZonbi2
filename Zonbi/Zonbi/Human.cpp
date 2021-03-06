#include"Human.h"
#include"Utility.h"
#include"DirectGraphics.h"
#include<algorithm>

Human::Human(D3DXVECTOR2* pos, int width, int height, D3DXVECTOR2 pos2[], int attackWidth, int attackHeight)
	: m_Pos(*pos),m_Width(width),m_Height(height),m_BeforePos(m_Pos),m_AttackWidth(attackWidth),m_AttackHeight(attackHeight)
{
	for (int i = 0; i < 4; i++) {
		m_TmpPos[i] = pos2[i];
	}
	m_pCollision = new Collision();
	m_pCollision->SetPosition(&m_Pos);
	m_pCollision->SetSize(&D3DXVECTOR2(m_Width * 2 - m_Width, m_Height * 2 - m_Height));
	m_pCollision->SetCollisionId(Collision::HUMAN);
	CollisionManager::GetcollisionManager()->AddCollision(m_pCollision);

	m_pBoxCollision = new Collision();
	m_pBoxCollision->SetPosition(&m_Pos);
	m_pBoxCollision->SetSize(&D3DXVECTOR2(m_LargestRect.right * 2,m_LargestRect.bottom * 2));
	m_pBoxCollision->SetCollisionId(Collision::BOX);
	CollisionManager::GetcollisionManager()->AddCollision(m_pBoxCollision);

	//m_pBoxCollision.push_back(new Collision());
	//m_pBoxCollision.back()->SetPosition(&m_Pos);
	//m_pBoxCollision.back()->SetSize(&D3DXVECTOR2(m_SmallRect.right * 2, m_SmallRect.bottom * 2));
	//m_pBoxCollision.back()->SetCollisionId(Collision::BOX);
	//CollisionManager::GetcollisionManager()->AddCollision(m_pBoxCollision.back());

	//m_pBoxCollision.push_back(new Collision());
	//m_pBoxCollision.back()->SetPosition(&m_Pos);
	//m_pBoxCollision.back()->SetSize(&D3DXVECTOR2(m_MiddleRect.right * 2, m_MiddleRect.bottom * 2));
	//m_pBoxCollision.back()->SetCollisionId(Collision::BOX);
	//CollisionManager::GetcollisionManager()->AddCollision(m_pBoxCollision.back());

	//m_pBoxCollision.push_back(new Collision());
	//m_pBoxCollision.back()->SetPosition(&m_Pos);
	//m_pBoxCollision.back()->SetSize(&D3DXVECTOR2(m_MiddleRect2.right * 2, m_MiddleRect2.bottom * 2));
	//m_pBoxCollision.back()->SetCollisionId(Collision::BOX);
	//CollisionManager::GetcollisionManager()->AddCollision(m_pBoxCollision.back());

	for (int i = 0; i < 4; i++) {
		m_pTmpCollision[i] = new Collision();
		m_pTmpCollision[i]->SetPosition(&m_CollisionPos[i]);
		m_pTmpCollision[i]->SetSize(&D3DXVECTOR2(1, 1));
		m_pTmpCollision[i]->SetCollisionId(Collision::BOX);
		CollisionManager::GetcollisionManager()->AddCollision(m_pTmpCollision[i]);
	}
	m_pTmpCollision[0]->SetSize(&D3DXVECTOR2(m_Width, 1));
	m_pTmpCollision[1]->SetSize(&D3DXVECTOR2(m_Width, 1));
	m_pTmpCollision[2]->SetSize(&D3DXVECTOR2(1, m_Height / 2 + 15));
	m_pTmpCollision[3]->SetSize(&D3DXVECTOR2(1, m_Height / 2 + 15));
}


Human::~Human()
{
	delete m_pCollision;
	delete m_pBoxCollision;
	/*for (auto ite = m_pBoxCollision.begin(); ite != m_pBoxCollision.end(); ++ite) {
		delete *ite;
	}*/
	for (int i = 0; i < 4; i++) {
		delete m_pTmpCollision[i];
	}
}

void Human::Draw()
{
	CUSTOMVERTEX HumanDraw[4];
	CUSTOMVERTEX  HumanVertex[4]{
		{ -m_Width / 2, -m_Height / 2, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  0.f },
		{  m_Width / 2, -m_Height / 2, 1.0f, 1.0f, 0xFFFFFFFF, m_Tu, 0.f },
		{  m_Width / 2,  m_Height / 2, 1.0f, 1.0f, 0xFFFFFFFF, m_Tu, m_Tv },
		{ -m_Width / 2,  m_Height / 2, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  m_Tv }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++) {
		HumanDraw[i] = HumanVertex[i];
		HumanDraw[i].x += m_Pos.x;
		HumanDraw[i].y += m_Pos.y;
	}
	int remainder = m_Fcnt % 30;

	if (m_IsDeath) {
		for (int i = 0; i < 4; i++) {
			HumanDraw[i].tu = 0.0f;
			HumanDraw[i].tv = 0.0f;
		}
		switch (m_Direction)
		{
		case Direction::UP:
			DirectGraphics::GetpInstance()->TrimingVertex(HumanDraw, 108, 336, 108, 108, 2048, 2048);
			DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
			break;
		case Direction::DOWN:
			DirectGraphics::GetpInstance()->TrimingVertex(HumanDraw, 0, 336, 108, 108, 2048, 2048);
			DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
			break;
		case Direction::RIGHT:
			DirectGraphics::GetpInstance()->TrimingVertex(HumanDraw, 324, 336, 108, 108, 2048, 2048);
			DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
			break;
		case Direction::LEFT:
			DirectGraphics::GetpInstance()->TrimingVertex(HumanDraw, 216, 336, 108, 108, 2048, 2048);
			DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
			break;
		}
	}
	else {
		if (m_BeforePos == m_Pos) {
			switch (m_Direction)
			{
			case Direction::UP:
				DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 3, m_Tv, 1);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				break;
			case Direction::DOWN:
				DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 0, m_Tv, 1);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				break;
			case Direction::RIGHT:
				DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 9, m_Tv, 1);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				break;
			case Direction::LEFT:
				DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 6, m_Tv, 1);
				DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				break;
			}
		}
		else {
			switch (m_Direction)
			{
			case Direction::UP:

				if (remainder <= 15) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 4, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				else if (remainder >= 16 &&remainder <= 29) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 5, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				break;
			case Direction::DOWN:
				if (remainder <= 15) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 1, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				else if (remainder >= 16 && remainder <= 29) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 2, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				break;
			case Direction::RIGHT:
				if (remainder <= 15) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 10, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				else if (remainder >= 16 && remainder <= 29) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 11, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				break;
			case Direction::LEFT:
				if (remainder <= 15) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 7, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				else if (remainder >= 16 && remainder <= 29) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 8, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				break;
			}
		}
	}
	if (m_IsToBeAttack) {
		ToAttack();
	}
	if (m_Fcnt != 60) {
		m_Fcnt++;
	}
	else {
		m_Fcnt = 0;
	}
}

void Human::Update()
{
	m_CollisionPos[0].x = m_Pos.x;
	m_CollisionPos[0].y = m_Pos.y - m_Speed - m_Height / 2;
	m_CollisionPos[1].x = m_Pos.x;
	m_CollisionPos[1].y = m_Pos.y + m_Speed + m_Height / 2;
	m_CollisionPos[2].x = m_Pos.x + m_Speed + m_Width / 2;
	m_CollisionPos[2].y = m_Pos.y;
	m_CollisionPos[3].x = m_Pos.x - m_Speed - m_Width / 2;
	m_CollisionPos[3].y = m_Pos.y;

	if (m_pCollision->IsSearchOtherCollisionId(m_pCollision->GetOtherCollisionId(), Collision::ZOMBIE)) {
		m_Hp--;
		if (m_Hp % 30 >= 10) {
			m_IsToBeAttack = true;
		}
		if (m_Hp == 0) {
			m_IsDeath = true;
		}
	}
	if (m_IsDeath) {
		if (m_Revivalcnt != 180) {
			m_Revivalcnt++;
		}
		else {
			m_IsRevival = true;
		}
	}
	m_BeforePos = m_Pos;

	if (!m_IsDeath) {
		//TODO
		for (int i = 0; i < m_pBoxCollision->GetOtherCollision().size(); i++) {
			if (m_pBoxCollision->GetOtherCollision()[i]->GetCollisionId() == Collision::ZOMBIE) {
				m_pZombieCollisions.push_back(m_pBoxCollision->GetOtherCollision()[i]);
				m_IsZombieCollisioned = true;
			}
		}

		//TODO
		if (m_IsZombieCollisioned)
		{
			D3DXVECTOR2 NearZombie;
			std::vector<float> tmpPos;
			std::vector<float> tmpBuffer;
			int Id;

			for (int i = 0; i < m_pZombieCollisions.size(); i++)
			{
				D3DXVECTOR2 tmp;

				/* 研究員とゾンビとの間の距離を取っている */
				tmp.x = m_Pos.x - m_pZombieCollisions[i]->GetPosition()->x;
				tmp.y = m_Pos.y - m_pZombieCollisions[i]->GetPosition()->y;

				/* 2乗している */
				float x = pow(tmp.x, 2.0);
				float y = pow(tmp.y, 2.0);

				/* x,yどちらかが同じ座標ならば斜めの距離を出さなくてもいい？ */

				/* これで斜めの距離を出している */
				float length = (x + y);

				/* ここでlengthの平方根を出している */
				float les = sqrt(length);

				tmpPos.push_back(les);
			}

			/* 一時的に非難する */
			for (int g = 0; g < tmpPos.size(); ++g)
			{
				tmpBuffer.push_back(tmpPos[g]);
			}

			/*
			*	昇順でソートをしている
			*	距離が短い順に前に来る
			*/
			std::sort(tmpBuffer.begin(), tmpBuffer.end());

			/* ここで一番近い座標が入ったvectorと前のvectorを見比べてここから更にCollisionsを見る事によってどのゾンビかを特定する */
			for (int k = 0; k < tmpPos.size(); ++k)
			{
				if (tmpBuffer[0] == tmpPos[k])
				{
					Id = k;
				}
			}

			/* 敵の方向を自分にいれている */
			m_Direction = m_pZombieCollisions[Id]->GetDirection();

			/* 敵の位置を貰う */
			switch (m_Direction)
			{
			case UP:
				if (!m_pTmpCollision[0]->IsSearchOtherCollisionId(m_pTmpCollision[0]->GetOtherCollisionId(), Collision::OBJECT)) {
					m_Pos.y += -m_Speed;
				}
				else if (!m_pTmpCollision[2]->IsSearchOtherCollisionId(m_pTmpCollision[2]->GetOtherCollisionId(), Collision::OBJECT)) {
					m_Pos.x += m_Speed;
					m_Direction = RIGHT;
				}
				else if (!m_pTmpCollision[3]->IsSearchOtherCollisionId(m_pTmpCollision[3]->GetOtherCollisionId(), Collision::OBJECT)) {
					m_Pos.x += -m_Speed;
					m_Direction = LEFT;
				}
				break;
			case DOWN:
				if (!m_pTmpCollision[1]->IsSearchOtherCollisionId(m_pTmpCollision[1]->GetOtherCollisionId(), Collision::OBJECT)) {
					m_Pos.y += m_Speed;
				}
				else if (!m_pTmpCollision[2]->IsSearchOtherCollisionId(m_pTmpCollision[2]->GetOtherCollisionId(), Collision::OBJECT)) {
					m_Pos.x += m_Speed;
					m_Direction = RIGHT;
				}
				else if (!m_pTmpCollision[3]->IsSearchOtherCollisionId(m_pTmpCollision[3]->GetOtherCollisionId(), Collision::OBJECT)) {
					m_Pos.x += -m_Speed;
					m_Direction = LEFT;
				}
				break;
			case RIGHT:
				if (!m_pTmpCollision[2]->IsSearchOtherCollisionId(m_pTmpCollision[2]->GetOtherCollisionId(), Collision::OBJECT)) {
					m_Pos.x += m_Speed;
				}
				else if (!m_pTmpCollision[0]->IsSearchOtherCollisionId(m_pTmpCollision[0]->GetOtherCollisionId(), Collision::OBJECT)) {
					m_Pos.y += -m_Speed;
					m_Direction = UP;
				}
				else if (!m_pTmpCollision[1]->IsSearchOtherCollisionId(m_pTmpCollision[1]->GetOtherCollisionId(), Collision::OBJECT)) {
					m_Pos.y += m_Speed;
					m_Direction = DOWN;
				}
				break;
			case LEFT:
				if (!m_pTmpCollision[3]->IsSearchOtherCollisionId(m_pTmpCollision[3]->GetOtherCollisionId(), Collision::OBJECT)) {
					m_Pos.x += -m_Speed;
				}
				else if (!m_pTmpCollision[0]->IsSearchOtherCollisionId(m_pTmpCollision[0]->GetOtherCollisionId(), Collision::OBJECT)) {
					m_Pos.y += -m_Speed;
					m_Direction = UP;
				}
				else if (!m_pTmpCollision[1]->IsSearchOtherCollisionId(m_pTmpCollision[1]->GetOtherCollisionId(), Collision::OBJECT)) {
					m_Pos.y += m_Speed;
					m_Direction = DOWN;
				}
				break;
			}

		}
	}
	///////
	//D3DXVECTOR2 UpDir[4];
	//UpDir[0] = { 0,-1.0f };
	//UpDir[1] = { 0,1.0f };
	//UpDir[2] = { 1.0f, 0 };
	//UpDir[3] = { -1.0,0 };
	//D3DXVECTOR2 RightDir[4];
	//RightDir[0] = { 1.0f,0 };
	//RightDir[1] = { -1.0f,0 };
	//RightDir[2] = { 0, -1.0f };
	//RightDir[3] = { 0,1.0f };
	//D3DXVECTOR2 DownDir[4];
	//DownDir[0] = { 0,1.0f };
	//DownDir[1] = { 0,- 1.0f };
	//DownDir[2] = { -1.0f,0 };
	//DownDir[3] = { 1.0f,0 };
	//D3DXVECTOR2 LeftDir[4];
	//LeftDir[0] = { -1.0f,0 };
	//LeftDir[1] = { 1.0f,0 };
	//LeftDir[2] = { 0,-1.0f };
	//LeftDir[3] = { 0,1.0f };
	//int direction[4];
	//switch (m_Direction)
	//{
	//case CharaObjectBase::UP:
	//	ChangePostion(&m_LargestRect, UpDir[0], m_Height / 2, m_Pos);
	//	ChangePostion(&m_SmallRect,   UpDir[1], m_Height / 2, m_Pos);
	//	ChangePostion(&m_MiddleRect,  UpDir[2], m_Width / 2, m_Pos);
	//	ChangePostion(&m_MiddleRect2,  UpDir[3], m_Width / 2, m_Pos);
	//	direction[0] = UP;
	//	direction[1] = DOWN;
	//	direction[2] = RIGHT;
	//	direction[3] = LEFT;
	//	break;
	//case CharaObjectBase::RIGHT:
	//	ChangePostion(&m_LargestRect, RightDir[0], m_Width / 2, m_Pos);
	//	ChangePostion(&m_SmallRect,   RightDir[1], m_Width / 2, m_Pos);
	//	ChangePostion(&m_MiddleRect,  RightDir[2], m_Height / 2, m_Pos);
	//	ChangePostion(&m_MiddleRect2,  RightDir[3], m_Height / 2, m_Pos);
	//	direction[0] = RIGHT;
	//	direction[1] = LEFT;
	//	direction[2] = UP;
	//	direction[3] = DOWN;
	//	break;
	//case CharaObjectBase::DOWN:
	//	ChangePostion(&m_LargestRect, DownDir[0], m_Height / 2, m_Pos);
	//	ChangePostion(&m_SmallRect,   DownDir[1], m_Height / 2, m_Pos);
	//	ChangePostion(&m_MiddleRect,  DownDir[2], m_Width / 2, m_Pos);
	//	ChangePostion(&m_MiddleRect2,  DownDir[3], m_Width / 2, m_Pos);
	//	direction[0] = DOWN;
	//	direction[1] = UP;
	//	direction[2] = LEFT;
	//	direction[3] = RIGHT;
	//	break;
	//case CharaObjectBase::LEFT:
	//	ChangePostion(&m_LargestRect, LeftDir[0], m_Width / 2, m_Pos);
	//	ChangePostion(&m_SmallRect,   LeftDir[1], m_Width / 2, m_Pos);
	//	ChangePostion(&m_MiddleRect,  LeftDir[2], m_Height / 2, m_Pos);
	//	ChangePostion(&m_MiddleRect2,  LeftDir[3], m_Height / 2, m_Pos);
	//	direction[0] = LEFT;
	//	direction[1] = RIGHT;
	//	direction[2] = UP;
	//	direction[3] = DOWN;
	//	break;
	//}
	//m_pBoxCollision[0]->SetPosition(&D3DXVECTOR2(50 + m_LargestRect.left, 50 + m_LargestRect.top));
	//m_pBoxCollision[1]->SetPosition(&D3DXVECTOR2(50 + m_SmallRect.left, 50 + m_SmallRect.top));
	//m_pBoxCollision[2]->SetPosition(&D3DXVECTOR2(50 + m_MiddleRect.left, 50 + m_MiddleRect.top));
	//m_pBoxCollision[3]->SetPosition(&D3DXVECTOR2(50 + m_MiddleRect2.left, 50 + m_MiddleRect2.top));

	//if (!m_IsDeath) {
	//	bool collision[4]{ false,false,false,false };
	//	int collisioncnt = 0;
	//	//矩形四つを見ている
	//	for (int i = 0; i < m_pBoxCollision.size(); i++) {
	//		//矩形の当たったものにゾンビがいるかどうか
	//		if (m_pBoxCollision[i]->IsSearchOtherCollisionId(m_pBoxCollision[i]->GetOtherCollisionId(), Collision::ZOMBIE)) {
	//			collision[i] = true;
	//			collisioncnt++;
	//		}
	//	}
	//	if (collisioncnt == 1) {
	//		for (int i = 0; i < 4; i++) {
	//			if (!collision[i] && m_BeforePos == m_Pos) {
	//				switch (direction[i])
	//				{
	//				case UP:
	//					if (!DirectionCheck(UP)) {
	//						m_BeforePos = m_Pos;
	//						m_Pos.y += -m_Speed;
	//						m_Direction = UP;
	//						ResetArray();
	//						break;
	//					}
	//					else {
	//						continue;
	//					}
	//				case DOWN:
	//					if (!DirectionCheck(DOWN)) {
	//						m_BeforePos = m_Pos;
	//						m_Pos.y += m_Speed;
	//						m_Direction = DOWN;
	//						ResetArray();
	//						break;
	//					}
	//					else {
	//						continue;
	//					}
	//				case RIGHT:
	//					if (!DirectionCheck(RIGHT)) {
	//						m_BeforePos = m_Pos;
	//						m_Pos.x += -m_Speed;
	//						m_Direction = RIGHT;
	//						ResetArray();
	//						break;
	//					}
	//					else {
	//						continue;
	//					}
	//				case LEFT:
	//					if (!DirectionCheck(LEFT)) {
	//						m_BeforePos = m_Pos;
	//						m_Pos.x += m_Speed;
	//						m_Direction = LEFT;
	//						ResetArray();
	//						break;
	//					}
	//					else {
	//						continue;
	//					}
	//				}
	//			}
	//		}
	//	}
	//	else if (collisioncnt == 2) {
	//		for (int i = 0; i < 4; i++) {
	//			if (!collision[i]) {
	//				switch (direction[i])
	//				{
	//				case UP:
	//					if (!DirectionCheck(UP)) {
	//						m_Pos.y += m_Speed;
	//						m_Direction = UP;
	//						ResetArray();
	//						break;
	//					}
	//					else {
	//						continue;
	//					}
	//				case DOWN:
	//					if (!DirectionCheck(DOWN)) {
	//						m_Pos.y += -m_Speed;
	//						m_Direction = DOWN;
	//						ResetArray();
	//						break;
	//					}
	//					else {
	//						continue;
	//					}
	//				case RIGHT:
	//					if (!DirectionCheck(RIGHT)) {
	//						m_Pos.x += m_Speed;
	//						m_Direction = RIGHT;
	//						ResetArray();
	//						break;
	//					}
	//					else {
	//						continue;
	//					}
	//				case LEFT:
	//					if (!DirectionCheck(LEFT)) {
	//						m_Pos.x += -m_Speed;
	//						m_Direction = LEFT;
	//						ResetArray();
	//						break;
	//					}
	//					else {
	//						continue;
	//					}
	//				}
	//			}
	//		}
	//	}
	//	else if (collisioncnt == 3) {
	//		for (int i = 0; i < 4; i++) {
	//			if (!collision[i]) {
	//				switch (direction[i])
	//				{
	//				case UP:
	//					if (!DirectionCheck(UP)) {
	//						m_Pos.y += m_Speed;
	//						m_Direction = UP;
	//						ResetArray();
	//						break;
	//					}
	//				case DOWN:
	//					if (!DirectionCheck(DOWN)) {
	//						m_Pos.y += -m_Speed;
	//						m_Direction = DOWN;
	//						ResetArray();
	//						break;
	//					}
	//				case RIGHT:
	//					if (!DirectionCheck(RIGHT)) {
	//						m_Pos.x += m_Speed;
	//						m_Direction = RIGHT;
	//						ResetArray();
	//						break;
	//					}
	//				case LEFT:
	//					if (!DirectionCheck(LEFT)) {
	//						m_Pos.x += -m_Speed;
	//						m_Direction = LEFT;
	//						ResetArray();
	//						break;
	//					}
	//				}
	//			}
	//		}
	//	}
	//	else if (collisioncnt == 4) {

	//	}
	//}

	for (int i = 0; i < 4; i++) {
		m_pTmpCollision[i]->SetPosition(&m_CollisionPos[i]);
	}
	m_pCollision->SetPosition(&m_Pos);
	m_LargestRect = { -100,-100,100,100 };
	m_pBoxCollision->SetPosition(&m_Pos);
	//TODO
	m_pZombieCollisions.clear();
	m_IsZombieCollisioned = false;
}

void Human::ChangePostion(RECT* rect, const D3DXVECTOR2& direction, float range, const D3DXVECTOR2& pos)
{
	D3DXVECTOR2 tmp = direction * range;
	tmp += pos;
	rect->left += tmp.x;
	rect->top += tmp.y;
	rect->bottom += tmp.y;
	rect->right += tmp.x;
}

bool Human::DirectionCheck(Direction direction)
 {
	switch (direction)
	{
	case CharaObjectBase::UP:
		if (m_pTmpCollision[0]->IsSearchOtherCollisionId(m_pTmpCollision[0]->GetOtherCollisionId(), Collision::OBJECT)) {
			return true;
		}
		return false;
	case CharaObjectBase::RIGHT:
		if (m_pTmpCollision[2]->IsSearchOtherCollisionId(m_pTmpCollision[2]->GetOtherCollisionId(), Collision::OBJECT)) {
			return true;
		}
		return false;
	case CharaObjectBase::DOWN:
		if (m_pTmpCollision[1]->IsSearchOtherCollisionId(m_pTmpCollision[1]->GetOtherCollisionId(), Collision::OBJECT)) {
			return true;
		}
		return false;
	case CharaObjectBase::LEFT:
		if (m_pTmpCollision[3]->IsSearchOtherCollisionId(m_pTmpCollision[3]->GetOtherCollisionId(), Collision::OBJECT)) {
			return true;
		}
		return false;
	}
 }

void Human::ResetArray() {
	for (int i = 0; i < 4; i++) {
		m_CollisionDir[i] = Direction::NON;
	}
}
void Human::ToAttack() 
{
	CUSTOMVERTEX ToBeAttackDraw[4];
	CUSTOMVERTEX  ToBeAttackVertex[4]{
	{ -m_AttackWidth / 2, -m_AttackHeight / 2, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  0.f },
	{ m_AttackWidth / 2, -m_AttackHeight / 2, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 0.f },
	{ m_AttackWidth / 2,  m_AttackHeight / 2, 1.0f, 1.0f, 0xFFFFFFFF, 1.0f, 1.0f },
	{ -m_AttackWidth / 2,  m_AttackHeight / 2, 1.0f, 1.0f, 0xFFFFFFFF, 0.f,  1.0f }
	};
	//位置と頂点情報を代入
	for (int i = 0; i < 4; i++) {
		ToBeAttackDraw[i] = ToBeAttackVertex[i];
		ToBeAttackDraw[i].x += m_Pos.x;
		ToBeAttackDraw[i].y += m_Pos.y;
	}

	switch (m_Direction)
	{
	case Direction::UP:
		DirectGraphics::GetpInstance()->TrimingVertex(ToBeAttackDraw, 60, 540, 108, 108, 2048, 2048);
		DirectGraphics::GetpInstance()->Render("Texture/combine.png", ToBeAttackDraw);
		break;
	case Direction::DOWN:
		DirectGraphics::GetpInstance()->TrimingVertex(ToBeAttackDraw, 0, 540, 108, 108, 2048, 2048);
		DirectGraphics::GetpInstance()->Render("Texture/combine.png", ToBeAttackDraw);
		break;
	case Direction::RIGHT:
		DirectGraphics::GetpInstance()->TrimingVertex(ToBeAttackDraw, 180, 540, 108, 108, 2048, 2048);
		DirectGraphics::GetpInstance()->Render("Texture/combine.png", ToBeAttackDraw);
		break;
	case Direction::LEFT:
		DirectGraphics::GetpInstance()->TrimingVertex(ToBeAttackDraw, 120, 540, 108, 108, 2048, 2048);
		DirectGraphics::GetpInstance()->Render("Texture/combine.png", ToBeAttackDraw);
		break;
	}
	m_IsToBeAttack = false;
}