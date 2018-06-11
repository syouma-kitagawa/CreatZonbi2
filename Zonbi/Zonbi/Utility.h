#ifndef UTILITY_H
#define UTILITY_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include<d3dx9.h>

namespace Utility {

	enum struct BUTTON_STATE {
		OFF,	//!< 前フレームから離されている状態
		ON,		//!< 前フレームから押されている状態
		PUSH,	//!< 現フレームから押された状態
		RELEASE	//!< 現フレームから離された状態
	};

	enum struct KEY_KIND
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,
		KEY_0,
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
		SPACE,
		LSHIFT,
		RSHIFT,
		LCONTROL,
		RCONTROL,
		ESC,
		ENTER,
		MAX
	};

	struct MouseData {
		D3DXVECTOR3 Movement;
		BUTTON_STATE LeftMouse;		//!< マウスの左クリックの状態
		BUTTON_STATE RightMouse;	//!< マウスの右クリックの状態
	};

	char TransformChar(int val);
}
#endif
