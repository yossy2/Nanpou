#include "DxLib.h"
#include "main.h"
#include "GameScene.h"
#include "ResultScene.h"
#include "TitleScene.h"
#include "UiManeger.h"
#include "Player.h"
#include <Chapter1/Chapter1.h>

// =============≤“∞ºﬁóp=====================
int gameClearImage;		// πﬁ∞—∏ÿ±ÇÃ€∫ﬁ
int gameOverImage;			// πﬁ∞—µ∞ ﬁ∞ÇÃ€∫ﬁ
int lifeLogoImg;			// ◊≤Ã€∫ﬁ
int powLogoImg;			//  ﬂ‹∞€∫ﬁ
int symbImg[2];				// ïÑçÜ
int totalImg;				// ƒ∞¿Ÿ€∫ﬁ
int oldScore;				// πﬁ∞—∏ÿ±Ç‹ÇΩÇÕπﬁ∞—µ∞ ﬁ∞éûÇÃΩ∫±
int totalScore;			// ƒ∞¿Ÿ€∫ﬁ
bool resSceneFlag;			// ÿªﬁŸƒï\é¶íÜÇ…º∞›à⁄çsÇµÇ»Ç¢

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
	// ◊≤Ã
	if ((lifeLogoImg = LoadGraph("image/life.png")) == -1)
	{
		AST();
		return;
	}
	//  ﬂ‹∞
	if ((powLogoImg = LoadGraph("image/power.png")) == -1)
	{
		AST();
		return;
	}
	// ïÑçÜ
	if (LoadDivGraph("image/symbol.png", 2, 2, 1, 30, 40, symbImg) == -1)
	{
		AST();
		return;
	}
	// ƒ∞¿Ÿ€∫ﬁ
	if ((totalImg = LoadGraph("image/total.png")) == -1)
	{
		AST();
		return;
	}

	resSceneFlag = false;
	oldScore = score;
	totalScore = score + (player.life * 1000) + (player.power * 100);
	CheckClear = flag;
	sceneFunc = ResultScene;
}

// èàóù
void ResultScene(void)
{
	ResultSceDraw(CheckClear);
	if (keyFram[KEY_INPUT_Z] == 1 && resSceneFlag)
	{
		StopBgm();
		TitleInit();
	}
}

// ï`âÊ
void ResultSceDraw(bool flag)
{
	GraphFilter(gameScreen, DX_GRAPH_FILTER_GAUSS, 16, 100);
	ClsDrawScreen();
	
	DrawGraph(0, 0, systemImg, true);
	DrawGraphF(GAME_SCREEN_X, GAME_SCREEN_Y, gameScreen, true);

	if (flag)
	{
		DrawGraphF(GAME_SCREEN_X + (GAME_SCREEN_SIZE_X - RESULT_LOGO_SIZE_X) / 2, GAME_SCREEN_Y + 80, gameClearImage, true);
	}
	else
	{
		DrawGraphF(GAME_SCREEN_X + (GAME_SCREEN_SIZE_X - RESULT_LOGO_SIZE_X) / 2, GAME_SCREEN_Y + 80, gameOverImage, true);
	}

	DrawGraphF(GAME_SCREEN_X + 80, GAME_SCREEN_Y + 270, scoreImage, true);

	int tmpNum = oldScore;

	for (int i = 0; i < SCORE_NUM; i++)
	{
		int drawNum = tmpNum % 10;
		DrawGraphF((GAME_SCREEN_SIZE_X - 50) - SCORE_NUM_SIZE_X - (SCORE_NUM_SIZE_X * i), GAME_SCREEN_Y + 300, scoreNumImage[drawNum], true);
		tmpNum = (tmpNum - drawNum) / 10;
	}

	if (framCnt >= 180)
	{
		DrawGraphF(GAME_SCREEN_X + 70, GAME_SCREEN_Y + 400, lifeLogoImg, true);
		DrawGraphF(GAME_SCREEN_X + 200, GAME_SCREEN_Y + 400, scoreNumImage[player.life], true);
	}
	if (framCnt >= 210)
	{
		DrawGraphF(GAME_SCREEN_X + 250, GAME_SCREEN_Y + 400, symbImg[0], true);
		// èÊéZÇÃäÓêîÇï\é¶
		tmpNum = 1000;
		for (int i = 0; i < 4; i++)
		{
			int drawNum = tmpNum % 10;
			DrawGraphF(((GAME_SCREEN_X + 280) + SCORE_NUM_SIZE_X * 4) - (SCORE_NUM_SIZE_X * i), GAME_SCREEN_Y + 400, scoreNumImage[drawNum], true);
			tmpNum = (tmpNum - drawNum) / 10;
		}
	}
	if (framCnt >= 270)
	{
		DrawGraphF(GAME_SCREEN_X + 400, GAME_SCREEN_Y + 450, symbImg[1], true);
		// â¡éZÇ∑ÇÈΩ∫±Çï\é¶
		tmpNum = 1000 * player.life;
		for (int i = 0; i < 4; i++)
		{
			int drawNum = tmpNum % 10;
			DrawGraphF(((GAME_SCREEN_X + 450) + SCORE_NUM_SIZE_X * 4) - (SCORE_NUM_SIZE_X * i), GAME_SCREEN_Y + 450, scoreNumImage[drawNum], true);
			tmpNum = (tmpNum - drawNum) / 10;
		}
	}
	if (framCnt >= 330)
	{
		tmpNum = player.power;
		//  ﬂ‹∞€∫ﬁÇÃï\é¶
		DrawGraphF(GAME_SCREEN_X + 70, GAME_SCREEN_Y + 500, powLogoImg, true);
		for (int i = 0; i < 3; i++)
		{
			int drawNum = tmpNum % 10;
			DrawGraphF(((GAME_SCREEN_X + 230) + SCORE_NUM_SIZE_X * 3) - (SCORE_NUM_SIZE_X * i), 
				GAME_SCREEN_Y + 500, scoreNumImage[drawNum], true);
			tmpNum = (tmpNum - drawNum) / 10;
		}
	}
	if (framCnt >= 360)
	{
		DrawGraphF(GAME_SCREEN_X + 390, GAME_SCREEN_Y + 500, symbImg[0], true);
		// â¡éZÇÃäÓêîÇï\é¶
		tmpNum = 100;
		for (int i = 0; i < 3; i++)
		{
			int drawNum = tmpNum % 10;
			DrawGraphF(((GAME_SCREEN_X + 420) + SCORE_NUM_SIZE_X * 3) - (SCORE_NUM_SIZE_X * i), 
				GAME_SCREEN_Y + 500, scoreNumImage[drawNum], true);
			tmpNum = (tmpNum - drawNum) / 10;
		}
	}
	if (framCnt >= 420)
	{
		DrawGraphF(GAME_SCREEN_X + 304, GAME_SCREEN_Y + 550, symbImg[1], true);
		tmpNum = 100 * player.power;
		for (int i = 0; i < 7; i++)
		{
			int drawNum = tmpNum % 10;
			DrawGraphF(((GAME_SCREEN_X + 354) + SCORE_NUM_SIZE_X * 7) - (SCORE_NUM_SIZE_X * i), GAME_SCREEN_Y + 550, scoreNumImage[drawNum], true);
			tmpNum = (tmpNum - drawNum) / 10;
		}
	}
	if (framCnt >= 510)
	{
		DrawGraphF(GAME_SCREEN_X + 60, GAME_SCREEN_Y + 600, totalImg, true);
		tmpNum = (score >= 10000000000 ? 9999999999 : score);

		for (int i = 0; i < SCORE_NUM; i++)
		{
			int drawNum = tmpNum % 10;
			DrawGraphF((GAME_SCREEN_SIZE_X - 50) - SCORE_NUM_SIZE_X - (SCORE_NUM_SIZE_X * i), GAME_SCREEN_Y + 600, scoreNumImage[drawNum], true);
			tmpNum = (tmpNum - drawNum) / 10;
		}
	}
	if (framCnt >= 570)
	{
		if (score < totalScore)
		{
			ScoreUpdate(100);
		}
		else
		{
			resSceneFlag = true;
		}
	}

	DrawScore();

	ScreenFlip();
}