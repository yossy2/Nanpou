#pragma once

#define ENEMY1_B_SIZE_X 32		// 敵1_BのｻｲｽﾞX
#define ENEMY1_B_SIZE_Y 32		// 敵1_BのｻｲｽﾞY
#define ENEMY1_B_NUM	40		// 敵1_Bの出現数
#define ENEMY1_B_SPEED	4.0f	// 敵1_Bの移動量
#define ENEMY1_B_MAX 500

#define ENEMY1_B_ANIM_MAX 4		// 敵1_Bのｱﾆﾒｰｼｮﾝ数

#define ENEMY1_B_MOVE_PTN_MAX 4	// 敵1_Bの移動ﾊﾟﾀｰﾝ数

// extern宣言
#ifdef ENEMY1_B_DEF
#define ENEMY1_B_EX
#else
#define ENEMY1_B_EX extern
#endif

ENEMY1_B_EX Enemy enemy1B[ENEMY1_B_MAX];

bool EnemyInit1_B(void);				// 初期化
void EnemyCtl1_B(void);					// 更新処理
void DrawEnemy1_B(void);				// 描画

void ScanInitData1_B(void);				// 初期配置を読み込む

void EnemyMove1_B_0(Enemy* enemy);		// 移動ﾊﾟﾀｰﾝ0
void EnemyMove1_B_1(Enemy* enemy);		// 移動ﾊﾟﾀｰﾝ1
void EnemyMove1_B_2(Enemy * enemy);		// ﾎﾞｽ専用移動
void EnemyMove1_B_3(Enemy * enemy);		// ﾎﾞｽ登場
