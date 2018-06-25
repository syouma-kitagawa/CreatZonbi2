#ifndef FADER_H
#define FADER_H

#include"ObjectBase.h"

class Fader : public ObjectBase
{
public:
	Fader(int frmMax);
	virtual ~Fader();
	virtual void Draw();
	virtual void Update();
	void FadeIn();
	void FadeOut();
	bool GetFadeFinish() { return m_FadeFinish; }
private:
	float m_Alpha;
	float m_AlphaIn = 1.0f;
	float m_AlphaOut = 0.0f;
	float m_AlphaIncAmount;
	int m_FrmCnt = 0;
	int m_FrmMax;
	bool m_FadeFinish = false;
};

#endif

