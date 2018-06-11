#include "Font.h"

Font::Font()
{
}


Font::~Font()
{
}

void Font::TrimingVertex(CUSTOMVERTEX vertex[], float leftTopTu, float leftTopTv, float width, float height, float pngWidth, float pngHeight) {
	vertex[0].tu = leftTopTu / pngWidth;
	vertex[0].tv = leftTopTv / pngHeight;

	vertex[1].tu = (leftTopTu + width) / pngWidth;
	vertex[1].tv = leftTopTv / pngHeight;

	vertex[2].tu = (leftTopTu + width) / pngWidth;
	vertex[2].tv = (leftTopTv + height) / pngHeight;

	vertex[3].tu = leftTopTu / pngWidth;
	vertex[3].tv = (leftTopTv + height) / pngHeight;

}

CUSTOMVERTEX* Font::GetUV(const char ch, CUSTOMVERTEX* vertex)
{
	switch (ch) {
	/*case 'A':
		TrimingVertex(vertex, m_Size.m_Width * 0, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'B':
		TrimingVertex(vertex, m_Size.m_Width * 1, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'C':
		TrimingVertex(vertex, m_Size.m_Width * 2, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'D':
		TrimingVertex(vertex, m_Size.m_Width * 3, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'E':
		TrimingVertex(vertex, m_Size.m_Width * 4, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'F':
		TrimingVertex(vertex, m_Size.m_Width * 5, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'G':
		TrimingVertex(vertex, m_Size.m_Width * 6, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'H':
		TrimingVertex(vertex, m_Size.m_Width * 7, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'I':
		TrimingVertex(vertex, m_Size.m_Width * 8, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'J':
		TrimingVertex(vertex, m_Size.m_Width * 9, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'K':
		TrimingVertex(vertex, m_Size.m_Width * 10, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'L':
		TrimingVertex(vertex, m_Size.m_Width * 11, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'M':
		TrimingVertex(vertex, m_Size.m_Width * 12, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'N':
		TrimingVertex(vertex, m_Size.m_Width * 13, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'O':
		TrimingVertex(vertex, m_Size.m_Width * 14, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'P':
		TrimingVertex(vertex, m_Size.m_Width * 15, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'Q':
		TrimingVertex(vertex, m_Size.m_Width * 16, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'R':
		TrimingVertex(vertex, m_Size.m_Width * 17, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'S':
		TrimingVertex(vertex, m_Size.m_Width * 0, m_Size.m_Height * 1, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'T':
		TrimingVertex(vertex, m_Size.m_Width * 1, m_Size.m_Height * 1, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'U':
		TrimingVertex(vertex, m_Size.m_Width * 2, m_Size.m_Height * 1, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'V':
		TrimingVertex(vertex, m_Size.m_Width * 3, m_Size.m_Height * 1, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'W':
		TrimingVertex(vertex, m_Size.m_Width * 4, m_Size.m_Height * 1, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'X':
		TrimingVertex(vertex, m_Size.m_Width * 5, m_Size.m_Height * 1, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'Y':
		TrimingVertex(vertex, m_Size.m_Width * 6, m_Size.m_Height * 1, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'Z':
		TrimingVertex(vertex, m_Size.m_Width * 7, m_Size.m_Height * 1, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'a':
		TrimingVertex(vertex, m_Size.m_Width * 0, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'b':
		TrimingVertex(vertex, m_Size.m_Width * 1, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'c':
		TrimingVertex(vertex, m_Size.m_Width * 2, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'd':
		TrimingVertex(vertex, m_Size.m_Width * 3, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'e':
		TrimingVertex(vertex, m_Size.m_Width * 4, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'f':
		TrimingVertex(vertex, m_Size.m_Width * 5, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'g':
		TrimingVertex(vertex, m_Size.m_Width * 6, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'h':
		TrimingVertex(vertex, m_Size.m_Width * 7, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'i':
		TrimingVertex(vertex, m_Size.m_Width * 8, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'j':
		TrimingVertex(vertex, m_Size.m_Width * 9, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'k':
		TrimingVertex(vertex, m_Size.m_Width * 10, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'l':
		TrimingVertex(vertex, m_Size.m_Width * 11, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'm':
		TrimingVertex(vertex, m_Size.m_Width * 12, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'n':
		TrimingVertex(vertex, m_Size.m_Width * 13, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'o':
		TrimingVertex(vertex, m_Size.m_Width * 14, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'p':
		TrimingVertex(vertex, m_Size.m_Width * 15, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'q':
		TrimingVertex(vertex, m_Size.m_Width * 16, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'r':
		TrimingVertex(vertex, m_Size.m_Width * 17, m_Size.m_Height * 2, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 's':
		TrimingVertex(vertex, m_Size.m_Width * 0, m_Size.m_Height * 3, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 't':
		TrimingVertex(vertex, m_Size.m_Width * 1, m_Size.m_Height * 3, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'u':
		TrimingVertex(vertex, m_Size.m_Width * 2, m_Size.m_Height * 3, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'v':
		TrimingVertex(vertex, m_Size.m_Width * 3, m_Size.m_Height * 3, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'w':
		TrimingVertex(vertex, m_Size.m_Width * 4, m_Size.m_Height * 3, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'x':
		TrimingVertex(vertex, m_Size.m_Width * 5, m_Size.m_Height * 3, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'y':
		TrimingVertex(vertex, m_Size.m_Width * 6, m_Size.m_Height * 3, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case 'z':
		TrimingVertex(vertex, m_Size.m_Width * 7, m_Size.m_Height * 3, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;*/

	case '0':
		TrimingVertex(vertex, m_Size.m_Width * 0, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case '1':
		TrimingVertex(vertex, m_Size.m_Width * 1, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case '2':
		TrimingVertex(vertex, m_Size.m_Width * 2, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case '3':
		TrimingVertex(vertex, m_Size.m_Width * 3, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case '4':
		TrimingVertex(vertex, m_Size.m_Width * 4, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case '5':
		TrimingVertex(vertex, m_Size.m_Width * 5, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case '6':
		TrimingVertex(vertex, m_Size.m_Width * 6, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case '7':
		TrimingVertex(vertex, m_Size.m_Width * 7, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case '8':
		TrimingVertex(vertex, m_Size.m_Width * 8, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case '9':
		TrimingVertex(vertex, m_Size.m_Width * 9, m_Size.m_Height * 0, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case '!':
		TrimingVertex(vertex, m_Size.m_Width * 10 , m_Size.m_Height * 4, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case '?':
		TrimingVertex(vertex, m_Size.m_Width * 11, m_Size.m_Height * 4, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case '+':
		TrimingVertex(vertex, m_Size.m_Width * 12 ,m_Size.m_Height * 4, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case '*':
		TrimingVertex(vertex, m_Size.m_Width * 13, m_Size.m_Height * 4, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case ':':
		TrimingVertex(vertex, m_Size.m_Width * 14 , m_Size.m_Height * 4, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	case '/':
		TrimingVertex(vertex, m_Size.m_Width * 15 , m_Size.m_Height * 4, m_Size.m_Width, m_Size.m_Height, m_Size.m_PngSize, m_Size.m_PngSize);
		break;

	}
	return vertex;
}