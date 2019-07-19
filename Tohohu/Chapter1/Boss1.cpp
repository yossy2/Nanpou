#define BOSS1_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Boss1.h"
#include "BossShot1.h"
#include <Player.h>

int bossImg1;		// 画像ID

// 初期化
bool BossInit1(void)
{
	bossImg1 = LoadGraph("image/boss1.png");
	if (bossImg1 == -1)
	{
		AST();
		return false;
	}

	boss1.pos = { 320.0f,300.0f };
	boss1.life = 100;
	boss1.drawFlag = false;

	return true;
}

// ﾎﾞｽの処理
void BossCtl1(void)
{

	// 出現
	if (flamCnt == BOSS_CNT)
	{
		boss1.drawFlag = true;
	}
}

// 描画
void BossDraw1(void)
{
	DrawRotaGraphF(boss1.pos.x,boss1.pos.y,1.0,0.0,bossImg1,true,false);
}