#pragma once

#define ENEMY1_A_SIZE_X 32		// “G1_A‚Ì»²½ŞX
#define ENEMY1_A_SIZE_Y 32		// “G1_A‚Ì»²½ŞY
#define ENEMY1_A_NUM	50		// “G1_A‚Ì”z—ñŒÂ”
#define ENEMY1_A_SPEED	4.0f	// “G1_A‚ÌˆÚ“®—Ê

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
