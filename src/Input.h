#ifndef INPUT_H
#define INPUT_H

#include <psp2/ctrl.h>

class Input
{
	public:
		~Input (void);		

		static void poll (void);
		
		static bool active (SceCtrlButtons button);
		static bool began (SceCtrlButtons button);
		static bool ended (SceCtrlButtons button);

	private:
		static Input instance;
		Input (void);

		SceCtrlData previous_;
		SceCtrlData data_;
};

#endif
