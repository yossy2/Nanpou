#pragma once

#define BOSS_CNT 2500		// ÎŞ½‚ªoŒ»‚·‚éÌÚ°Ñ

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
