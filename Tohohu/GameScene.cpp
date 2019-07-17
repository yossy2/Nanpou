#define GAME_DEF
#include <time.h>
#include <DxLib.h>
#include <main.h>
#include <GameScene.h>
#include <Player.h>
#include <Chapter1/Chapter1.h>

// ¹Ş°Ñ¼°İ‰Šú‰»
bool GameInit(void)
{
	bool rtnFlag = true;

	srand((unsigned int)time(NULL));
	PlayerInit();
	ChapterInit1();

	// ‰æ‘œ“Ç‚İ‚İ
	systemImg = LoadGraph("image/system.png");
	if (systemImg == -1)
	{
		AST();
		rtnFlag = false;
	}

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
}

// “–‚½‚è”»’è
bool CheckHitObj(Vector2 aPos, float arad, Vector2 bPos, float brad)
{
	bool hitFlag = false;
	float x_Len = aPos.x - bPos.x;
	float y_Len = aPos.y - bPos.y;
	float Renge = (x_Len * x_Len) + (y_Len * y_Len);			// “ñ“_‚Ì’†S‚Ì‹——£

	if (Renge < (arad + brad) * (arad + brad))
	{
		hitFlag = true;
	}

	return hitFlag;
}