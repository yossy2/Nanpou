#include "DxLib.h"
#include "main.h"
#include "GameScene.h"
#include "ResultScene.h"
#include "TitleScene.h"

int gameClearImage;		// πﬁ∞—∏ÿ±ÇÃ€∫ﬁ
int gameOverImage;			// πﬁ∞—µ∞ ﬁ∞ÇÃ€∫ﬁ

bool CheckClear;			// πﬁ∞—∏ÿ±Ç©Ç«Ç§Ç©Çπﬁ∞—º∞›Ç©ÇÁéÛÇØéÊÇÈ

// èâä˙âª
void ResultInit(bool flag)
{
	// ================≤“∞ºﬁìoò^
	// πﬁ∞—∏ÿ±€∫ﬁ
	if ((gameClearImage = LoadGraph("image/gameclear.png")) == -1)
	{
		AST();
		return;
	}
	// πﬁ∞—µ∞ ﬁ∞€∫ﬁ
	if ((gameOverImage = LoadGraph("image/gameover.png")) == -1)
	{
		AST();
		return;
	}

	CheckClear = flag;
	sceneFunc = ResultScene;
}

// èàóù
void ResultScene(void)
{
	ResultSceDraw(CheckClear);
	if (keyFram[KEY_INPUT_Z] == 1)
	{
		TitleInit();
	}
}

// ï`âÊ
void ResultSceDraw(bool flag)
{
	ClsDrawScreen();
	DrawGraph(GAME_SCREEN_X, GAME_SCREEN_Y, gameScreen, true);

	if (flag)
	{
		DrawGraph(0, 0, gameClearImage, true);
	}
	else
	{
		DrawGraph(0, 0, gameOverImage, true);
	}
	ScreenFlip();
}