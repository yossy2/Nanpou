#pragma once

#define BOSS1_CNT 2500		// ÎŞ½‚ªoŒ»‚·‚éÌÚ°Ñ
#define BOSS1_ANIM_MAX 4	// ËŞ¯¸Ş½×²Ñ‚Ì±ÆÒ°¼®İ”
#define BOSS1_ANIM_SPEED 10	// ËŞ¯¸Ş½×²Ñ‚Ì±ÆÒ°¼®İ½Ëß°ÄŞ

#define BOSS1_SIZE_X 96		// ËŞ¯¸Ş½×²Ñ‚Ì»²½ŞX
#define BOSS1_SIZE_Y 96		// ËŞ¯¸Ş½×²Ñ‚Ì»²½ŞY

#define BOSS1_HIT_RAD 40	// ÎŞ½‚Ì“–‚½‚è”»’è‚Ì”¼Œa
#define BOSS1_LIFE_MAX 1000	// ÎŞ½‚ÌÅ‘å‘Ì—Í
#define BOSS1_ATK_PTN 4		// ÎŞ½‚ÌUŒ‚ÊßÀ°İ”

#define BOSS1_BLAST_ANIM_MAX 14	// ÎŞ½‚Ì”š”­±ÆÒ°¼®İ”

#define BOSS1_SHOT_OFSET 20.0f	// ’e‚ªo‚éˆÊ’u‚ğŒû‚ÌˆÊ’u‚É’²ß

// externéŒ¾
#ifdef BOSS1_DEF
#define BOSS1_EX
#else
#define BOSS1_EX extern
#endif

BOSS1_EX Boss boss1;			// 1ÍÎŞ½ËŞ¯¸Ş½×²Ñ
BOSS1_EX bool bossStartFlag1;	// ÎŞ½‚Ì“oêÌ×¸Ş

bool BossInit1(void);		// ‰Šú‰»
void BossCtl1(void);		// ÎŞ½‚Ìˆ—
void BossDraw1(void);		// •`‰æ

void BossAtk1_1(void);		// ˆÚ“®‚µ‚È‚ª‚ç’e‚ğ”­Ë
void BossAtk1_2(void);		// ’e‚ğ‰~ó‚É”­Ë
void BossAtk1_3(void);		// ‰ñ“]
void BossAtk1_4(void);		// ½×²Ñ‘åsi

void MoveCenter(void);		// ’†‰›‚ÉˆÚ“®
void ShotDelete(void);		// UŒ‚ÊßÀ°İ‚ª‚©‚í‚é‚Æ‚«’e‚ğˆê’UÁ‚·
