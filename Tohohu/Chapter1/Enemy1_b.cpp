#define ENEMY1_B_DEF
#include <math.h>
#include <DxLib.h>
#include <main.h>
#include "Enemy1_b.h"
#include <Player.h>
#include <PlayerShot.h>

int enemyImg1B;				// 敵Aの画像ID
void(*enemyMove1B[ENEMY1_B_MOVE_PTN_MAX])(Enemy*) = { EnemyMove1_B_0,EnemyMove1_B_1 };	// 移動の種類

						// 初期化
bool EnemyInit1_B(void)
{
	ScanInitData1_B();

	for (int i = 0; i < ENEMY1_B_NUM; i++)
	{
		enemy1B[i].drawFlag = false;
		enemy1B[i].pos = enemy1B[i].initData.pos;
		enemy1B[i].moveAngle = enemy1B[i].initData.moveAngle;
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
	// 敵移動
	for (int i = 0; i < ENEMY1_B_NUM; i++)
	{
		if (enemy1B[i].drawFlag)
		{
			// 移動量決定
			enemy1B[i].move.x = cosf((float)(enemy1B[i].moveAngle) * PI / 180.0f) * (int)ENEMY1_B_SPEED;
			enemy1B[i].move.y = sinf((float)(enemy1B[i].moveAngle) * PI / 180.0f) * (int)ENEMY1_B_SPEED;

			(*enemyMove1B[enemy1B[i].initData.movePtn])(&enemy1B[i]);
			enemy1B[i].moveCount++;

			// 画面外判定
			if (isMoveOut(enemy1B[i].pos))
			{
				enemy1B[i].drawFlag = false;
			}

			// 弾との当たり判定
			for (int k = 0; k < PSHOT_NUM; k++)
			{
				if (pShot[k].flag)
				{
					if (CheckHitObj(pShot[k].pos, (float)PSHOT_SIZE_X / 2.0f, enemy1B[i].pos, (float)ENEMY1_B_SIZE_X / 2.0f))
					{
						pShot[k].flag = false;
						enemy1B[i].drawFlag = false;
						break;
					}
				}
			}
		}
	}

	// 敵出現
	for (int i = 0; i < ENEMY1_B_NUM; i++)
	{
		if (!enemy1B[i].drawFlag)
		{
			if (enemy1B[i].initData.count == flamCnt)
			{
				enemy1B[i].drawFlag = true;
			}
		}
	}
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

// 初期配置を読み込む
void ScanInitData1_B(void)
{
	int file;			// ﾌｧｲﾙﾊﾝﾄﾞﾙ
	char string[256];		// 最初の1行読み飛ばす用

	// ファイル読み込み
	file = FileRead_open("出現パターン/Enemy1_b.csv");
	if (file == 0)
	{
		AST();
		return;
	}

	// 1行読み飛ばし
	FileRead_gets(string, 256, file);

	// 初期配置設定
	for (int i = 0; i < ENEMY1_B_NUM; i++)
	{
		FileRead_scanf(file, "%d,%d,%f,%f,%d",
			&enemy1B[i].initData.count, &enemy1B[i].initData.movePtn,
			&enemy1B[i].initData.pos.x, &enemy1B[i].initData.pos.y, &enemy1B[i].initData.moveAngle);
	}
	
	FileRead_close(file);
}

// 移動0
void EnemyMove1_B_0(Enemy *enemy)
{
	enemy->pos.x += enemy->move.x;
	enemy->pos.y += enemy->move.y;

	if (enemy->moveCount % 2 == 0)
	{
		enemy->moveAngle++;
	}
}

// 移動1
void EnemyMove1_B_1(Enemy *enemy)
{
	enemy->pos.x += enemy->move.x;
	enemy->pos.y += enemy->move.y;

	if (enemy->moveCount % 2 == 0)
	{
		enemy->moveAngle--;
	}
}