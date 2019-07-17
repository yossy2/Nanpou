#define ENEMY1_B_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Enemy1_b.h"
#include <Player.h>

int enemyImg1B;			// “GA‚Ì‰æ‘œID

						// ‰Šú‰»
bool EnemyInit1_B(void)
{
	for (int i = 0; i < ENEMY1_B_NUM; i++)
	{
		enemy1B[i].pos = { 50,50 };
		enemy1B[i].drawFlag = true;
	}

	// ‰æ‘œ“Ç‚İ‚İ
	enemyImg1B = LoadGraph("image/enemy1_B.png");
	if (enemyImg1B == -1)
	{
		AST();
		return false;
	}

	return true;
}

// XVˆ—
void EnemyCtl1_B(void)
{
	
}

// •`‰æ
void DrawEnemy1_B(void)
{
	for (int i = 0; i < ENEMY1_B_NUM; i++)
	{
		if (enemy1B[i].drawFlag)
		{
			DrawRotaGraphF(enemy1B[i].pos.x + GAME_SCREEN_X, enemy1B[i].pos.y + GAME_SCREEN_Y,
				1.0, 0.0, enemyImg1B, true, false);
		}
	}
}