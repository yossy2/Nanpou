#pragma once

// externéŒ¾
#ifdef CP1_DEF
#define CP1_EX
#else
#define CP1_EX extern
#endif

CP1_EX int chapter1Bgm;
CP1_EX int bossBgm;

bool ChapterInit1(void);		// 1Í‰Šú‰»
void Chapter1(void);			// 1Íˆ—
void DrawChapter1(void);		// 1Í•`‰æ
void Chapter1Sound(void);		// »³İÄŞÄ¶

void StopBgm(void);		// ‰¹Šy‚ğ~‚ß‚é
