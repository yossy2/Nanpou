#define ENEMY1_A_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Enemy1_a.h"
#include "EnemyShot1_a.h"
#include <Player.h>

int enemyImg1A;			// 敵Aの画像ID
void(*enemyMove1A[ENEMY1_A_MOVE_PTN_MAX])(Enemy*) = {EnemyMove1_A_0};	// 移動の種類

// 初期化
bool EnemyInit1_A(void)
{
	ScanInitData1_A();

	for (int i = 0; i < ENEMY1_A_NUM; i++)
	{
		enemy1A[i].drawFlag = false;
	}

	// 画像読み込み
	enemyImg1A = LoadGraph("image/enemy1_A.png");
	if (enemyImg1A == -1)
	{
		AST();
		return false;
	}

	return true;
}

// 更新処理
void EnemyCtl1_A(void)
{
	for (int i = 0; i < ENEMY1_A_NUM; i++)
	{
		if (enemy1A[i].drawFlag && !enemy1A[i].atkFlag)
		{
			enemy1A[i].pos.y += ENEMY1_A_SPEED;
			

			if (enemy1A[i].pos.y >= 200)
			{
				enemy1A[i].atkFlag = true;
				EnemyAttack1_A(enemy1A[i].pos);
				enemy1A[i].move.x = ENEMY1_A_SPEED * (1 - 2 * (rand() % 2));
			}
		}
		else if (enemy1A[i].atkFlag && ++enemy1A[i].moveCount > 60)
		{
			enemy1A[i].pos.x += enemy1A[i].move.x;
		}

		// 画面外判定
		if (isMoveOut(enemy1A[i].pos))
		{
			enemy1A[i].drawFlag = false;
		}

	}

	if (flamCnt % ENEMY1_A_INV == 0 && (flamCnt / ENEMY1_A_INV) < ENEMY1_A_NUM)
	{
		enemy1A[flamCnt / ENEMY1_A_INV].drawFlag = true;
		enemy1A[flamCnt / ENEMY1_A_INV].pos.x = (float)((rand() % (GAME_SCREEN_SIZE_X - ENEMY1_A_SIZE_X)) + ENEMY1_A_SIZE_X / 2);
		enemy1A[flamCnt / ENEMY1_A_INV].pos.y = -ENEMY1_A_SIZE_Y;
	}
	for (int i = 0; i < ENEMY1_A_NUM; i++)
	{
		if (enemy1A[i].drawFlag && player.flag)
		{
			if (CheckHitObj(enemy1A[i].pos, ENEMY1_A_SIZE_X / 2, player.pos, PLAYER_HIT_RAD))
			{
				player.flag = false;
			}
		}
	}
}

// 描画
void DrawEnemy1_A(void)
{
	for (int i = 0; i < ENEMY1_A_NUM; i++)
	{
		if (enemy1A[i].drawFlag)
		{
			DrawRotaGraphF(enemy1A[i].pos.x + GAME_SCREEN_X, enemy1A[i].pos.y + GAME_SCREEN_Y,
				1.0, 0.0, enemyImg1A, true, false);
		}
	}
}

// 攻撃
void EnemyAttack1_A(Vector2 pos)
{
	int count = 0;

	for (int i = 0; i < ESHOT1_A_NUM; i++)
	{
		if (!eShot1A[i].flag)
		{
			eShot1A[i].flag = true;
			eShot1A[i].pos = pos;
			eShot1A[i].moveAngle = (count - 2) * PI / 8.0f + atan2f(player.pos.y - pos.y, player.pos.x - pos.x);
			
			count++;
			if (count >= 5)
			{
				return;
			}
		}
	}
}

// 初期配置を読み込む
void ScanInitData1_A(void)
{
	int file;			// ﾌｧｲﾙﾊﾝﾄﾞﾙ
	char string[256];	// 最初の1行読み飛ばす用

	// ファイル読み込み
	file = FileRead_open("出現パターン/Enemy1_a.csv");
	if (file == 0)
	{
		AST();
		return;
	}

	// 1行読み飛ばし
	FileRead_gets(string, 256, file);

	// 初期配置設定
	for (int i = 0; i < ENEMY1_A_NUM; i++)
	{
		FileRead_scanf(file, "%d,%d,%f,%f,%d",
			&enemy1A[i].initData.count, &enemy1A[i].initData.movePtn,
			&enemy1A[i].initData.pos.x, &enemy1A[i].initData.pos.y, &enemy1A[i].initData.moveAngle);

		if (enemy1A[i].initData.movePtn >= ENEMY1_A_MOVE_PTN_MAX)
		{
			AST();
			enemy1A[i].initData.movePtn = 0;
		}
	}

	FileRead_close(file);
}

// 移動0
void EnemyMove1_A_0(Enemy *enemy)
{
	enemy->pos.x += enemy->move.x;
	enemy->pos.y += enemy->move.y;
	enemy->moveCount++;

	if (enemy->moveCount % 2 == 0)
	{
		enemy->moveAngle++;
	}
}