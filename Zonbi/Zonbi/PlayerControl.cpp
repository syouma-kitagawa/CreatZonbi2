#include"PlayerControl.h"
#include"Event.h"

PlayerControl::PlayerControl(){
	m_MousePos.x = 0.0f;
	m_MousePos.y = 0.0f;
}

void PlayerControl::MouseCursor()
{
	//マウス座標取得
	GetCursorPos(&m_MousePos);
	//スクリーン座標からクライアント座標へ変換
	ScreenToClient(Event::GetInstance()->GethWnd(), &m_MousePos);
	Event::GetInstance()->SetMousePos(m_MousePos);
}

void PlayerControl::Update() 
{
	MouseCursor();
}