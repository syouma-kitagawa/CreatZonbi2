#ifndef DIRECTINPUT_H
#define DIRECTINPUT_H

//------------------------------------------------------------------------------------------
//include
//------------------------------------------------------------------------------------------
#include<dinput.h>

#include"Utility.h"

class DirectInput {
public:
	static void CrateInstance(HWND hWnd, HINSTANCE hInstance);

	static DirectInput& GetInstance();

	void UpdateKey();

	void UpdateMouse();

	Utility::BUTTON_STATE GetKeyState(Utility::KEY_KIND keyKind) {
		return m_CurrentKey[static_cast<int>(keyKind)];
	}

	const Utility::MouseData* GetMouseData() {
		return &m_Mouse;
	}

private:
	static DirectInput* pInstance;

	DirectInput(HWND hWnd, HINSTANCE hInstance);

	~DirectInput();

	LPDIRECTINPUT8 m_pDInput;
	LPDIRECTINPUTDEVICE8 m_pKeyDevice;
	LPDIRECTINPUTDEVICE8 m_pMouseDevise;

	Utility::BUTTON_STATE m_CurrentKey[static_cast<int>(Utility::KEY_KIND::MAX)];
	Utility::MouseData m_Mouse;

	int DikCheck(Utility::KEY_KIND keyKind);
	void KeyCheck(Utility::KEY_KIND keyKind, BYTE* pDiks);
	void MouseCheck(const DIMOUSESTATE& dims);

	DirectInput(const DirectInput&);
	void operator =(const DirectInput&);
};
#endif