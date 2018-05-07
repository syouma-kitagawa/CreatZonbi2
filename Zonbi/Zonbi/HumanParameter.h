#ifndef HUMANPARAMETER_H
#define HUMANPAROMETER_H

#include <vector>

#include<d3dx9.h>

class HumanParameter{
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

	~HumanParameter();

	int GetHumanNum() { return m_HumanNum; }
	HumanData* GetHumanParam(int number) { return &m_pHumanPram[number]; }

	void LoadHuman();
private:

private:
	static HumanParameter* m_pInstance;

	int m_HumanNum = 0;
	HumanData* m_pHumanPram;

	HumanParameter();
};

#endif