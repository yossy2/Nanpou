#define BOSS1_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Boss1.h"
#include "BossShot1.h"
#include <Player.h>

int bossImg1;		// ‰æ‘œID
Boss boss1;			// 1ÍÎŞ½ËŞ¯¸Ş½×²Ñ

// ‰Šú‰»
bool BossInit1(void)
{
	bossImg1 = LoadGraph("image/boss1.png");
	if (bossImg1 == -1)
	{
		AST();
		return false;
	}

	return true;
}