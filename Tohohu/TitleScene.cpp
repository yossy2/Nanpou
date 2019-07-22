#include <DxLib.h>
#include "main.h"
#include "TitleScene.h"

// �Ұ�ޗp
int menuImage[MENU_NUM];			// �ްѽ���

// ���ټ�ݏ�����
bool TitleInit(void)
{
	bool rtnFlag = true;

	for (int i = 0; i < MENU_NUM; i++)
	{
		if (LoadDivGraph("image/menu.png", MENU_NUM, 1, MENU_NUM, MENU_IMAGE_SIZE_X, MENU_IMAGE_SIZE_Y, menuImage) == -1)
		{
			AST();
			rtnFlag = false;
		}
	}

	return rtnFlag;
}

// ���ټ�ݏ���
void TitleScene(void)
{
	TitleDraw();
}

// ���ټ�ݕ`��
void TitleDraw(void)
{
	ClsDrawScreen();

	for (int i = 0; i < MENU_NUM; i++)
	{
		DrawGraph((SCREEN_SIZE_X - MENU_IMAGE_SIZE_X) / 2, 400 + ((MENU_IMAGE_SIZE_Y + 20) * i), menuImage[i], true);
	}

	ScreenFlip();
}