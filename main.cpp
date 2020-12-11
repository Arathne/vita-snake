#include <psp2/kernel/processmgr.h>
#include "src/States/StateManager.h"
#include "src/GameRenderer.h"

int main()
{
	GameRenderer::init();

	bool run = true;
	while (run)
	{
		StateManager::process();
	}
	
	StateManager::reset();
	GameRenderer::destroy();

	sceKernelExitProcess(0);
}
