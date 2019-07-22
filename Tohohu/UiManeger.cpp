#include <DxLib.h>
#include "main.h"
#include "GameScene.h"
#include "UiManeger.h"
#include "Player.h"

// =================ïœêîíËã`
int highScoreImage;			//  ≤Ω∫±óp
int scoreImage;				// Ω∫±óp
int scoreNumImage[SCORE_NUM];			// Ω∫±êîéöóp
int lifeImage[PLAYER_LIFE_STATS];

// èâä˙âª
void UiInit(void)
{
	// ===========≤“∞ºﬁìoò^
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
		if (LoadDivGraph("image/playerlife.png", PLAYER_LIFE_STATS, PLAYER_LIFE_STATS, 1, PLLIFE_SIZE_X, PLLIFE_SIZE_Y, lifeImage) == -1)
		{
			AST();
			return;
		}
	}
}

// Ω∫±åvéZ
void ScoreUpdate(void)
{

}

// ï`âÊ
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
		if (player.life >= i + 1)
		{
			DrawGraph(GAME_SCREEN_X + GAME_SCREEN_SIZE_X + 10 + ((PLLIFE_SIZE_X + 10) * i), 230, lifeImage[1], true);
		}
		else
		{
			DrawGraph(GAME_SCREEN_X + GAME_SCREEN_SIZE_X + 10 + ((PLLIFE_SIZE_X + 10) * i), 230, lifeImage[0], true);
		}
	}
}