#include <psp2/kernel/processmgr.h>

#include "src/States/StateManager.h"
#include "src/GameRenderer.h"
#include "src/Log.h"

int main()
{
	GameRenderer::init();
	Log::render(GameRenderer::getRenderer(), 10);	

	bool run = true;
	while (run)
	{
		StateManager::process();
	}
	
	Log::destroy();
	StateManager::destroy();
	GameRenderer::destroy();

	sceKernelExitProcess(0);
}
