#ifndef DIRECTGRAPHICS_H
#define DIRECTGRAPHICS_H

//シングルトンクラス

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
	//2Dグラフィックス解放
	virtual ~DirectGraphics();
	static void CreateInstance(HWND hWnd);

	static DirectGraphics* GetpInstance() { return pInstance; }
	//描画の初期化関数
	void RenderInitialization();
	//描画開始関数
	void StartRender();
	//シーンに画像をセットする関数
	void Render(char* filepath, CUSTOMVERTEX vertex[]);
	//描画終了関数
	void EndRender();
	//2D画像読み込み関数
	//第一引数ファイルパス
	void InitGraphics(char* filepath);
	//画像透過読み込み関数
	//第一引数ファイルパス
	void InitGraphicsPermeation(char* filepath);
	//画像を上に方向転換
	//引数上に向けたい画像のCUSTOMVERTEX
	void Direction_Up(CUSTOMVERTEX tmp[]);
	//画像を下に方向転換
	//引数下に向けたい画像のCUSTOMVERTEX
	void Direction_Down(CUSTOMVERTEX tmp[]);
	//画像を右に方向転換
	//引数右に向けたい画像のCUSTOMVERTEX
	void Direction_Right(CUSTOMVERTEX tmp[]);
	//画像を左に方向転換
	//引数左に向けたい画像のCUSTOMVERTEX
	void Direction_Left(CUSTOMVERTEX tmp[]);


	void AnimationTv(CUSTOMVERTEX tmp[], float tv);
	void Animation(CUSTOMVERTEX tmp[], float tu, int animNum, float tv, int animDown);
	void AnimationTu(CUSTOMVERTEX tmp[], float tu, int animNum);
	void TrimingVertex(CUSTOMVERTEX vertex[], float leftTopTu, float leftTopTv, float width, float height, float pngWidth, float pngHeight);
#ifdef DEBUG_RUN
	void DebugDrawBox(CUSTOMVERTEX vertex[]);
#endif

private:
	//2Dグラフィックス生成
	DirectGraphics(HWND hWnd);
	static DirectGraphics* pInstance;
	// DirectXオブジェクトのポインタ
	LPDIRECT3D9			m_pDirect3D = NULL;	
	// DirectXデバイスのポインタ
	LPDIRECT3DDEVICE9	m_pDirect3DDevice = NULL;
	//読み込んだ画像保持する
	std::map<std::string, LPDIRECT3DTEXTURE9> m_Texture;
};

#endif 