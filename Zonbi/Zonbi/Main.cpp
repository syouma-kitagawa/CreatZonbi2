#include <windows.h>
#include <mmsystem.h>

#include"DirectGraphics.h"
#include"DirectInput.h"
#include"DirectSound.h"
#include"Event.h"
#include"SceneManager.h"
#include"ZombieParameter.h"


#define TITLE 	TEXT("ZONBI")
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)
/**
*���b�Z�[�W����
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_KEYDOWN:        // �L�[�������ꂽ�Ƃ�
		if (wp == VK_ESCAPE)
		{
			DestroyWindow(hWnd);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}

/**
*���C�����[�`��
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASS Wndclass;
	HWND hWnd;

	//Windows���̐ݒ�
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpfnWndProc = WndProc;
	Wndclass.cbClsExtra = Wndclass.cbWndExtra = 0;
	Wndclass.hInstance = hInstance;
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wndclass.lpszMenuName = NULL;
	Wndclass.lpszClassName = TITLE;	//�N���X��
									//Window�̓o�^
	RegisterClass(&Wndclass);
	//Window�̐���
	hWnd = CreateWindow(
		TITLE,								//�E�B���h�E�̃N���X��
		TITLE, 							//�E�B���h�E�̃^�C�g��
		WS_VISIBLE | WS_POPUP,	//�E�B���h�E�X�^�C��
		0,						// �E�B���h�E�̉������̈ʒux
		0,						// �E�B���h�E�̏c�����̈ʒuy
		DISPLAY_WIDTH,							// Width�i���j
		DISPLAY_HEIGHT,							// Height�i�����j
		NULL,
		NULL,
		hInstance,						
		// �A�v���P�[�V�����C���X�^���X�̃n���h��
		NULL
	);

	if (!hWnd) return 0;

	DirectGraphics::CreateInstance(hWnd);
	DirectInput::CrateInstance(hWnd, hInstance);
	DirectSound::CreateInstance(hWnd);
	Event::CreateInstance(hWnd);
	SceneManager scene;

	DWORD SyncOld = timeGetTime();	//	�V�X�e�����Ԃ��擾
	DWORD SyncNow;

	timeBeginPeriod(1);
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		Sleep(1);
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{

			SyncNow = timeGetTime();
			if (SyncNow - SyncOld >= 1000 / 60) //	1�b�Ԃ�60�񂱂̒��ɓ���͂�
			{
				scene.Run();
				SyncOld = SyncNow;
			}
		}
	}
	timeEndPeriod(1);

	// �J�������I���
	return (int)msg.wParam;
}
