#include "DxLib.h"
#include "main.h"
#include "GameScene.h"
#include "ResultScene.h"
#include "TitleScene.h"

int gameClearImage;		// ｹﾞｰﾑｸﾘｱのﾛｺﾞ
int gameOverImage;			// ｹﾞｰﾑｵｰﾊﾞｰのﾛｺﾞ

bool CheckClear;			// ｹﾞｰﾑｸﾘｱかどうかをｹﾞｰﾑｼｰﾝから受け取る

// 初期化
void ResultInit(bool flag)
{
	// ================ｲﾒｰｼﾞ登録
	// ｹﾞｰﾑｸﾘｱﾛｺﾞ
	if ((gameClearImage = LoadGraph("image/gameclear.png")) == -1)
	{
		AST();
		return;
	}
	// ｹﾞｰﾑｵｰﾊﾞｰﾛｺﾞ
	if ((gameOverImage = LoadGraph("image/gameover.png")) == -1)
	{
		AST();
		return;
	}

	CheckClear = flag;
	sceneFunc = ResultScene;
}

// 処理
void ResultScene(void)
{
	ResultSceDraw(CheckClear);
	if (keyFram[KEY_INPUT_Z] == 1)
	{
		TitleInit();
	}
}

// 描画
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