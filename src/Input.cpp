#include "Input.h"

SceCtrlData Input::data_;

void Input::mode (SceCtrlPadInputMode mode)
{
	sceCtrlSetSamplingMode( mode );
}

void Input::poll (void)
{
	sceCtrlPeekBufferPositive(0, &data_, 1);	
}

bool Input::isActive (CONTROLLER button)
{
	bool active = false;
	
	if (button == UP && data_.buttons == SCE_CTRL_UP)
		active = true;
	else if (button == DOWN && data_.buttons == SCE_CTRL_DOWN)
		active = true;
	else if (button == LEFT && data_.buttons == SCE_CTRL_LEFT)
		active = true;
	else if (button == RIGHT && data_.buttons == SCE_CTRL_RIGHT)
		active = true;
	else if (button == CROSS && data_.buttons == SCE_CTRL_CROSS)
		active = true;
	else if (button == CIRCLE && data_.buttons == SCE_CTRL_CIRCLE)
		active = true;

	return active;
}
