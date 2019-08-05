#pragma once

#define ENEMY1_B_SIZE_X 32		// “G1_B‚Ì»²½ŞX
#define ENEMY1_B_SIZE_Y 32		// “G1_B‚Ì»²½ŞY
#define ENEMY1_B_NUM	40		// “G1_B‚ÌoŒ»”
#define ENEMY1_B_SPEED	4.0f	// “G1_B‚ÌˆÚ“®—Ê
#define ENEMY1_B_MAX 500

#define ENEMY1_B_ANIM_MAX 4		// “G1_B‚Ì±ÆÒ°¼®İ”

#define ENEMY1_B_MOVE_PTN_MAX 4	// “G1_B‚ÌˆÚ“®ÊßÀ°İ”

// externéŒ¾
#ifdef ENEMY1_B_DEF
#define ENEMY1_B_EX
#else
#define ENEMY1_B_EX extern
#endif

ENEMY1_B_EX Enemy enemy1B[ENEMY1_B_MAX];

bool EnemyInit1_B(void);				// ‰Šú‰»
void EnemyCtl1_B(void);					// XVˆ—
void DrawEnemy1_B(void);				// •`‰æ

void ScanInitData1_B(void);				// ‰Šú”z’u‚ğ“Ç‚İ‚Ş

void EnemyMove1_B_0(Enemy* enemy);		// ˆÚ“®ÊßÀ°İ0
void EnemyMove1_B_1(Enemy* enemy);		// ˆÚ“®ÊßÀ°İ1
void EnemyMove1_B_2(Enemy * enemy);		// ÎŞ½ê—pˆÚ“®
void EnemyMove1_B_3(Enemy * enemy);		// ÎŞ½“oê
