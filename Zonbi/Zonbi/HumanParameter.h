#ifndef HUMANPARAMETER_H
#define HUMANPAROMETER_H

#include <vector>

#include"Human.h"

class HumanParameter
{
public:
	struct HumanData {
		D3DXVECTOR2 pos;
		float speed;
	};

	static HumanParameter& GetInstance()
	{
		if (m_pInstance == nullptr) {
			m_pInstance = new HumanParameter;
		}
		return *m_pInstance;
	}

	void LoadHuman();
private:
	static HumanParameter* m_pInstance;

	int m_HumanNum = 0;
	HumanData* m_pHumanPram;

	HumanParameter();
	~HumanParameter();
};

#endif