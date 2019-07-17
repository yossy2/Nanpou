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
		// ÌÚ°Ñ¶³İÄŠÇ—
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

// “–‚½‚è”»’è
bool CheckHitObj(Vector2 aPos, float arad, Vector2 bPos, float brad)
{
	bool hitFlag = false;
	float x_Len = aPos.x - bPos.x;
	float y_Len = aPos.y - bPos.y;
	float Renge = (x_Len * x_Len) + (y_Len * y_Len);			// “ñ“_‚Ì’†S‚Ì‹——£

	if (Renge < (arad + brad) * (arad + brad))
	{
		hitFlag = true;
	}

	return hitFlag;
}