#ifndef DIRECTGRAPHICS_H
#define DIRECTGRAPHICS_H

//�V���O���g���N���X

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include <d3dx9.h>
#include <map>
#include <stdio.h>

#include"Debag.h"

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
};

class DirectGraphics {
public:
	//2D�O���t�B�b�N�X���
	virtual ~DirectGraphics();
	static void CreateInstance(HWND hWnd);

	static DirectGraphics* GetpInstance() { return pInstance; }
	//�`��̏������֐�
	void RenderInitialization();
	//�`��J�n�֐�
	void StartRender();
	//�V�[���ɉ摜���Z�b�g����֐�
	void Render(char* filepath, CUSTOMVERTEX vertex[]);
	//�`��I���֐�
	void EndRender();
	//2D�摜�ǂݍ��݊֐�
	//�������t�@�C���p�X
	void InitGraphics(char* filepath);
	//�摜���ߓǂݍ��݊֐�
	//�������t�@�C���p�X
	void InitGraphicsPermeation(char* filepath);
	//�摜����ɕ����]��
	//������Ɍ��������摜��CUSTOMVERTEX
	void Direction_Up(CUSTOMVERTEX tmp[]);
	//�摜�����ɕ����]��
	//�������Ɍ��������摜��CUSTOMVERTEX
	void Direction_Down(CUSTOMVERTEX tmp[]);
	//�摜���E�ɕ����]��
	//�����E�Ɍ��������摜��CUSTOMVERTEX
	void Direction_Right(CUSTOMVERTEX tmp[]);
	//�摜�����ɕ����]��
	//�������Ɍ��������摜��CUSTOMVERTEX
	void Direction_Left(CUSTOMVERTEX tmp[]);


	void AnimationTv(CUSTOMVERTEX tmp[], float tv);
	void Animation(CUSTOMVERTEX tmp[], float tu, int animNum, float tv, int animDown);
	void AnimationTu(CUSTOMVERTEX tmp[], float tu, int animNum);
	void TrimingVertex(CUSTOMVERTEX vertex[], float leftTopTu, float leftTopTv, float width, float height, float pngWidth, float pngHeight);
#ifdef DEBUG_RUN
	void DebugDrawBox(CUSTOMVERTEX vertex[]);
#endif

private:
	//2D�O���t�B�b�N�X����
	DirectGraphics(HWND hWnd);
	static DirectGraphics* pInstance;
	// DirectX�I�u�W�F�N�g�̃|�C���^
	LPDIRECT3D9			m_pDirect3D = NULL;	
	// DirectX�f�o�C�X�̃|�C���^
	LPDIRECT3DDEVICE9	m_pDirect3DDevice = NULL;
	//�ǂݍ��񂾉摜�ێ�����
	std::map<std::string, LPDIRECT3DTEXTURE9> m_Texture;
};

#endif 