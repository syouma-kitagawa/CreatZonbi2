#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <vector>
#include <stdio.h>

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
	//描画の初期化関数
	void RenderInitialization();
	//描画開始関数
	void StartRender();
	//シーンに画像をセットする関数
	void Render(int* textureid, CUSTOMVERTEX vertex[]);
	//描画終了関数
	void EndRender();
	//2D画像読み込み関数
	//第一引数ファイルパス
	//第二引数画像を置く場所
	void InitGraphics(char* filepath, int* texture);
	void InitGraphicsPermeation(char* filepath, int* texture);
	//画像を上に方向転換
	//引数上に向けたい画像のCUSTOMVERTEX
	void Direction_Up(CUSTOMVERTEX Tmp[]);
	//画像を下に方向転換
	//引数下に向けたい画像のCUSTOMVERTEX
	void Direction_Down(CUSTOMVERTEX Tmp[]);
	//画像を右に方向転換
	//引数右に向けたい画像のCUSTOMVERTEX
	void Direction_Right(CUSTOMVERTEX Tmp[]);
	//画像を左に方向転換
	//引数左に向けたい画像のCUSTOMVERTEX
	void Direction_Left(CUSTOMVERTEX Tmp[]);
	//統合ファイルのアニメーション
	//第一引数アニメーションさせたい統合ファイルのCUSTOMVERTEX
	//第二引数アニメーションさせたい統合ファイルのTUの値
	//第三引数アニメーションさせたい統合ファイルをどれだけずらすか
	void Animation(CUSTOMVERTEX Tmp[], float Tuint, int RightSlide);
	static DirectGraphics* GetpInstance() { return pInstance; }
private:
	//2Dグラフィックス生成
	DirectGraphics(HWND hWnd);
	static DirectGraphics* pInstance;
	LPDIRECT3D9			m_pDirect3D = NULL;		// DirectXオブジェクトのポインタ
	LPDIRECT3DDEVICE9	m_pDirect3DDevice = NULL;	// DirectXデバイスのポインタ
	std::vector<LPDIRECT3DTEXTURE9> m_pTexture;
	std::vector<char*> m_FileName;
};