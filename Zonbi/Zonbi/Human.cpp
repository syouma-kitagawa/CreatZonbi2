#include"Human.h"
#include"Utility.h"
#include"DirectGraphics.h"

Human::Human(D3DXVECTOR2* pos, int width, int height): m_Pos(*pos),m_Width(width),m_Height(height),m_BeforePos(m_Pos)
{
	m_pCollision = new Collision();
	m_pCollision->SetPosition(&m_Pos);
	m_pCollision->SetSize(&D3DXVECTOR2(m_Width * 2 - m_Width, m_Height * 2 - m_Height));
	m_pCollision->SetCollisionId(Collision::HUMAN);
	CollisionManager::GetcollisionManager()->AddCollision(m_pCollision);

	m_pBoxCollision.push_back(new Collision());
	m_pBoxCollision.back()->SetPosition(&m_Pos);
	m_pBoxCollision.back()->SetSize(&D3DXVECTOR2(m_LargestRect.right * 2,m_LargestRect.bottom * 2));
	m_pBoxCollision.back()->SetCollisionId(Collision::BOX);
	CollisionManager::GetcollisionManager()->AddCollision(m_pBoxCollision.back());

	m_pBoxCollision.push_back(new Collision());
	m_pBoxCollision.back()->SetPosition(&m_Pos);
	m_pBoxCollision.back()->SetSize(&D3DXVECTOR2(m_SmallRect.right * 2, m_SmallRect.bottom * 2));
	m_pBoxCollision.back()->SetCollisionId(Collision::BOX);
	CollisionManager::GetcollisionManager()->AddCollision(m_pBoxCollision.back());

	m_pBoxCollision.push_back(new Collision());
	m_pBoxCollision.back()->SetPosition(&m_Pos);
	m_pBoxCollision.back()->SetSize(&D3DXVECTOR2(m_MiddleRect.right * 2, m_MiddleRect.bottom * 2));
	m_pBoxCollision.back()->SetCollisionId(Collision::BOX);
	CollisionManager::GetcollisionManager()->AddCollision(m_pBoxCollision.back());

	m_pBoxCollision.push_back(new Collision());
	m_pBoxCollision.back()->SetPosition(&m_Pos);
	m_pBoxCollision.back()->SetSize(&D3DXVECTOR2(m_MiddleRect2.right * 2, m_MiddleRect2.bottom * 2));
	m_pBoxCollision.back()->SetCollisionId(Collision::BOX);
	CollisionManager::GetcollisionManager()->AddCollision(m_pBoxCollision.back());
}


Human::~Human()
{
	delete m_pCollision;
	for (auto ite = m_pBoxCollision.begin(); ite != m_pBoxCollision.end(); ++ite) {
		delete *ite;
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
	//à íuÇ∆í∏ì_èÓïÒÇë„ì¸
	for (int i = 0; i < 4; i++) {
		HumanDraw[i] = HumanVertex[i];
		HumanDraw[i].x += m_Pos.x;
		HumanDraw[i].y += m_Pos.y;
	}
	int remainder = m_Fcnt % 40;

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

				if (remainder <=19) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 4, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				else if (remainder >= 20 &&remainder <= 39) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 5, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				break;
			case Direction::DOWN:
				if (remainder <= 19) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 1, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				else if (remainder >= 20 && remainder <= 39) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 2, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				break;
			case Direction::RIGHT:
				if (remainder <= 19) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 10, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				else if (remainder >= 20 && remainder <= 39) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 11, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				break;
			case Direction::LEFT:
				if (remainder <= 19) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 7, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
				}
				else if (remainder >= 20 && remainder <= 39) {
					DirectGraphics::GetpInstance()->Animation(HumanDraw, m_Tu, 8, m_Tv, 1);
					DirectGraphics::GetpInstance()->Render("Texture/combine.png", HumanDraw);
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

void Human::Update()
{
	if (m_pCollision->GetOtherCollisionId() == Collision::ZOMBIE) {
		m_Hp--;
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
	/*int average = m_Height + m_Width / 2;
	m_LargestRect.left += m_Pos.x;
	m_LargestRect.top += m_Pos.y;
	m_LargestRect.right += m_Pos.x;
	m_LargestRect.bottom += m_Pos.y;
	m_SmallRect.left += m_Pos.x;
	m_SmallRect.top += m_Pos.y;
	m_SmallRect.right += m_Pos.x;
	m_SmallRect.bottom += m_Pos.y;
	m_MiddleRect.left += m_Pos.x;
	m_MiddleRect.top += m_Pos.y;
	m_MiddleRect.right += m_Pos.x;
	m_MiddleRect.bottom += m_Pos.y;
	m_MiddleRect2.left += m_Pos.x;
	m_MiddleRect2.top += m_Pos.y;
	m_MiddleRect2.right += m_Pos.x;
	m_MiddleRect2.bottom += m_Pos.y;
	ChangePostion(&m_LargestRect, m_forward, average / 2);
	ChangePostion(&m_SmallRect, -m_forward, average / 2);
	D3DXVECTOR2 tmp = m_forward;
	m_forward.x = tmp.x;
	m_forward.y = tmp.y;
	m_forward.x = tmp.y;
	m_forward.y = tmp.x;
	ChangePostion(&m_MiddleRect, m_forward, average / 2);
	m_forward.y * -1.0f;
	ChangePostion(&m_MiddleRect2, m_forward, average / 2);*/
	//ChangePostion(&m_MiddleRect, )
	
	D3DXVECTOR2 UpRect[4];
	UpRect[0] = { 0,1.0f };
	UpRect[1] = { 0,-1.0f };
	UpRect[2] = { 1.0f, 0 };
	UpRect[3] = { -1.0,0 };
	D3DXVECTOR2 RightRect[4];
	RightRect[0] = { 1.0f,0 };
	RightRect[1] = { -1.0f,0 };
	RightRect[2] = { 0, -1.0f };
	RightRect[3] = { 0,1.0f };
	D3DXVECTOR2 DownRect[4];
	DownRect[0] = { 0,-1.0f };
	DownRect[1] = { 0, 1.0f };
	DownRect[2] = { -1.0f,0 };
	DownRect[3] = { 1.0f,0 };
	D3DXVECTOR2 LeftRect[4];
	LeftRect[0] = { -1.0f,0 };
	LeftRect[1] = { 1.0f,0 };
	LeftRect[2] = { 0,1.0f };
	LeftRect[3] = { 0,-1.0f };
	int direction[4];
	switch (m_Direction)
	{
	case CharaObjectBase::UP:
		ChangePostion(&m_LargestRect, UpRect[0], m_Height / 2 + m_Pos.y);
		ChangePostion(&m_SmallRect,   UpRect[1], m_Height / 2 + m_Pos.y);
		ChangePostion(&m_MiddleRect,  UpRect[2], m_Width / 2 + m_Pos.x);
		ChangePostion(&m_MiddleRect,  UpRect[3], m_Width / 2 + m_Pos.x);
		direction[0] = UP;
		direction[1] = DOWN;
		direction[2] = RIGHT;
		direction[3] = LEFT;
		break;
	case CharaObjectBase::RIGHT:
		ChangePostion(&m_LargestRect, RightRect[0], m_Width / 2 + m_Pos.x);
		ChangePostion(&m_SmallRect, RightRect[1], m_Width / 2 + m_Pos.x);
		ChangePostion(&m_MiddleRect, RightRect[2], m_Height / 2 + m_Pos.y);
		ChangePostion(&m_MiddleRect, RightRect[3], m_Height / 2 + m_Pos.y);
		direction[0] = RIGHT;
		direction[1] = LEFT;
		direction[2] = DOWN;
		direction[3] = UP;
		break;
	case CharaObjectBase::DOWN:
		ChangePostion(&m_LargestRect, DownRect[0], m_Height / 2 + m_Pos.y);
		ChangePostion(&m_SmallRect, DownRect[1], m_Height / 2 + m_Pos.y);
		ChangePostion(&m_MiddleRect, DownRect[2], m_Width / 2 + m_Pos.x);
		ChangePostion(&m_MiddleRect, DownRect[3], m_Width / 2 + m_Pos.x);
		direction[0] = DOWN;
		direction[1] = UP;
		direction[2] = LEFT;
		direction[3] = RIGHT;
		break;
	case CharaObjectBase::LEFT:
		ChangePostion(&m_LargestRect, LeftRect[0], m_Width / 2 + m_Pos.x);
		ChangePostion(&m_SmallRect, LeftRect[1], m_Width / 2 + m_Pos.x);
		ChangePostion(&m_MiddleRect, LeftRect[2], m_Height / 2 + m_Pos.y);
		ChangePostion(&m_MiddleRect, LeftRect[3], m_Height / 2 + m_Pos.y);
		direction[0] = LEFT;
		direction[1] = RIGHT;
		direction[2] = UP;
		direction[3] = DOWN;
		break;
	}

	bool collision[4]{ false,false,false,false };
	int collisioncnt = 0;
	for (int i = 0; i < m_pBoxCollision.size();i++) {
		if (m_pBoxCollision[i]->GetOtherCollisionId() == Collision::ZOMBIE) {
			collision[i] = true;
			collisioncnt++;
		}
	}
	if (collisioncnt == 1) {
		for (int i = 0; i < 4; i++) {
			if (collision[i]) {
					switch (direction[i])
					{
					case UP:
						 {
							m_Pos.y += -m_Speed;
							m_Direction = DOWN;;
						}
						break;
					case DOWN:
						if (!DirectionCheck(DOWN)) {
							m_Pos.y += m_Speed;
							m_Direction = UP;
						}
						break;
					case RIGHT:
						if (!DirectionCheck(RIGHT)) {
							m_Pos.x += -m_Speed;
							m_Direction = LEFT;
						}
						break;
					case LEFT:
						if (!DirectionCheck(LEFT)) {
							m_Pos.x += m_Speed;
							m_Direction = RIGHT;
						}
						break;
				}
			}
		}
	}
	else if (collisioncnt == 2) {
		for (int i = 0; i < 4; i++) {
			if (!collision[i]) {
				switch (direction[i])
				{
				case UP:
					if (!DirectionCheck(UP)) {
						m_Pos.y += m_Speed;
						m_Direction = UP;
					}
					break;
				case DOWN:
					if (!DirectionCheck(DOWN)) {
						m_Pos.y += -m_Speed;
						m_Direction = DOWN;
					}
					break;
				case RIGHT:
					if (!DirectionCheck(RIGHT)) {
						m_Pos.x += m_Speed;
						m_Direction = RIGHT;
					}
					break;
				case LEFT:
					if (!DirectionCheck(LEFT)) {
						m_Pos.x += -m_Speed;
						m_Direction = LEFT;
					}
					break;
				}
			}
		}
	}
	else if (collisioncnt == 3) {
		for (int i = 0; i < 4; i++) {
			if (!collision[i]) {
				switch (direction[i])
				{
				case UP:
					if (!DirectionCheck(UP)) {
						m_Pos.y += m_Speed;
						m_Direction = UP;
					}
					break;
				case DOWN:
					if (!DirectionCheck(DOWN)) {
						m_Pos.y += -m_Speed;
						m_Direction = DOWN;
					}
					break;
				case RIGHT:
					if (!DirectionCheck(RIGHT)) {
						m_Pos.x += m_Speed;
						m_Direction = RIGHT;
					}
					break;
				case LEFT:
					if (!DirectionCheck(LEFT)) {
						m_Pos.x += -m_Speed;
						m_Direction = LEFT;
					}
					break;
				}
			}
		}
	}
	else if (collisioncnt == 4) {

	}
	if (m_pCollision->GetOtherCollisionId() == Collision::OBJECT) {
		switch (m_Direction)
		{
		case UP:
			m_Pos.y += - m_Speed;
			m_Direction = UP;
			m_CollisionDir[m_CollisionDircnt] = UP;
			m_CollisionDircnt++;
			break;
		case DOWN:
			m_Pos.y += m_Speed;
			m_Direction = DOWN;
			m_CollisionDir[m_CollisionDircnt] = DOWN;
			m_CollisionDircnt++;
			break;
		case RIGHT:
			m_Pos.x += -m_Speed;
			m_Direction = RIGHT;
			m_CollisionDir[m_CollisionDircnt] = RIGHT;
			m_CollisionDircnt++;
			break;
		case LEFT:
			m_Pos.x += m_Speed;
			m_Direction = LEFT;
			m_CollisionDir[m_CollisionDircnt] = LEFT;
			break;
		}
	}
		m_pCollision->SetPosition(&m_Pos);
	for (auto ite = m_pBoxCollision.begin(); ite != m_pBoxCollision.end(); ++ite) {
		(*ite)->SetPosition(&m_Pos);
	}

}

 void Human::ChangePostion(RECT* rect, const D3DXVECTOR2& direction, float range)
{
	D3DXVECTOR2 tmp = direction * range;
	rect->left += tmp.x;
	rect->top += tmp.y;
	rect->bottom += tmp.y;
	rect->right += tmp.x;
}

bool Human::DirectionCheck(Direction direction)
 {
	for (int i = 0; i < 4; i++) {
		m_CollisionDir[i] = direction;
		return true;
	}
	return false;
 }

void Human::ResetArray() {
	for (int i = 0; i < 4; i++) {
		m_CollisionDir[i] = Direction::NON;
	}
}