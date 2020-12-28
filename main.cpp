#include <psp2/kernel/processmgr.h>

#include "src/States/StateManager.h"
#include "src/GameRenderer.h"
#include "src/Log.h"
#include "src/Input.h"

int main()
{
	Log::setRenderer(GameRenderer::getRenderer());
	Log::add("Initialized");

	bool run = true;
	while (run)
	{
		Input::poll();
		StateManager::process();
	}
	
	StateManager::destroy();

	sceKernelExitProcess(0);
}
