#include <psp2/kernel/processmgr.h>

#include "src/States/StateManager.h"
#include "src/GameRenderer.h"
#include "src/Log.h"
#include "src/Input.h"

int main()
{
	GameRenderer::init();
	Log::render(GameRenderer::getRenderer(), 10);	
	Log::add("initialized");
	Input::mode(SCE_CTRL_MODE_DIGITAL);

	bool run = true;
	while (run)
	{
		Input::poll();
		StateManager::process();
	}
	
	Log::destroy();
	StateManager::destroy();
	GameRenderer::destroy();

	sceKernelExitProcess(0);
}
