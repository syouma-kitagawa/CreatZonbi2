#include"Debag.h"


#ifdef DEBUG_RUN
#include <vector>
#include "StageManager.h"
#include "StageObject.h"
#include "DirectGraphics.h"

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

#endif