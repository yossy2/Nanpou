#define GAME_DEF
#include <time.h>
#include <DxLib.h>
#include <main.h>
#include <GameScene.h>
#include <Player.h>
#include <Chapter1/Chapter1.h>
#include "UiManeger.h"

// ¹Ş°Ñ¼°İ‰Šú‰»
bool GameInit(void)
{
	bool rtnFlag = true;

	srand((unsigned int)time(NULL));
	PlayerInit();
	ChapterInit1();
	UiInit();

	// ‰æ‘œ“Ç‚İ‚İ
	systemImg = LoadGraph("image/system.png");
	if (systemImg == -1)
	{
		AST();
		rtnFlag = false;
	}

	sceneFunc = GameScene;

	return rtnFlag;
}

// ¹Ş°Ñ¼°İˆ—
void GameScene(void)
{
	PlayerCtl();
	chapterFunc();
}

// ¹Ş°Ñ¼°İ•`‰æ
void GameDraw(void)
{
	// ¹Ş°Ñ‰æ–Ê˜g
	DrawGraph(0, 0, systemImg, true);
	DrawScore();
}
