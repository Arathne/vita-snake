#include "Input.h"

SceCtrlData Input::previous_;
SceCtrlData Input::data_;

void Input::mode (SceCtrlPadInputMode mode)
{
	sceCtrlSetSamplingMode(mode);
}

void Input::poll (void)
{
	previous_ = data_;
	sceCtrlPeekBufferPositive(0, &data_, 1);	
}

bool Input::active (SceCtrlButtons button)
{
	if (data_.buttons == button)
		return true;

	return false;
}

bool Input::began (SceCtrlButtons button)
{
	if (data_.buttons == button && !(previous_.buttons == button))
		return true;

	return false;
}

bool Input::ended (SceCtrlButtons button)
{
	if (!(data_.buttons == button) && previous_.buttons == button)
		return true;

	return false;
}
