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
		// �ڰѶ��ĊǗ�
		if (sceneOldFunc != sceneFunc)
		{
			flamCnt = 2400;
		}
		sceneOldFunc = sceneFunc;

		sceneFunc();
		flamCnt++;
	}

	DxLib_End();

	return 0;
}

// �����蔻��
bool CheckHitObj(Vector2 aPos, float arad, Vector2 bPos, float brad)
{
	bool hitFlag = false;
	float x_Len = aPos.x - bPos.x;
	float y_Len = aPos.y - bPos.y;
	float Renge = (x_Len * x_Len) + (y_Len * y_Len);			// ��_�̒��S�̋���

	if (Renge < (arad + brad) * (arad + brad))
	{
		hitFlag = true;
	}

	return hitFlag;
}

// ��ʊO����
bool isMoveOut(Vector2 pos)
{
	// ��ʊO����
	if (pos.x < -100 ||
		pos.x >(float)(GAME_SCREEN_SIZE_X) + 100 ||
		pos.y < -100 ||
		pos.y >(float)(GAME_SCREEN_SIZE_Y) + 100)
	{
		return true;
	}

	return false;
}