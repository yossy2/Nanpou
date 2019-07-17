#pragma once
#define ENEMY1_B_SIZE_X 32		// “G1_B‚Ì»²½ŞX
#define ENEMY1_B_SIZE_Y 32		// “G1_B‚Ì»²½ŞY
#define ENEMY1_B_NUM	50		// “G1_B‚Ì”z—ñŒÂ”
#define ENEMY1_B_SPEED	4.0f	// “G1_B‚ÌˆÚ“®—Ê

// externéŒ¾
#ifdef ENEMY1_B_DEF
#define ENEMY1_B_EX
#else
#define ENEMY1_B_EX extern
#endif

ENEMY1_B_EX Enemy enemy1B[ENEMY1_B_NUM];

bool EnemyInit1_B(void);				// ‰Šú‰»
void EnemyCtl1_B(void);					// XVˆ—
void DrawEnemy1_B(void);				// •`‰æ