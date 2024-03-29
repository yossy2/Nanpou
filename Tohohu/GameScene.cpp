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

// ｹﾞｰﾑｼｰﾝ初期化
bool GameInit(void)
{
	bool rtnFlag = true;

	srand((unsigned int)time(NULL));
	ChapterInit1();
	UiInit();

	srand((unsigned int)time(NULL));
	// 画像読み込み
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

// ｹﾞｰﾑｼｰﾝ処理
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

// ｹﾞｰﾑｼｰﾝ描画
void GameDraw(void)
{
	// ｹﾞｰﾑ画面枠
	DrawGraph(GAME_SCREEN_X + (int)shake.x, GAME_SCREEN_Y + (int)shake.y, gameScreen, true);
	DrawGraph(0, 0, systemImg, true);
	DrawScore();
}
