#ifndef EVENT_H
#define EVENT_H

#include <windows.h>
#include<stdio.h>
#include<d3dx9.h>

#define DISPLAY_WIDTH 1920
#define DISPLAY_HEIGHT 1080

class Event{
public:
	static void CreateInstance(HWND hwnd);
	~Event();
	static Event* GetInstance() { return pInstance; }

	HWND GethWnd() { return m_hWnd; }
	void SethWnd(HWND hwnd) { m_hWnd = hwnd; }

	D3DXVECTOR2 GetMousePosPointToVector2()
	{ 
		D3DXVECTOR2 vectorRet;
		vectorRet.x = m_MousePos.x;
		vectorRet.y = m_MousePos.y;
		return vectorRet;
	}
	void SetMousePos(POINT mousePos) {m_MousePos = mousePos;}
private:
	Event(HWND hwnd) {};
	static Event* pInstance;

	HWND m_hWnd;
	POINT m_MousePos;

};

#endif