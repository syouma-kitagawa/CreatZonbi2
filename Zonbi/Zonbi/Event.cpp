#include"Event.h"

Event* Event::pInstance = NULL;

Event::~Event()
{
}

void Event::CreateInstance(HWND hwnd)
{
	if (pInstance == NULL) {
		pInstance = new Event(hwnd);
		Event::GetInstance()->SethWnd(hwnd);
	}
}