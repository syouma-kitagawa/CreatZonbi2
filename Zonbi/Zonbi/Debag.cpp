#include"Debag.h"


#ifdef DEBUG_RUN
#include <vector>
#include "StageManager.h"
#include "StageObject.h"
#include "DirectGraphics.h"
#include"PlayerZombie.h"

void DebugDrawHitRect(StageManager *manager)
{
	std::vector<StageObject*> list = manager->GetStageObject();

	for (int i = 0; i < list.size(); i++)
	{
		Collision *collision = list[i]->GetCollision();

		D3DXVECTOR2 *pos = collision->GetPosition();
		D3DXVECTOR2 *size = collision->GetSize();

		float h_width = size->x / 2.0f;
		float h_height = size->y / 2.0f;
		CUSTOMVERTEX vertex[4] = {
		{ pos->x - h_width, pos->y - h_height, 0.0f, 1.0f, 0x80ff0000, 0.0f, 0.0f },
		{ pos->x + h_width, pos->y - h_height, 0.0f, 1.0f, 0x80ff0000, 0.0f, 0.0f },
		{ pos->x - h_width, pos->y + h_height, 0.0f, 1.0f, 0x80ff0000, 0.0f, 0.0f },
		{ pos->x + h_width, pos->y + h_height, 0.0f, 1.0f, 0x80ff0000, 0.0f, 0.0f },
		};

		DirectGraphics::GetpInstance()->DebugDrawBox(vertex);
	}
}

void DebugPlayerHitRect(PlayerZombie *player)
{
	Collision *list[5] =
	{
		player->GetCollision(),
		player->GetTmpCollision(0),
		player->GetTmpCollision(1),
		player->GetTmpCollision(2),
		player->GetTmpCollision(3),
	};

	for (int i = 0; i < 5; i++)
	{

		D3DXVECTOR2 *pos = list[i]->GetPosition();
		D3DXVECTOR2 size = *list[i]->GetSize();

		if (size.x == 1)
		{
			size.x = 10;
		}

		if (size.y == 1)
		{
			size.y = 10;
		}

		float h_width = size.x / 2.0f;
		float h_height = size.y / 2.0f;

		DWORD color = 0x8000ff00;

		if (i != 0)
		{
			color = 0x80000000;
		}

		CUSTOMVERTEX vertex[4] = {
			{ pos->x - h_width, pos->y - h_height, 0.0f, 1.0f, color, 0.0f, 0.0f },
		{ pos->x + h_width, pos->y - h_height, 0.0f, 1.0f, color, 0.0f, 0.0f },
		{ pos->x - h_width, pos->y + h_height, 0.0f, 1.0f, color, 0.0f, 0.0f },
		{ pos->x + h_width, pos->y + h_height, 0.0f, 1.0f, color, 0.0f, 0.0f },
		};

		DirectGraphics::GetpInstance()->DebugDrawBox(vertex);
	}

}
#endif