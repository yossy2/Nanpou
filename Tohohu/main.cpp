#define MAIN_DEF

#include <DxLib.h>
#include "main.h"
#include "Init.h"
#include "TitleScene.h"
#include "GameScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (!SysInit())
	{
		return -1;
	}

	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		// Ã⁄∞—∂≥›ƒä«óù
		if (sceneOldFunc != sceneFunc)
		{
			flamCnt = 0;
		}
		sceneOldFunc = sceneFunc;

		sceneFunc();
		flamCnt++;
	}

	DxLib_End();

	return 0;
}