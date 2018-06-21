#ifndef HUMAN__H
#define HUMAN__H
//--------------------------------------------------------------------------------------------
//include
//--------------------------------------------------------------------------------------------
#include<vector>

#include"CharaObjectBase.h"
#include"CollisionManager.h"

#define HUMAN_W 54
#define HUMAN_H 108

class Human : public CharaObjectBase
{
public:
	enum DirectionRank{
		ONE,
		TWO,
		THREE
	};
	Human(D3DXVECTOR2* pos,int width,int height, D3DXVECTOR2 pos2[]);
	virtual ~Human();
	virtual void Update();
	virtual void Draw();

	Collision* GetCollision() { return m_pCollision; }

	D3DXVECTOR2* Getpos() { return &m_Pos; }
	void Setpos(D3DXVECTOR2* pos){ m_Pos = *pos;}

	bool IsDeath() { return m_IsDeath; }
	bool IsRevival() {return m_IsRevival;}
private:
	void ChangePostion(RECT* rect, const D3DXVECTOR2& direction, float range, const D3DXVECTOR2& pos);
	bool DirectionCheck(Direction direction);
	void ResetArray();
	const float m_Tu = 0.0278f;
	const float m_Tv = 0.0573f;
	const float m_BreakDownTuTv = 0.0536f;

	Collision* m_pTmpCollision[4];
	D3DXVECTOR2 m_CollisionPos[4];
	D3DXVECTOR2 m_TmpPos[4];
	bool IsTmpFlg[4]{ false,false,false,false };

	Collision* m_pCollision;
	std::vector<Collision*> m_pBoxCollision;
	int m_Size = 95;
	D3DXVECTOR2 m_Pos;
	D3DXVECTOR2 m_BeforePos;
	Direction m_Direction;
	Direction m_CollisionDir[4];
	int m_Width;
	int m_Height;
	int m_CollisionDircnt = 0;
	int m_Fcnt = 0;
	int m_Revivalcnt = 0;
	int m_Hp = 180;
	int m_Speed = 1;
	RECT m_LargestRect{ -50,-50,50,50 };
	RECT m_SmallRect{ -12,-12,12,12 };
	RECT m_MiddleRect{ -25,-25,25,25 };
	RECT m_MiddleRect2{ -25,-25,25,25 };

	D3DXVECTOR2 m_forward{ 0,1.0f};
	// 
	bool m_IsDeath = false;
	bool m_IsRevival = false;
};

#endif