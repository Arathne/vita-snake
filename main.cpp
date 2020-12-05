#include <psp2/kernel/processmgr.h>
#include "src/GameRenderer.h"

int main()
{
	GameRenderer::init();

	bool run = true;
	while (run)
	{
		GameRenderer::clear();
		GameRenderer::drawRect(30, 30, 100, 100);
		GameRenderer::present();
	}
	
	GameRenderer::destroy();

	sceKernelExitProcess(0);
	return 0;
}
