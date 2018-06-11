#ifndef UTILITY_H
#define UTILITY_H

//-----------------------------------------------------------------------------------------
//include
//-----------------------------------------------------------------------------------------
#include<d3dx9.h>

namespace Utility {

	enum struct BUTTON_STATE {
		OFF,	//!< �O�t���[�����痣����Ă�����
		ON,		//!< �O�t���[�����牟����Ă�����
		PUSH,	//!< ���t���[�����牟���ꂽ���
		RELEASE	//!< ���t���[�����痣���ꂽ���
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
		BUTTON_STATE LeftMouse;		//!< �}�E�X�̍��N���b�N�̏��
		BUTTON_STATE RightMouse;	//!< �}�E�X�̉E�N���b�N�̏��
	};

	char TransformChar(int val);
}
#endif
