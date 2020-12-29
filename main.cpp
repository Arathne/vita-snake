#include <psp2/kernel/processmgr.h>

#include "src/States/StateManager.h"
#include "src/GameRenderer.h"
#include "src/Input.h"

bool checkRun (void);

int main()
{
	bool run = true;
	while (run)
	{
		run = checkRun();
		Input::poll();
		StateManager::process();
	}
	
	sceKernelExitProcess(0);
}

bool checkRun (void)
{
	bool run = true;
	SDL_Event event;

	while (SDL_PollEvent(&event)) 
	{
		if (event.type == SDL_QUIT)
			run = false;
	}

	return run;
}
