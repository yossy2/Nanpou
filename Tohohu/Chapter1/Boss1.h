#pragma once

#define BOSS1_CNT 2500		// ÎŞ½‚ªoŒ»‚·‚éÌÚ°Ñ
#define BOSS1_ANIM_MAX 4	// ËŞ¯¸Ş½×²Ñ‚Ì±ÆÒ°¼®İ”

#define BOSS1_SIZE_X 96		// ËŞ¯¸Ş½×²Ñ‚Ì»²½ŞX
#define BOSS1_SIZE_Y 96		// ËŞ¯¸Ş½×²Ñ‚Ì»²½ŞY

// externéŒ¾
#ifdef BOSS1_DEF
#define BOSS1_EX
#else
#define BOSS1_EX extern
#endif

BOSS1_EX Boss boss1;			// 1ÍÎŞ½ËŞ¯¸Ş½×²Ñ

bool BossInit1(void);		// ‰Šú‰»
void BossCtl1(void);		// ÎŞ½‚Ìˆ—
void BossDraw1(void);		// •`‰æ

void BossAtk1_1(void);		// UŒ‚ÊßÀ°İ‚»‚Ì1A‰ñ“]
