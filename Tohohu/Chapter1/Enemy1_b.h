#pragma once

#define ENEMY1_B_SIZE_X 32		// G1_BÌ»²½ÞX
#define ENEMY1_B_SIZE_Y 32		// G1_BÌ»²½ÞY
#define ENEMY1_B_NUM	10		// G1_BÌzñÂ
#define ENEMY1_B_SPEED	4.0f	// G1_BÌÚ®Ê

// externé¾
#ifdef ENEMY1_B_DEF
#define ENEMY1_B_EX
#else
#define ENEMY1_B_EX extern
#endif

ENEMY1_B_EX Enemy enemy1B[ENEMY1_B_NUM];

bool EnemyInit1_B(void);				// ú»
void EnemyCtl1_B(void);					// XV
void DrawEnemy1_B(void);				// `æ

void ScanInitData1_B(void);				// úzuðÇÝÞ
