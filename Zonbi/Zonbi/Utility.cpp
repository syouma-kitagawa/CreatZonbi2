#include"Utility.h"

char Utility::TransformChar(int val)
{
	char ret;

	switch (val) {
	case 0:
		ret = '0';
		break;
		
	case 1:
		ret = '1';
		break;

	case 2:
		ret = '2';
		break;

	case 3:
		ret = '3';
		break;

	case 4:
		ret = '4';
		break;

	case 5:
		ret = '5';
		break;

	case 6:
		ret = '6';
		break;

	case 7:
		ret = '7';
		break;

	case 8:
		ret = '8';
		break;

	case 9:
		ret = '9';
		break;
	}

	return ret;
}