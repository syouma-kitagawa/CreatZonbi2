#ifndef ZONBIMANAGER_H
#define ZONBIMANAGER_H

#include <vector>

#include"Zonbi.h"

class ZonbiManager
{
public:
	ZonbiManager();
	~ZonbiManager();
	void Draw();
	void Update();

	void ZonbiAdd(D3DXVECTOR2 pos);
private:
	std::vector<Zonbi*> m_pZonbi;
};

#endif