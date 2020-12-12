#ifndef INPUT_H
#define INPUT_H

#include <psp2/ctrl.h>

enum CONTROLLER { UP, DOWN, LEFT, RIGHT, CROSS, CIRCLE };

class Input
{
	public:
		static void mode (SceCtrlPadInputMode mode);
		static void poll (void);
		static bool isActive (CONTROLLER button);

	private:
		static SceCtrlData data_;
};

#endif
