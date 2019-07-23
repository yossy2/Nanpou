#include <DxLib.h>
#include "main.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "Player.h"

// ²Ò°¼Ş—p
int titleBgImage;					// À²ÄÙ‚Ì”wŒi
int menuImage[MENU_ID_MAX];		// ÒÆ­°ˆê——
int menuGuideImage;				// ÒÆ­°‚Ì¶Ş²ÄŞ×²İ

// ²Ò°¼Ş‚ÌŠg‘å—p
float rate;
bool rateFlag;

// ÒÆ­°ŠÖ˜A
MENU_ID menuID;						// ÒÆ­°‚ÌŠÇ—

// À²ÄÙ¼°İ‰Šú‰»
bool TitleInit(void)
{
	bool rtnFlag = true;

	// ”wŒi
	if ((titleBgImage = LoadGraph("image/titlebg.png")) == -1)
	{
		AST();
		rtnFlag = false;
	}

	// ÒÆ­°‰æ‘œ
	for (int i = 0; i < MENU_ID_MAX; i++)
	{
		if (LoadDivGraph("image/menu.png", MENU_ID_MAX, 1, MENU_ID_MAX, MENU_IMAGE_SIZE_X, MENU_IMAGE_SIZE_Y, menuImage) == -1)
		{
			AST();
			rtnFlag = false;
		}
	}

	// ÒÆ­°‚Ì˜g
	if ((menuGuideImage = LoadGraph("image/menuguideline.png")) == -1)
	{
		AST();
		rtnFlag = false;
	}

	PlayerInit();
	rate = 1.0f;
	rateFlag = true;

	return rtnFlag;
}

// À²ÄÙ¼°İˆ—
void TitleScene(void)
{
	if (keyFram[KEY_INPUT_UP] == 1)
	{
		menuID = (MENU_ID)(menuID - 1);
		if (menuID < 0)
		{
			menuID = EXIT_ID;
		}
		rate = 1.0f;
	}
	else if (keyFram[KEY_INPUT_DOWN] == 1)
	{
		menuID = (MENU_ID)(menuID + 1);
		if (menuID >= MENU_ID_MAX)
		{
			menuID = GAMESTART_ID;
		}
		rate = 1.0f;
	}

	TitleDraw();

	if (keyFram[keyList.shot] == 1)
	{
		switch (menuID)
		{
		case GAMESTART_ID:
			GameInit();
			break;
		case CONFIG_ID:
			break;
		case EXIT_ID:
			keyFram[KEY_INPUT_ESCAPE] = 1;
			break;
		default:
			AST();
			break;
		}

	}
}

// À²ÄÙ¼°İ•`‰æ
void TitleDraw(void)
{
	if (framCnt % 3 == 0 && rateFlag)
	{
		rate -= 0.01;
		if (rate < 0.8)
		{
			rateFlag = false;
		}
	}
	else if (framCnt % 3 == 0 && !rateFlag)
	{
		rate += 0.01;
		if (rate >= 1.0)
		{
			rateFlag = true;
		}
	}

	ClsDrawScreen();

	DrawGraph(0, 0, titleBgImage, false);

	for (int i = 0; i < MENU_ID_MAX; i++)
	{
		if (menuID != i)
		{
			DrawGraph((SCREEN_SIZE_X - MENU_IMAGE_SIZE_X) / 2, 400 + ((MENU_IMAGE_SIZE_Y + 20) * i), menuImage[i], true);
		}
	}

	DrawRotaGraph(SCREEN_SIZE_X / 2, 400 + MENU_IMAGE_SIZE_Y / 2 + ((MENU_IMAGE_SIZE_Y + 20) * menuID), rate, 0.0f, menuImage[menuID], true, false);

	DrawGraph((SCREEN_SIZE_X - MENU_IMAGE_SIZE_X) / 2, 400 + ((MENU_IMAGE_SIZE_Y + 20) * menuID), menuGuideImage, true);

	ScreenFlip();
}