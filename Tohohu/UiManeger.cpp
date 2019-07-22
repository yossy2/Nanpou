#include <DxLib.h>
#include "main.h"
#include "GameScene.h"
#include "UiManeger.h"
#include "Player.h"

// =================変数定義
int highScoreImage;			// ﾊｲｽｺｱ用
int scoreImage;				// ｽｺｱ用
int scoreNumImage[SCORE_NUM];			// ｽｺｱ数字用
int playerLife[PLAYER_LIFE_STATS];

// 初期化
void UiInit(void)
{
	// ===========ｲﾒｰｼﾞ登録
	if ((highScoreImage = LoadGraph("image/highscore.png")) == -1)
	{
		AST();
		return;
	}
	if ((scoreImage = LoadGraph("image/score.png")) == -1)
	{
		AST();
		return;
	}
	for (int i = 0; i < SCORE_NUM; i++)
	{
		if (LoadDivGraph("image/scorenum.png", SCORE_NUM, SCORE_NUM, 1, SCORE_NUM_SIZE_X, SCORE_NUM_SIZE_Y, scoreNumImage) == -1)
		{
			AST();
			return;
		}
	}
	for (int i = 0; i < PLAYER_LIFE_STATS; i++)
	{
		if (LoadDivGraph("image/playerlife.png", PLAYER_LIFE_STATS, PLAYER_LIFE_STATS, 1, PLLIFE_SIZE_X, PLLIFE_SIZE_Y, playerLife) == -1)
		{
			AST();
			return;
		}
	}
}

// ｽｺｱ計算
void ScoreUpdate(void)
{

}

// 描画
void DrawScore(void)
{
	DrawGraph(GAME_SCREEN_X + GAME_SCREEN_SIZE_X, 30, highScoreImage, true);
	for (int i = 0; i < SCORE_NUM; i++)
	{
		DrawGraph(SCREEN_SIZE_X - SCORE_NUM_SIZE_X - (SCORE_NUM_SIZE_X * i), 70, scoreNumImage[i], true);
	}
	DrawGraph(GAME_SCREEN_X + GAME_SCREEN_SIZE_X, 110, scoreImage, true);
	for (int i = 0; i < SCORE_NUM; i++)
	{
		DrawGraph(SCREEN_SIZE_X - SCORE_NUM_SIZE_X - (SCORE_NUM_SIZE_X * i), 150, scoreNumImage[i], true);
	}
	for (int i = 0; i < PLAYER_DEF_LIFE; i++)
	{
		DrawGraph(GAME_SCREEN_X + GAME_SCREEN_SIZE_X + 10 + ((PLLIFE_SIZE_X + 10) * i), 230, playerLife[1], true);
	}
}