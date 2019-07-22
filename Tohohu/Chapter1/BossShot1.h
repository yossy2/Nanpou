#pragma once

#define BSHOT1_NUM 1000		// ËŞ¯¸Ş½×²Ñ‚Ì’e”

#define BSHOT1_SIZE_X 16	// ËŞ¯¸Ş½×²Ñ‚Ì’e‚Ì»²½ŞX
#define BSHOT1_SIZE_Y 16	// ËŞ¯¸Ş½×²Ñ‚Ì’e‚Ì»²½ŞY


// externéŒ¾
#ifdef BSHOT1_DEF
#define BSHOT1_EX
#else
#define BSHOT1_EX extern
#endif

BSHOT1_EX EShot bShot1[BSHOT1_NUM];		// ËŞ¯¸Ş½×²Ñ‚Ì’e

bool BShotInit(void);		// ‰Šú‰»
void BShotCtl1(void);		// ÎŞ½1‚Ì’e‚Ìˆ—
void BShotDraw1(void);		// ÎŞ½1‚Ì’e‚Ì•`‰æ
