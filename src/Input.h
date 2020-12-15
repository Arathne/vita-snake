#ifndef INPUT_H
#define INPUT_H

#include <psp2/ctrl.h>

class Input
{
	public:
		static void mode (SceCtrlPadInputMode mode);
		static void poll (void);
		
		static bool active (SceCtrlButtons button);
		static bool began (SceCtrlButtons button);
		static bool ended (SceCtrlButtons button);

	private:
		static SceCtrlData previous_;
		static SceCtrlData data_;
};

#endif
