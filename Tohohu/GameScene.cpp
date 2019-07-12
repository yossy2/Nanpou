#define GAME_DEF
#include <time.h>
#include <DxLib.h>
#include <main.h>
#include <GameScene.h>
#include <Player.h>
#include <Chapter1/Chapter1.h>

// ｹﾞｰﾑｼｰﾝ初期化
bool GameInit(void)
{
	bool rtnFlag = true;

	srand((unsigned int)time(NULL));
	PlayerInit();
	ChapterInit1();

	// 画像読み込み
	systemImg = LoadGraph("image/system.png");
	if (systemImg == -1)
	{
		AST();
		rtnFlag = false;
	}

	return rtnFlag;
}

// ｹﾞｰﾑｼｰﾝ処理
void GameScene(void)
{
	PlayerCtl();
	chapterFunc();
}

// ｹﾞｰﾑｼｰﾝ描画
void GameDraw(void)
{
	// ｹﾞｰﾑ画面枠
	DrawGraph(0, 0, systemImg, true);
}