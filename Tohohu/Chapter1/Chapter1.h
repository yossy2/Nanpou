#pragma once

// externé¾
#ifdef CP1_DEF
#define CP1_EX
#else
#define CP1_EX extern
#endif

CP1_EX int chapter1Bgm;
CP1_EX int bossBgm;

bool ChapterInit1(void);		// 1Íú»
void Chapter1(void);			// 1Í
void DrawChapter1(void);		// 1Í`æ
void Chapter1Sound(void);		// »³ÝÄÞÄ¶

void StopBgm(void);		// ¹yð~ßé
