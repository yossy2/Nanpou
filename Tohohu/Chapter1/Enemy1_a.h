#pragma once

#define ENEMY1_A_SIZE_X 32		// “G1_A‚Ì»²½ŞX
#define ENEMY1_A_SIZE_Y 32		// “G1_A‚Ì»²½ŞY
#define ENEMY1_A_NUM	70		// “G1_A‚Ì”z—ñŒÂ”
#define ENEMY1_A_SPEED	4.0f	// “G1_A‚ÌˆÚ“®—Ê

#define ENEMY1_A_MOVE_PTN_MAX 9	// “G1_A‚ÌˆÚ“®ÊßÀ°İ”
#define ENEMY1_A_ANIM_MAX 4		// “G1_A‚Ì±ÆÒ°¼®İ”

#define ENEMY1_A_INV 20			// “G1_A‚ÌoŒ»ŠÔŠu

// externéŒ¾
#ifdef ENEMY1_A_DEF
#define ENEMY1_A_EX
#else
#define ENEMY1_A_EX extern
#endif

ENEMY1_A_EX Enemy enemy1A[ENEMY1_A_NUM];

bool EnemyInit1_A(void);				// ‰Šú‰»
void EnemyCtl1_A(void);					// XVˆ—
void DrawEnemy1_A(void);				// •`‰æ
void EnemyAttack1_A(Vector2 pos);		// UŒ‚

void ScanInitData1_A(void);				// ‰Šú”z’u‚ğ“Ç‚İ‚Ş		

void EnemyMove1_A_0(Enemy * enemy);		// ˆÚ“®ÊßÀ°İ0
void EnemyMove1_A_1(Enemy * enemy);		// ˆÚ“®ÊßÀ°İ1
void EnemyMove1_A_2(Enemy * enemy);		// ˆÚ“®ÊßÀ°İ2
void EnemyMove1_A_3(Enemy * enemy);		// ˆÚ“®ÊßÀ°İ3
void EnemyMove1_A_4(Enemy * enemy);		// ˆÚ“®ÊßÀ°İ4
void EnemyMove1_A_5(Enemy * enemy);		// ˆÚ“®ÊßÀ°İ5
void EnemyMove1_A_6(Enemy * enemy);		// ˆÚ“®ÊßÀ°İ6
void EnemyMove1_A_7(Enemy * enemy);		// ˆÚ“®ÊßÀ°İ7
void EnemyMove1_A_8(Enemy * enemy);		// ˆÚ“®ÊßÀ°İ8

