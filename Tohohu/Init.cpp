#include "DxLib.h"
#include "main.h"
#include "Init.h"
#include "GameScene.h"

// ���ьn������
bool SysInit(void)
{
	bool rtnFlag = true;

	// ---------- ���я���
	SetWindowText("�e��");

	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);
	if (DxLib_Init() == -1)
	{
		AST();
		return false;
	}
	
	SetDrawScreen(DX_SCREEN_BACK);

	// �ϐ�������
	sceneFunc = GameScene;
	flamCnt = 0;

	GameInit();

	return rtnFlag;
}