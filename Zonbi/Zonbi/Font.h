#ifndef FONT_H
#define FONT_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include"DirectGraphics.h"

class Font
{
public:
	struct Size {
		const int m_Width
			= 56;
		const int m_Height = 56;
		const int m_PngSize = 1024;
	};
	static Font& GetpInstance()
	{
		static Font* m_pInstance = nullptr;
		if (m_pInstance == nullptr) {
			m_pInstance = new Font();
		}
		return *m_pInstance;
	}
	Size* GetSize() { return &m_Size; }
	
	~Font();
	void TrimingVertex(CUSTOMVERTEX vertex[],
		float leftTopTu, float leftTopTv,
		float width, float height,
		float pngWidth, float pngHeight);
	CUSTOMVERTEX* GetUV(const char ch, CUSTOMVERTEX* vertex);
private:
	Font();
	Size m_Size;
};

#endif