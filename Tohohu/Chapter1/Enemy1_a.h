#pragma once

#define ENEMY1_A_SIZE_X 32		// 敵1_AのｻｲｽﾞX
#define ENEMY1_A_SIZE_Y 32		// 敵1_AのｻｲｽﾞY
#define ENEMY1_A_NUM	70		// 敵1_Aの配列個数
#define ENEMY1_A_SPEED	4.0f	// 敵1_Aの移動量

#define ENEMY1_A_MOVE_PTN_MAX 9	// 敵1_Aの移動ﾊﾟﾀｰﾝ数
#define ENEMY1_A_ANIM_MAX 4		// 敵1_Aのｱﾆﾒｰｼｮﾝ数

#define ENEMY1_A_INV 20			// 敵1_Aの出現間隔

// extern宣言
#ifdef ENEMY1_A_DEF
#define ENEMY1_A_EX
#else
#define ENEMY1_A_EX extern
#endif

ENEMY1_A_EX Enemy enemy1A[ENEMY1_A_NUM];

bool EnemyInit1_A(void);				// 初期化
void EnemyCtl1_A(void);					// 更新処理
void DrawEnemy1_A(void);				// 描画
void EnemyAttack1_A(Vector2 pos);		// 攻撃

void ScanInitData1_A(void);				// 初期配置を読み込む		

void EnemyMove1_A_0(Enemy * enemy);		// 移動ﾊﾟﾀｰﾝ0
void EnemyMove1_A_1(Enemy * enemy);		// 移動ﾊﾟﾀｰﾝ1
void EnemyMove1_A_2(Enemy * enemy);		// 移動ﾊﾟﾀｰﾝ2
void EnemyMove1_A_3(Enemy * enemy);		// 移動ﾊﾟﾀｰﾝ3
void EnemyMove1_A_4(Enemy * enemy);		// 移動ﾊﾟﾀｰﾝ4
void EnemyMove1_A_5(Enemy * enemy);		// 移動ﾊﾟﾀｰﾝ5
void EnemyMove1_A_6(Enemy * enemy);		// 移動ﾊﾟﾀｰﾝ6
void EnemyMove1_A_7(Enemy * enemy);		// 移動ﾊﾟﾀｰﾝ7
void EnemyMove1_A_8(Enemy * enemy);		// 移動ﾊﾟﾀｰﾝ8

