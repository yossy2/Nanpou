#pragma once
/*
 * 1ÍGAÌeÖA
 */
#define ESHOT1_A_SIZE_X 16		// æ»²½ÞX
#define ESHOT1_A_SIZE_Y 16		// æ»²½ÞY
#define ESHOT1_A_NUM 250		// zñÌÂ
#define ESHOT1_A_DEF_SPEED 4.0f	// î{Ú®Ê
#define ESHOT1_A_MAX_SPEED 8.0f	// ÅåÚ®Ê
#define ESHOT1_A_CNT_MAX 10		// ¶³ÝÄÌÅål

 // externé¾
#ifdef ESHOT1_A_DEF
#define ESHOT1_A_EX
#else
#define ESHOT1_A_EX extern
#endif

ESHOT1_A_EX EShot eShot1A[ESHOT1_A_NUM];

bool EShotInit1_A(void);		// ú»
void EShotCtl1_A(void);			// XV
void DrawEShot1_A(void);		// `æ
