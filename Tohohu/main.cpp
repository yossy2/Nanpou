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

	while (!ProcessMessage() && keyFram[KEY_INPUT_ESCAPE] == 0)
	{
		// ﾌﾚｰﾑｶｳﾝﾄ管理
		if (sceneOldFunc != sceneFunc)
		{
			framCnt = 2000;
		}
		sceneOldFunc = sceneFunc;

		UpdateKeyState();

		sceneFunc();
		framCnt++;
	}
	InitSoundMem();
	DxLib_End();

	return 0;
}

// 当たり判定
bool CheckHitObj(Vector2 aPos, float aRad, Vector2 bPos, float bRad)
{
	bool hitFlag = false;
	float x_Len = aPos.x - bPos.x;
	float y_Len = aPos.y - bPos.y;
	float Renge = (x_Len * x_Len) + (y_Len * y_Len);			// 二点の中心の距離

	if (Renge <= (aRad + bRad) * (aRad + bRad))
	{
		hitFlag = true;
	}

	return hitFlag;
}

// 画面外判定
bool isMoveOut(Vector2 pos)
{
	// 画面外判定
	if (pos.x < -100 ||
		pos.x >(float)(GAME_SCREEN_SIZE_X) + 100 ||
		pos.y < -100 ||
		pos.y >(float)(GAME_SCREEN_SIZE_Y) + 100)
	{
		return true;
	}

	return false;
}

// ｷｰ押下状態更新
void UpdateKeyState(void)
{
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);

	for (int i = 0; i < 256; i++)
	{
		if (tmpKey[i])
		{
			keyFram[i]++;
		}
		else
		{
			keyFram[i] = 0;
		}
	}
}