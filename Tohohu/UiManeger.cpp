#include <DxLib.h>
#include "main.h"
#include "GameScene.h"
#include "UiManeger.h"
#include "Player.h"

// =================変数定義
int highScoreImage;					// ﾊｲｽｺｱ用
int scoreImage;						// ｽｺｱ用
int scoreNumImage[SCORE_NUM];			// ｽｺｱ数字用
int lifeImage[PLAYER_LIFE_STATS];		// 残機ﾊｰﾄ用
int powGaugeImage;						// ﾊﾟﾜｰｹﾞｰｼﾞ
int powGaugeFrameImage;				// ﾊﾟﾜｰｹﾞｰｼﾞのﾌﾚｰﾑ
int powLevelImage;						// ﾚﾍﾞﾙ文字
int highScore;							// ﾊｲｽｺｱ
int score;								// ｽｺｱ

// 初期化
void UiInit(void)
{
	// ===========ｲﾒｰｼﾞ登録
	// ﾊｲｽｺｱ
	if ((highScoreImage = LoadGraph("image/highscore.png")) == -1)
	{
		AST();
		return;
	}
	// ｽｺｱ
	if ((scoreImage = LoadGraph("image/score.png")) == -1)
	{
		AST();
		return;
	}
	// ｽｺｱﾅﾝﾊﾞｰ
	for (int i = 0; i < SCORE_NUM; i++)
	{
		if (LoadDivGraph("image/scorenum.png", SCORE_NUM, SCORE_NUM, 1, SCORE_NUM_SIZE_X, SCORE_NUM_SIZE_Y, scoreNumImage) == -1)
		{
			AST();
			return;
		}
	}
	// 残機のﾊｰﾄ
	for (int i = 0; i < PLAYER_LIFE_STATS; i++)
	{
		if (LoadDivGraph("image/playerlife.png", PLAYER_LIFE_STATS, PLAYER_LIFE_STATS, 1, PLLIFE_SIZE_X, PLLIFE_SIZE_Y, lifeImage) == -1)
		{
			AST();
			return;
		}
	}
	// ﾊﾟﾜｰｹﾞｰｼﾞ
	if ((powGaugeImage = LoadGraph("image/powgauge.png")) == -1)
	{
		AST();
		return;
	}
	// ﾊﾟﾜｰｹﾞｰｼﾞのﾌﾚｰﾑ
	if ((powGaugeFrameImage = LoadGraph("image/powgaugeframe.png")) == -1)
	{
		AST();
		return;
	}
	// ﾚﾍﾞﾙ
	if ((powLevelImage = LoadGraph("image/powerlevel.png")) == -1)
	{
		AST();
		return;
	}

	highScore = HIGHSCORE_DEF;
	score = 0;
}

// ｽｺｱ計算
void ScoreUpdate(int addScr)
{
	score += addScr;
	if (highScore < score)
	{
		highScore = score;
	}
}

// 描画
void DrawScore(void)
{
	DrawGraph(GAME_SCREEN_X + GAME_SCREEN_SIZE_X, 30, highScoreImage, true);

	int scr = (highScore >= 10000000000 ? 9999999999 : highScore);

	for (int i = 0; i < SCORE_NUM; i++)
	{
		int drawNum = scr % 10;
		DrawGraph(SCREEN_SIZE_X - SCORE_NUM_SIZE_X - (SCORE_NUM_SIZE_X * i), 70, scoreNumImage[drawNum], true);
		scr = (scr - drawNum) / 10; 
	}
	DrawGraph(GAME_SCREEN_X + GAME_SCREEN_SIZE_X, 110, scoreImage, true);

	scr = (score >= 10000000000 ? 9999999999 : score);

	for (int i = 0; i < SCORE_NUM; i++)
	{
		int drawNum = scr % 10;
		DrawGraph(SCREEN_SIZE_X - SCORE_NUM_SIZE_X - (SCORE_NUM_SIZE_X * i), 150, scoreNumImage[drawNum], true);
		scr = (scr - drawNum) / 10;
	}
	for (int i = 0; i < PLAYER_DEF_LIFE; i++)
	{
		if (player.life >= i + 1)
		{
			DrawGraph(GAME_SCREEN_X + GAME_SCREEN_SIZE_X + 10 + ((PLLIFE_SIZE_X + 10) * i), 230, lifeImage[1], true);
		}
		else
		{
			DrawGraph(GAME_SCREEN_X + GAME_SCREEN_SIZE_X + 10 + ((PLLIFE_SIZE_X + 10) * i), 230, lifeImage[0], true);
		}
	}
	DrawGraph(POWGARGE_POS_X - 3, 290 - 3, powGaugeFrameImage, false);
	DrawRectGraph(POWGARGE_POS_X, 290, 0, 0, player.power, 20,powGaugeImage, false, false);
	DrawGraph(GAME_SCREEN_X + GAME_SCREEN_SIZE_X, 330, powLevelImage, true);
	DrawGraph(GAME_SCREEN_X + GAME_SCREEN_SIZE_X + 250, 328, scoreNumImage[player.shotPowUp], true);
}