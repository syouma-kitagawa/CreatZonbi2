#include"PlayerControl.h"
#include"Event.h"

PlayerControl::PlayerControl(){
	m_MousePos.x = 0.0f;
	m_MousePos.y = 0.0f;
}

void PlayerControl::MouseCursor()
{
	//�}�E�X���W�擾
	GetCursorPos(&m_MousePos);
	//�X�N���[�����W����N���C�A���g���W�֕ϊ�
	ScreenToClient(Event::GetInstance()->GethWnd(), &m_MousePos);
	Event::GetInstance()->SetMousePos(m_MousePos);
}

void PlayerControl::Update() 
{
	MouseCursor();
}