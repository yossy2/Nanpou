#define GAME_DEF
#include <time.h>
#include <DxLib.h>
#include <main.h>
#include <GameScene.h>
#include <Player.h>
#include <PlayerShot.h>
#include <Chapter1/Chapter1.h>
#include "UiManeger.h"
#include "Item.h"
#include "ResultScene.h"

// πﬁ∞—º∞›èâä˙âª
bool GameInit(void)
{
	bool rtnFlag = true;

	srand((unsigned int)time(NULL));
	ChapterInit1();
	UiInit();

	srand((unsigned int)time(NULL));
	// âÊëúì«Ç›çûÇ›
	systemImg = LoadGraph("image/system.png");
	if (systemImg == -1)
	{
		AST();
		rtnFlag = false;
	}

	if (LoadDivGraph("image/blast.png", BLAST_DIV_NUM_X * BLAST_DIV_NUM_Y, BLAST_DIV_NUM_X, BLAST_DIV_NUM_Y,
		BLAST_SIZE_X, BLAST_SIZE_Y, blastImg) == -1)
	{
		AST();
		rtnFlag = false;
	}
	gameScreen = MakeScreen(GAME_SCREEN_SIZE_X, GAME_SCREEN_SIZE_Y, true);
	sceneFunc = GameScene;

	return rtnFlag;
}

// πﬁ∞—º∞›èàóù
void GameScene(void)
{
	ItemCtl();
	PlayerCtl();
	PlayerShotMove();
	chapterFunc();
	if (player.life <= 0)
	{
		ResultInit(false);
	}
}

// πﬁ∞—º∞›ï`âÊ
void GameDraw(void)
{
	// πﬁ∞—âÊñ òg
	DrawGraph(GAME_SCREEN_X + shake.x, GAME_SCREEN_Y + shake.y, gameScreen, true);
	DrawGraph(0, 0, systemImg, true);
	DrawScore();
}
