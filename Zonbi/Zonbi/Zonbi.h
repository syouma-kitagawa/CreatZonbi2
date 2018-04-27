#ifndef ZONBI_H
#define ZONBIH

#include"CharaObject.h"
#include"CollisionManager.h"

#define ZONBI_SPEED 1.0f

#define ZONBI_W 108
#define ZONBI_H 54
//
//#define PLAYER_INNTIAL_POSX 100.f
//#define PLAYER_INNTIAL_POSY 100.f

class Zonbi : public CharaObject
{
public:
	Zonbi(D3DXVECTOR2 pos);
	virtual ~Zonbi();

	virtual void Update();
	virtual void Draw();
	int* GetZonbiTexture() { return &m_ZonbiTexture; }
private:
	bool m_MoveZonbi;

	Collision* m_Collision;
	D3DXVECTOR2 m_Pos;
	D3DXVECTOR2 m_Distance;
	//ÇÃÇøÇ…ñºëOïœçX
	D3DXVECTOR2 m_NextPos;
	int m_ZonbiTexture;
};

#endif