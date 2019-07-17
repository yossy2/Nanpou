#define ENEMY1_B_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Enemy1_b.h"
#include <Player.h>

int enemyImg1B;			// 敵Aの画像ID

						// 初期化
bool EnemyInit1_B(void)
{
	for (int i = 0; i < ENEMY1_B_NUM; i++)
	{
		enemy1B[i].pos = { 50,50 };
		enemy1B[i].drawFlag = true;
	}

	// 画像読み込み
	enemyImg1B = LoadGraph("image/enemy1_B.png");
	if (enemyImg1B == -1)
	{
		AST();
		return false;
	}

	return true;
}

// 更新処理
void EnemyCtl1_B(void)
{
	
}

// 描画
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